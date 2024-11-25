//
// Created by jaehy on 24. 11. 25.
//
#include <iostream>
#include <algorithm>

int main(){
    int N, i, j, ans = 1000001;
    std::cin >> N;
    int fir_red, fir_green, fir_blue;
    int house_cost[1000][3];
    int house_cost_dp[1000][3];
    std::cin >> fir_red >> fir_green >> fir_blue;
    for (i = 1; i < N; i++)
        std::cin >> house_cost[i][0] >> house_cost[i][1]
        >> house_cost[i][2];

    for (i = 0; i < 3; i++){
        house_cost_dp[0][0] = (i == 0) ? fir_red : 1001;
        house_cost_dp[0][1] = (i == 1) ? fir_green : 1001;
        house_cost_dp[0][2] = (i == 2) ? fir_blue : 1001;
        for (j = 1; j < N; j++){
            house_cost_dp[j][0] = house_cost[j][0] +
                                  std::min(house_cost_dp[j-1][1], house_cost_dp[j-1][2]);
            house_cost_dp[j][1] = house_cost[j][1] +
                                  std::min(house_cost_dp[j-1][0], house_cost_dp[j-1][2]);
            house_cost_dp[j][2] = house_cost[j][2] +
                                  std::min(house_cost_dp[j-1][0], house_cost_dp[j-1][1]);
        }
        if (i == 0) ans = std::min({ans, house_cost_dp[j-1][1], house_cost_dp[j-1][2]});
        else if (i == 1) ans = std::min({ans, house_cost_dp[j-1][0], house_cost_dp[j-1][2]});
        else ans = std::min({ans, house_cost_dp[j-1][0], house_cost_dp[j-1][1]});
    }
    std::cout << ans <<'\n';
    return 0;
}