//
// Created by jaehy on 25. 8. 8..
//

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int dp[100001]= {1,};
    for (auto m : money) {
        for (int i = m; i <= n; ++i) {
            dp[i] += dp[i-m];
            dp[i] %= 1'000'000'007;
        }
    }
    return dp[n];
}