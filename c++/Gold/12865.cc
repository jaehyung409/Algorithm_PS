//
// Created by jaehy on 24. 11. 4.
//
#include <iostream>
#include <queue>

int main(){
    int N, K;
    int dp[100001][101];
    std::cin >> N >> K;
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> weights_value;
    int i, j, weights, value;
    for (i = 0; i < N; i++){
        std::cin >> weights >> value;
        weights_value.emplace(weights, value);
    }
    for (j = 1; j <= K; j++) dp[j][0] = 0;
    for (i = 1; i <= N; i++){
        weights = weights_value.top().first;
        value = weights_value.top().second;
        weights_value.pop();
        for (j = 1; j <= K; j++){
            if (j < weights){
                dp[j][i] = dp[j][i-1];
                continue;
            }
            dp[j][i] = std::max(dp[j-weights][i-1] + value,dp[j][i-1]);
        }
    }
    std::cout << dp[K][N] << '\n';
    return 0;
}