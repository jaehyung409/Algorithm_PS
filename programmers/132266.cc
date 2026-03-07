#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<vector<int>> link(n+1);
    for (auto road : roads) {
        link[road.front()].emplace_back(road.back());
        link[road.back()].emplace_back(road.front());
    }
    map<int, int> m;
    vector<bool> visited(n+1);
    queue<int> q;
    q.push(destination);
    m[destination] = 0;
    visited[destination] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (auto next : link[current]) {
            if (!visited[next]) {
        		visited[next] = true;
                q.push(next);
                m[next] = m[current] + 1;
            }
        }
    }
    vector<int> answer;
    for (auto s : sources) {
        int dist = m.count(s) ? m[s] : -1;
    	answer.emplace_back(dist);    
    }
    return answer;
}
