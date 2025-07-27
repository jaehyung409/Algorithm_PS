//
// Created by jaehy on 25. 7. 26.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int dp[501][501] = {};
    int height = 1;
    for (auto vec: triangle) {
        dp[height][1] = dp[height - 1][1] + vec[0];
        for (int i = 1; i < height - 1; ++i) {
            dp[height][i + 1] = max(dp[height - 1][i], dp[height - 1][i + 1]) + vec[i];
        }
        dp[height][height] = dp[height - 1][height - 1] + vec[height - 1];
        height++;
    }
    return *max_element(dp[height - 1], dp[height - 1] + height - 1);
}