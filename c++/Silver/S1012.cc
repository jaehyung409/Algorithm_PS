#include <iostream>
#include <queue>
#include <utility>

int x_dir[] = {-1, 1, 0, 0};
int y_dir[] = {0, 0, -1, 1};

int main(){
    int T;
    std::cin >> T;
    for(int i = 0; i < T; ++i){
        int M, N, K, count = 0;
        std::cin >> M >> N >> K;
        int arr[M][N];
        for(int m = 0; m < M; ++m){
            for(int n = 0; n < N; ++n) arr[m][n] = 0;
        }
        for(int k = 0; k < K; ++k){
            int x,y;
            std::cin >> x >> y;
            arr[x][y] = 1;
        }
        std::queue<std::pair<int,int>> tmp;
        for(int m = 0; m < M; ++m){
            for(int n = 0; n < N; ++n){
                if(arr[m][n] == 1){
                    count++;
                    arr[m][n] = 0;
                    tmp.push(std::make_pair(m,n));
                    while(!tmp.empty()){
                        int x = tmp.front().first;
                        int y = tmp.front().second;
                        tmp.pop();
                        for(int q = 0; q < 4; ++q){
                            int x_tmp = x_dir[q] + x;
                            int y_tmp = y_dir[q] + y;
                            if(0 <= x_tmp && x_tmp < M && 0 <= y_tmp && y_tmp < N){
                                if(arr[x_tmp][y_tmp] == 1){
                                    arr[x_tmp][y_tmp] = 0;
                                    tmp.push(std::make_pair(x_tmp,y_tmp));
                                }
                            }
                        }
                    }
                }
            }
        }
        std::cout << count << std::endl;
    }

    return 0;
}