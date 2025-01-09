//
// Created by jaehy on 25. 1. 10.
//
#include <iostream>
#include <queue>
#define SIZE 1000
typedef std::pair<int, int> ii;

void cut(int H, int W, int x, int y, int time, char (&alps)[SIZE][SIZE], std::queue<std::pair<ii, int>> &q){
    std::pair<int, int> dir[] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
    for (auto item : dir) {
        if (x + item.first >= 0 && x + item.first < H && y + item.second >= 0 && y + item.second < W) {
            if (alps[x + item.first][y + item.second] > '0') {
                if(--alps[x + item.first][y + item.second] == '0') q.emplace(std::make_pair(x + item.first, y + item.second), time+1);
            }
        }
    }
}

int wave(int H, int W, char (&alps)[SIZE][SIZE], std::queue<std::pair<ii, int>> &q){
    int time, x, y;
    for (x = 0; x < H; x++){
        for (y = 0; y < W; y++)
            if (alps[x][y] == '.') cut(H, W, x, y, 0, alps, q);
    }
    while (!q.empty()){
        x = q.front().first.first;
        y = q.front().first.second;
        time = q.front().second;
        q.pop();
        cut(H, W, x, y, time, alps, q);
    }
    return time;
}

int main(){
    int H, W;
    std::queue<std::pair<ii, int>> q;
    std::cin >> H >> W;
    char alps[SIZE][SIZE];
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++)
            std::cin >> alps[i][j];
    }
    std::cout << wave(H, W, alps, q) << '\n';
}