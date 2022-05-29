#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <limits>

int main(){
    int V, E, k;
    std::cin >> V >> E >> k;
    std::vector<std::pair<int,int>> graph[V+1];
    std::vector<int> distance(V+1, std::numeric_limits<int>::max());
    std::vector<bool> visited(V+1, false);
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> min_q;
    for(int i = 0; i < E; ++i){
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u].emplace_back(v,w);
    }
    min_q.push(std::make_pair(0, k));
    distance[k] = 0;
    while(!min_q.empty()){
        int now = min_q.top().second;
        int now_dist = min_q.top().first;
        min_q.pop();
        visited[now] = true;
        for(int i = 0; i < graph[now].size(); ++i){
            int next = graph[now][i].first;
            int next_dist = graph[now][i].second + now_dist;

            if(next_dist > distance[next]) continue;
            if(visited[next]) continue;

            distance[next] = next_dist;
            min_q.push(std::make_pair(next_dist, next));
        }
    }
    for(int i = 1; i < V + 1; ++i){
        if(distance[i] == std::numeric_limits<int>::max())
            std::cout << "INF" << '\n';
        else
            std::cout << distance[i] << '\n';
    }

    return 0;
}