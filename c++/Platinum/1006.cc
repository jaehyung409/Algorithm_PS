//
// Created by jaehy on 25. 7. 14.
//
// Reference : https://casterian.net/ps/boj1006/

#include <iostream>

void make_dp(int dp[][3], int circle[][2], const int start, const int end, int m) {
    for (int i = start; i < end; i++) {
        dp[i + 1][2] = std::min(dp[i][0], dp[i][1]) + 1;
        if (circle[i][0] + circle[i][1] <= m) {
            dp[i + 1][2] = std::min(dp[i + 1][2], dp[i][2] + 1);
        }
        if (i > 0 && circle[i - 1][0] + circle[i][0] <= m && circle[i - 1][1] + circle[i][1] <= m) {
            dp[i + 1][2] = std::min(dp[i + 1][2], dp[i - 1][2] + 2);
        }
        if (i < end - 1) {
            dp[i + 1][0] = dp[i + 1][2] + 1;
            if (circle[i][0] + circle[i + 1][0] <= m) {
                dp[i + 1][0] = std::min(dp[i + 1][0], dp[i][1] + 1);
            }
            dp[i + 1][1] = dp[i + 1][2] + 1;
            if (circle[i][1] + circle[i + 1][1] <= m) {
                dp[i + 1][1] = std::min(dp[i + 1][1], dp[i][0] + 1);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;
        int ans = 2 * n;

        int circle[n][2];
        int dp[n + 1][3] = {}; //  upside, downside, none

        for (int i = 0; i < n; i++) std::cin >> circle[i][0];
        for (int i = 0; i < n; i++) std::cin >> circle[i][1];

        dp[0][0] = 1; dp[0][1] = 1; dp[0][2] = 0;
        make_dp(dp, circle, 0, n, m);
        ans = std::min(ans, dp[n][2]);

        if (n > 1 && circle[n - 1][0] + circle[0][0] <= m) {
            dp[1][0] = 2; dp[1][1] = (circle[0][1] + circle[1][1] <= m) ? 1 : 2; dp[1][2] = 1;
            make_dp(dp, circle, 1, n, m);
            ans = std::min(ans, dp[n - 1][1] + 1);
        } // OX

        if (n > 1 && circle[n - 1][1] + circle[0][1] <= m) {
            dp[1][0] = (circle[0][0] + circle[1][0] <= m) ? 1 : 2; dp[1][1] = 2; dp[1][2] = 1;
            make_dp(dp, circle, 1, n, m);
            ans = std::min(ans, dp[n - 1][0] + 1);
        } // XO

        if (n > 1 && circle[n - 1][0] + circle[0][0] <= m && circle[n - 1][1] + circle[0][1] <= m) {
            dp[1][0] = 1; dp[1][1] = 1; dp[1][2] = 0;
            make_dp(dp, circle, 1, n, m);
            ans = std::min(ans, dp[n - 1][2] + 2);
        } // OO

        std::cout << ans << '\n';
    }
}