#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> dp(301);
const int mod = 10000019;

int ncr_dp[301][301] = {};

void init_ncr() {
    for (int n = 0; n <= 300; ++n) {
        ncr_dp[n][0] = ncr_dp[n][n] = 1;
        for (int r = 1; r < n; ++r) {
            ncr_dp[n][r] = (ncr_dp[n-1][r-1] + ncr_dp[n-1][r]) % mod;
        }
    }
}

void update(vector<int>& next, int idx, int n, int val, int row_size) {
    // idx (odd), row_size - idx (even)
    const int max_to_odd = min(n, idx);
    const int min_to_odd = max(0, n - (row_size - idx));

    for (int to_odd = min_to_odd; to_odd <= max_to_odd; ++to_odd) {
        int new_odd = idx + n - 2 * to_odd;
        long long comb = 1LL * ncr_dp[idx][to_odd] * ncr_dp[row_size - idx][n - to_odd] % mod;
        long long add = (comb * val) % mod;
        next[new_odd] = (next[new_odd] + add) % mod;
    }
}

int solution(vector<vector<int>> a) {
    init_ncr();
    const int row_size = a.size();
    const int col_size = a.front().size();
    vector<int> count(col_size);
    for (auto vec : a) {
        for (int i = 0; i < col_size; ++i) count[i] += vec[i];
    }
    sort(count.begin(), count.end(), greater<int>());
    dp[count[0]] = ncr_dp[row_size][count[0]];
    for (int i = 1; i < col_size; ++i) {
        if (count[i] == 0) break;
        vector<int> next(301);
        for (int j = 0; j <= row_size; ++j) {
            if (dp [j] == 0) continue;
            update(next, j, count[i], dp[j], row_size);
        }
        dp.swap(next);
    }
    return dp.front();
}