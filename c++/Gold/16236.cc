//
// Created by jaehy on 25. 7. 12..
//

#include <cstring>
#include <iostream>
#include <queue>

int dx[] = {0, -1, 1, 0}; // up, left, right, down
int dy[] = {-1, 0, 0, 1};

int main() {
    int n;
    std::cin >> n;
    int water[n][n];
    std::queue<std::pair<int, int>> q;
    int visited[n][n];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> water[i][j];
            if (water[i][j] == 9) {
                q.emplace(100 * i + j, 0);
                visited[i][j] = 1;
            }
        }
    }
    int time = 0, level = 2, fishes = 0, find_distance = 1000;
    std::pair<int, int> first = std::make_pair(q.front().first / 100, q.front().first % 100); // (y,x)
    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    while (!q.empty()) {
        const int x = q.front().first % 100;
        const int y = q.front().first / 100;
        const int distance = q.front().second;
        q.pop();
        if (find_distance != 1000 && (find_distance < distance || q.empty())) {
            std::queue<std::pair<int, int>>().swap(q); // queue clear
            time += find_distance + 1;
            if (++fishes == level) {
                ++level;
                fishes = 0;
            }
            const int new_x = pq.top() % 100;
            const int new_y = pq.top() / 100;
            std::priority_queue<int, std::vector<int>, std::greater<>>().swap(pq); // heap clear
            find_distance = 1000;
            q.emplace(new_y * 100 + new_x, 0);
            water[first.first][first.second] = 0;
            water[new_y][new_x] = 9;
            first = std::make_pair(new_y, new_x);
            // std::cout << "------------------------\n";
            // std::cout << "move " << first.second << " " << first.first << std::endl;
            // std::cout << "level " << level << std::endl;
            // std::cout << "fishes " << fishes << std::endl;
            // std::cout << "time " << time << std::endl;
            // std::cout << "------------------------\n";
            // // print water
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < n; j++) {
            //         std::cout << water[i][j];
            //     }
            //     std::cout << std::endl;
            // }
            memset(visited, 0, sizeof(visited));
            visited[new_y][new_x] = 1;
            continue;
        }
        for (int i = 0; i< 4; ++i) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && visited[new_y][new_x] == 0) {
                if (water[new_y][new_x] == level || water[new_y][new_x] == 0) {
                    q.emplace(new_y * 100 + new_x, distance + 1);
                    visited[new_y][new_x] = 1;
                } else if (water[new_y][new_x] < level) { // found!
                    q.emplace(new_y * 100 + new_x, distance + 1);
                    pq.emplace(new_y * 100 + new_x);
                    find_distance = distance;
                    visited[new_y][new_x] = 1;
                }
            }
        }
    }
    std::cout << time << '\n';
}