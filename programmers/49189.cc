//
// Created by jaehy on 25. 8. 4.
//

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> nodes(20001);
int visited[20001] = {};

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (auto vec : edge) {
        nodes[vec.front()].emplace_back(vec.back());
        nodes[vec.back()].emplace_back(vec.front());
    }
    queue<int> prev, next;
    prev.push(1);
    visited[1] = 1;
    while (!prev.empty()) {
        int node = prev.front();
        prev.pop();
        ++answer;
        for (int n : nodes[node]) {
            if (visited[n] == 0) {
                next.push(n);
                visited[n] = 1;
            }
        }
        if (prev.empty() && !next.empty()) {
            answer = 0;
            swap(prev, next);
        }
    }
    return answer;
}