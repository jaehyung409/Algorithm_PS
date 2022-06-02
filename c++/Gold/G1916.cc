#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <limits>

/* Dijkstra's algorithms
 * INF && priority_queue (min heap)
 * No minus edge */

int main(){
    int N, M;
    std::cin >> N >> M;
    std::vector<std::pair<int,int>> edge[N + 1];
    std::vector<int> distance(N + 1, std::numeric_limits<int>::max());
    std::vector<bool> visited(N + 1, false);
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> min_heap;
    for(int i = 0; i < M; ++i){
        int start, end, dist;
        std::cin >> start >> end >> dist;
        edge[start].emplace_back(dist, end);
    }
    int start, end;
    std::cin >> start >> end;
    min_heap.push(std::make_pair(0, start));
    distance[start] = 0;
    while (!min_heap.empty() && !visited[end]){
        int now = min_heap.top().second;
        int now_dist = min_heap.top().first;
        visited[now] = true;
        min_heap.pop();
        for(const auto& n : edge[now]){
            int next = n.second;
            int next_dist = n.first + now_dist;
            if (next_dist >= distance[next]) continue;
            distance[next] = next_dist;
            min_heap.push(std::make_pair(next_dist, next));
        }
    }
    std::cout << distance[end] << std::endl;
}