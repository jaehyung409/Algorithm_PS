#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& graph, vector<int>& visit, queue<int>& q, int n) {
    int ret = 0;
    q.push(n);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        ret++;
        for (auto n : graph[top]) {
            if (visit[n] == 0) {
                q.push(n);
                visit[n] = 1;
            }
        }
    }
    return ret - 1;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0, temp = 0;
    vector<vector<int>> graph(101), reverse(101);
    vector<int> visit(n+1, 0);
    queue<int> q;
    for (auto fight : results) {
        graph[fight.front()].emplace_back(fight.back());
        reverse[fight.back()].emplace_back(fight.front());
    }
    for (int i = 1; i <= n; ++i) {
        temp = bfs(graph, visit, q, i);
        temp += bfs(reverse, visit, q, i);
        if (temp == n-1) ++answer;
        fill(visit.begin(), visit.end(), 0);
    }
    return answer;
}