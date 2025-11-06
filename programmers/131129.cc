#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[361][2] = {};


vector<int> solution(int target) {
    vector<int> base, others, answer;
    base.reserve(21);
    others.reserve(30);
    for (int i = 1; i <= 60; ++i) {
        if (i <= 20) base.push_back(i);
        else if (i % 2 == 0 && i <= 40) others.push_back(i);
        else if (i % 3 == 0) others.push_back(i);
        else if (i == 50) base.push_back(i);
    }
    for (int i = 1; i <= 20; ++i) {
        dp[i][0] = 1;
        dp[i << 1][0] = 1;
        dp[i * 3][0] = 1;
        dp[i][1] = 1;
    }
    dp[50][0] = dp[50][1] = 1;
    for (int i = 1; i <= 360; ++i) {
        if (dp[i][0] == 0) {
            int minimum = 100000;
            int flag = 0;
            for (int n : base) {
                if (i <= n) break;
                int prev0 = dp[i - n][0] + 1;
                int prev1 = dp[i - n][1] + 1; // base
                if (prev0 < minimum) {
                    minimum = prev0;
                    flag = prev1;
                } else if (prev0 == minimum) {
                    flag = max(flag, prev1);
                }
            }
            for (int n : others) {
                if (i <= n) break;
                int prev0 = dp[i - n][0] + 1;
                int prev1 = dp[i - n][1];
                if (prev0 < minimum) {
                    minimum = prev0;
                    flag = prev1;
                } else if (prev0 == minimum) {
                    flag = max(flag, prev1);
                }
            }
            dp[i][0] = minimum;
            dp[i][1] = flag;
        }
    }
    int addition = 0;
    if (target >= 360) {
        addition = (target - 360) / 60 + 1;
        target -= 60 * addition;
    }
    answer.push_back(dp[target][0] + addition);
    answer.push_back(dp[target][1]);
    return answer;
}