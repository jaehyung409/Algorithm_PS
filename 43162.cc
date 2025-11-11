#include <string>
#include <vector>
#include <stack>

using namespace std;

int visited[200] = {};
stack<int> s;

void dfs(int size, vector<vector<int>>& computers) {
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        for (int i = 0; i < size; ++i) {
            if (computers[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                s.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0) {
            ++answer;
            visited[i] = 1;
            s.push(i);
            dfs(n, computers);
        }
    }
    return answer;
}