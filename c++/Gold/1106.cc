//
// Created by jaehy on 25. 7. 18.
//

#include <iostream>

int main() {
    int c, n;
    std::cin >> c >> n;
    std::pair<int, int> arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i].first >> arr[i].second;
    }
    int dp[c + 100];
    int ans = 100'001;
    dp[0] = 0;
    std::fill(dp + 1, dp + c + 100, 100'001);
    for (int i = 1; i < c + 100; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j].second > i) continue;
            dp[i] = std::min(dp[i], dp[i - arr[j].second] + arr[j].first);
        }
        if (i >= c) {
            ans = std::min(ans, dp[i]);
        }
    }

    std::cout << ans << '\n';
}