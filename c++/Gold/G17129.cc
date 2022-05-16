#include <iostream>
#include <queue>
#include <utility>

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(){
    int N,M;
    std::queue<std::pair<int,int>> q;
    std::cin >> N >> M;
    int arr[N][M];
    char tmp;

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            std::cin >> tmp;
            arr[i][j] = tmp - '0';
            if(arr[i][j]  == 2){
                q.push(std::make_pair(i,j));
                arr[i][j] = -1;
            }
        }
    }

    while(!q.empty()){
        int y_pos = q.front().first;
        int x_pos = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i){
            if(y_pos + dy[i] > N-1 || y_pos + dy[i] < 0) continue;
            if(x_pos + dx[i] > M-1 || x_pos + dx[i] < 0) continue;
            int check = arr[y_pos + dy[i]][x_pos + dx[i]];
            if(check == 3 || check == 4 || check == 5){
                std::cout << "TAK" << std::endl;
                std::cout << -arr[y_pos][x_pos] << std::endl;
                exit(0);
            }
            else if(check == 0){
                arr[y_pos + dy[i]][x_pos+dx[i]] = arr[y_pos][x_pos] - 1;
                q.push(std::make_pair(y_pos + dy[i], x_pos + dx[i]));
            }
        }
    }
    std::cout << "NIE" << std::endl;

    return 0;
}