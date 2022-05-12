#include <iostream>
#include <queue>
#include <utility>

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main(){
    int M,N,tmp;
    std::queue<std::pair<int,int>> box;
    std::cin >> M >> N;
    int tomato[N][M];
    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> tmp;
            tomato[i][j] = tmp;
            if (tmp == 1)
                box.push(std::make_pair(i, j));
        }
    }
    while(!box.empty()){
        int y_pos = box.front().first;
        int x_pos = box.front().second;
        box.pop();
        for(int i = 0; i < 4; ++i){
            if(y_pos + dy[i] > N - 1 || y_pos + dy[i] < 0) continue;
            if(x_pos + dx[i] > M - 1 || x_pos + dx[i] < 0) continue;
            if(tomato[y_pos + dy[i]][x_pos + dx[i]] == 0){
                tomato[y_pos + dy[i]][x_pos + dx[i]] = tomato[y_pos][x_pos] + 1;
                box.push(std::make_pair(y_pos + dy[i], x_pos + dx[i]));
            }
        }
    }
    int max = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(tomato[i][j] == 0) {
                std::cout << -1 << std::endl;
                exit(0);
            }
            else if(tomato[i][j] > max) max = tomato[i][j];
        }
    }
    std::cout << max - 1 << std::endl;

    return 0;
}
