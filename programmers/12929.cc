//
// Created by jaehy on 25. 7. 25.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Optimal
int solution(int n) {
    int dp[15] = {1,};
    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k < i; ++k) {
            dp[i] += dp[k] * dp[i - 1 - k];
        }
    }
    return dp[n];
}
 */
void partitions(int n, int max_num, vector<int>& current, vector<vector<int>>& ret) {
    if (n == 0) {
        ret.push_back(current);
        return;
    }
    for (int i = min(max_num, n); i > 0; --i) {
        current.push_back(i);
        partitions(n - i, i, current, ret);
        current.pop_back();
    }
}

int solution(int n) {
    int dp[15] = {};
    int origin[15] = {};
    origin[1] = 1;
    dp[1] = 1;
    vector<vector<int>> result;
    vector<int> temp;
    for (int i = 2; i <= n; i++) {
        origin[i] = dp[i - 1];
        partitions(i, i, temp, result);
        for (auto& p: result) {
            sort(p.begin(), p.end());
            do {
                int mul = 1;
                for (int x : p) mul *= origin[x];
                dp[i] += mul;
            } while (next_permutation(p.begin(), p.end()));
        }
        result.clear();
        temp.clear();
    }
    return dp[n];
}
