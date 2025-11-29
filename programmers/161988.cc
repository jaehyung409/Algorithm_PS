#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    long long dp[500001][2] = {}; // 0 (+), 1 (-)
    const int size = sequence.size();
    for (int i = 0; i < size; ++i) {
        long long s = static_cast<long long>(sequence[i]);
        dp[i + 1][0] = max(dp[i][1] + s, s);
        dp[i + 1][1] = max(dp[i][0] - s, -s);
        answer = max({answer, dp[i + 1][0], dp[i + 1][1]});
    }
    return answer;
}