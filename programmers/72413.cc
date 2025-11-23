#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 20000001));
    for (int i = 1; i <= n; ++i) dist[i][i] = 0;

    for (auto& edge : fares) {
        dist[edge[0]][edge[1]] = edge[2];
        dist[edge[1]][edge[0]] = edge[2];
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int answer = 20000001;
    for (int i = 1; i <= n; ++i) {
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    return answer;
}