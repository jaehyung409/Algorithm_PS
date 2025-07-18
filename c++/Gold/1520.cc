//
// Created by jaehy on 25. 7. 18.
//

#include <iostream>
#include <vector>

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void get_route(int n, int m, std::vector<std::vector<int>>& map, std::vector<std::vector<long long>>& dp, int i, int j) {
    if (dp[i][j] != 0) return;
    for (int dir = 0; dir < 4; dir++) {
        int ni = i + dx[dir];
        int nj = j + dy[dir];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        if (dp[ni][nj] == -1) continue; // visited (no path)
        if (map[ni][nj] > map[i][j]) {
            get_route(n, m, map, dp, ni, nj);
            if (dp[ni][nj] == -1) continue; // no path from ni, nj
            dp[i][j] += dp[ni][nj];
        }
    }
    if (dp[i][j] == 0) dp[i][j] = -1; // visited (no path)
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector map(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> map[i][j];
        }
    }
    std::vector dp(n, std::vector<long long>(m, 0));
    dp[0][0] = 1; // Start point
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            get_route(n, m, map, dp, i, j);
        }
    }
    if (dp[n - 1][m - 1] < 0) {
        std::cout << 0 << '\n'; // No path to the end
    } else {
        std::cout << dp[n - 1][m - 1] << '\n';
    }
}