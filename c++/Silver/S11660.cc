#include <iostream>
/* dynamic programming
 * with matrix (2d array)
 * check range && inclusive-exclusive principle */

void fastIO(){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);
}
int main() {
    fastIO();
    int N, M;
    std::cin >> N >> M;
    int arr[N][N];
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j) {
            std::cin >> arr[i][j];
            if(i > 0) arr[i][j] += arr[i-1][j];
            if(j > 0) arr[i][j] += arr[i][j-1];
            if(i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];
        }
    }
    for(int i = 0; i < M; ++i){
        int x1,y1,x2,y2,ans;
        std::cin >> x1 >> y1 >> x2 >> y2;
        ans = arr[x2-1][y2-1];
        if(x1 > 1) ans -= arr[x1-2][y2-1];
        if(y1 > 1) ans -= arr[x2-1][y1-2];
        if(x1 > 1 && y1 > 1) ans += arr[x1-2][y1-2];
        std::cout << ans << '\n';
    }
    return 0;
}