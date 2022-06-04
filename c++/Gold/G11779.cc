#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <utility>
/* dijkstra with min heap
 * make route array -> next[route] = now route + next
 * when distance renewal(change distance, root, queue) */

int main(){
    int n, m;
    std::cin >> n >> m;
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> min_heap;
    std::vector<int> distance(n+1, std::numeric_limits<int>::max());
    std::vector<int> route[n + 1];
    std::vector<bool> visited(n+1, false);
    std::vector<std::pair<int, int>> nodes[n+1]; // distance, next_node
    for(int i = 0; i < m; ++i){
        int start, end, dist;
        std::cin >> start >> end >> dist;
        nodes[start].emplace_back(dist, end);
    }
    int s, e;
    std::cin >> s >> e;
    route[s].push_back(s);
    distance[s] = 0;
    min_heap.push(std::make_pair(0,s));
    while(!min_heap.empty() && !visited[e]){
        int now = min_heap.top().second;
        int now_dist = min_heap.top().first;
        min_heap.pop();
        visited[now] = true;
        for(int i = 0; i < nodes[now].size(); ++i){
            int next = nodes[now][i].second;
            int next_dist = now_dist + nodes[now][i].first;
            if(visited[next]) continue;
            if(next_dist >= distance[next]) continue;
            route[next] = route[now];
            route[next].push_back(next);
            min_heap.push(std::make_pair(next_dist, next));
            distance[next] = next_dist;
        }
    }
    std::cout << distance[e] << '\n';
    std::cout << route[e].size() << '\n';
    for(const auto& a : route[e])
        std::cout << a << ' ';
    std::cout << '\n';

    return 0;
}