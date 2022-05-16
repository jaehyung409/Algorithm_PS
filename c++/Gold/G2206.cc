#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(){
    int N,M;
    char temp;
    std::cin >> N >> M;
    int maze[N][M];
    int check[N][M];
    std::queue<std::pair<int, int>> q;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            std::cin >> temp;
            maze[i][j] = temp - '0';
            check[i][j] = temp - '0';
        }
    }
    q.push(std::make_pair(0,0));
    maze[0][0] = -1;
    while(!q.empty()){
        int y_pos = q.front().first;
        int x_pos = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i){
            if(y_pos + dy[i] > N - 1 || y_pos + dy[i] < 0) continue;
            if(x_pos + dx[i] > M - 1 || x_pos + dx[i] < 0) continue;
            if(maze[y_pos + dy[i]][x_pos + dx[i]] == 0){
                maze[y_pos + dy[i]][x_pos + dx[i]] = maze[y_pos][x_pos] - 1;
                q.push(std::make_pair(y_pos + dy[i], x_pos + dx[i]));
            }
        }
    }
    q.push(std::make_pair(N-1,M-1));
    check[N-1][M-1] = -1;
    while(!q.empty()){
        int y_pos = q.front().first;
        int x_pos = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i){
            if(y_pos + dy[i] > N - 1 || y_pos + dy[i] < 0) continue;
            if(x_pos + dx[i] > M - 1 || x_pos + dx[i] < 0) continue;
            if(check[y_pos + dy[i]][x_pos + dx[i]] == 0){
                check[y_pos + dy[i]][x_pos + dx[i]] = check[y_pos][x_pos] - 1;
                q.push(std::make_pair(y_pos + dy[i], x_pos + dx[i]));
            }
        }
    }
    if(maze[N-1][M-1] != 0) {
        int ans = maze[N - 1][M - 1];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (maze[i][j] < 0) {
                    if (i - 2 >= 0) {
                        if (maze[i - 1][j] == 1 && check[i - 2][j] < 0)
                            ans = std::max(ans, maze[i][j] + check[i - 2][j]);
                    }
                    if (j - 2 >= 0) {
                        if (maze[i][j - 1] == 1 && check[i][j - 2] < 0)
                            ans = std::max(ans, maze[i][j] + check[i][j - 2]);
                    }
                    if (i + 2 <= N - 1) {
                        if (maze[i + 1][j] == 1 && check[i + 2][j] < 0)
                            ans = std::max(ans, maze[i][j] + check[i + 2][j]);
                    }
                    if (j + 2 <= M - 1) {
                        if (maze[i][j + 1] == 1 && check[i][j + 2] < 0)
                            ans = std::max(ans, maze[i][j] + check[i][j + 2]);
                    }
                    if (i <= N - 2 && j <= M -2){
                        if (maze[i + 1][j] == 1 && maze[i][j + 1] == 1 && check[i + 1][j + 1] < 0)
                            ans = std::max(ans, maze[i][j] + check[i + 1][j + 1]);
                    }
                    if (i >= 1 && j >= 1){
                        if (maze[i - 1][j] == 1 && maze[i][j - 1] == 1 && check[i - 1][j - 1] < 0)
                            ans = std::max(ans, maze[i][j] + check[i - 1][j - 1]);
                    }
                    if (i >= 1 && j <= M -2){
                        if (maze[i - 1][j] == 1 && maze[i][j + 1] == 1 && check[i - 1][j + 1] < 0)
                            ans = std::max(ans, maze[i][j] + check[i - 1][j + 1]);
                    }
                    if (i <= N - 2 && j >= 1){
                        if (maze[i + 1][j] == 1 && maze[i][j - 1] == 1 && check[i + 1][j - 1] < 0)
                            ans = std::max(ans, maze[i][j] + check[i + 1][j - 1]);
                    }
                }
            }
        }
        if(ans == -1) std::cout << 1 << std::endl;
        else if(ans == maze[N-1][M-1]) std::cout << -ans << std::endl;
        else std::cout << -(ans - 1)  << std::endl;
    }
    else{
        int ans = -1000001;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (maze[i][j] < 0) {
                    if (i - 2 >= 0) {
                        if (maze[i - 1][j] == 1 && check[i - 2][j] < 0)
                            ans = std::max(ans, maze[i][j] + check[i - 2][j]);
                    }
                    if (j - 2 >= 0) {
                        if (maze[i][j - 1] == 1 && check[i][j - 2] < 0)
                            ans = std::max(ans, maze[i][j] + check[i][j - 2]);
                    }
                    if (i + 2 <= N - 1) {
                        if (maze[i + 1][j] == 1 && check[i + 2][j] < 0)
                            ans = std::max(ans, maze[i][j] + check[i + 2][j]);
                    }
                    if (j + 2 <= M - 1) {
                        if (maze[i][j + 1] == 1 && check[i][j + 2] < 0)
                            ans = std::max(ans, maze[i][j] + check[i][j + 2]);
                    }
                    if (i <= N - 2 && j <= M -2){
                        if (maze[i + 1][j] == 1 && maze[i][j + 1] == 1 && check[i + 1][j + 1] < 0)
                            ans = std::max(ans, maze[i][j] + check[i + 1][j + 1]);
                    }
                    if (i >= 1 && j >= 1){
                        if (maze[i - 1][j] == 1 && maze[i][j - 1] == 1 && check[i - 1][j - 1] < 0)
                            ans = std::max(ans, maze[i][j] + check[i - 1][j - 1]);
                    }
                    if (i >= 1 && j <= M -2){
                        if (maze[i - 1][j] == 1 && maze[i][j + 1] == 1 && check[i - 1][j + 1] < 0)
                            ans = std::max(ans, maze[i][j] + check[i - 1][j + 1]);
                    }
                    if (i <= N - 2 && j >= 1){
                        if (maze[i + 1][j] == 1 && maze[i][j - 1] == 1 && check[i + 1][j - 1] < 0)
                            ans = std::max(ans, maze[i][j] + check[i + 1][j - 1]);
                    }
                }
            }
        }
        if(ans == -1000001) std::cout << -1 << std::endl;
        else std::cout << -(ans - 1)  << std::endl;
    }

    return 0;
}