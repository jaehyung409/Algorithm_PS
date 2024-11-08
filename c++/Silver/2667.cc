//
// Created by jaehy on 24. 11. 8.
//
#include <iostream>
#include <stack>
#include <algorithm>

int main(){
    bool house_map[25][25], visited[25][25] = {false};
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    char house;
    int N, i , j;
    int total_house_num = 0, houses_num[625] = {0};
    int x, y, x_pos, y_pos;
    std::stack<std::pair<int, int>> dfs;

    std::cin >> N;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            std::cin >> house; // 1 or 0
            house_map[i][j] = house - '0';
        }
    }

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if (house_map[i][j] && !visited[i][j]){
                dfs.emplace(i, j);
                while (!dfs.empty()){
                    y = dfs.top().first;
                    x = dfs.top().second;
                    dfs.pop();
                    if (visited[y][x]) continue;
                    houses_num[total_house_num]++;
                    visited[y][x] = true;
                    for (const auto& dir_pair : dir){
                        x_pos = x + dir_pair[0];
                        y_pos = y + dir_pair[1];
                        if (x_pos < 0 || x_pos >= N || y_pos < 0 || y_pos >= N || !house_map[y_pos][x_pos] || visited[y_pos][x_pos]) continue;
                        dfs.emplace(y_pos, x_pos);
                    }
                }
                total_house_num++;
            }
        }
    }

    std::cout << total_house_num << '\n';
    std::sort(houses_num, houses_num + total_house_num);
    for (i = 0; i < total_house_num; i++) std::cout << houses_num[i] << '\n';

    return 0;
}