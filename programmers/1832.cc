#include <vector>

using namespace std;

int MOD = 20170805;

void update(int x, int y, int (&map)[500][500][2], int status) {
    if (status == 1) {
        return;
    }
    if (x > 0) { // down
        map[x][y][0] = map[x-1][y][0];
        if (status != 2) {
            map[x][y][1] = map[x-1][y][0];
        }
    }
    if (y > 0) { // right
        map[x][y][1] = (map[x][y][1] + map[x][y-1][1]) % MOD;
        if (status != 2) {
            map[x][y][0] = (map[x][y][0] + map[x][y-1][1]) % MOD;
        }
    }

}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int map[500][500][2] = {};
    map[0][0][0] = map[0][0][1] = 1;
    const int size = m + n - 2;
    for (int i = 1; i <= size; ++i) {
        for (int x = 0; x <= i; ++x) {
            if (i - x >= n) continue;
            if (x >= m) break;
            update(x, i - x, map, city_map[x][i-x]);
        }
    }
    if (m == 1 && n == 1) return 1;
    if (m == 1) return map[m-1][n-2][1];
    if (n == 1) return map[m-2][n-1][0];
    return (map[m-2][n-1][0] + map[m-1][n-2][1]) % MOD;
}