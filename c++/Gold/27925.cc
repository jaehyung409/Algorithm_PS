//
// Created by jaehy on 25. 2. 19.
//
#include <iostream>
#include <ranges>
#include <algorithm>

int min_click(const int init, const int target) {
    const int abs_dist = std::abs(init - target);
    return std::min(abs_dist, 10 - abs_dist);
}

int main(){
    int foods, temp;
    std::cin >> foods;
    int dp[foods][1000];
    for (auto& row : dp) { std::ranges::fill(row, 50000); }
    int digit[3] = {100, 10, 1};
    std::cin >> temp;
    for (int i : digit) {
        dp[0][temp * i] = min_click(temp, 0);
    }
    for (int i = 0; i < foods - 1; ++i) {
        std::cin >> temp;
        for (int prev_state = 0; prev_state < 1000; ++prev_state) {
            if (dp[i][prev_state] == 50000) continue;
            for (int j : digit) {
                int new_state = prev_state;
                int induction_temp = (prev_state / j) % 10;
                int click_count = min_click(induction_temp, temp);
                new_state = prev_state - induction_temp * j + temp * j;
                dp[i + 1][new_state] = std::min(dp[i + 1][new_state], dp[i][prev_state] + click_count);
            }
        }
    }
    std::cout << *std::ranges::min_element(dp[foods-1]);
}