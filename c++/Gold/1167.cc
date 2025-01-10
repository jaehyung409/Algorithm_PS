//
// Created by jaehy on 25. 1. 10.
//
#include <iostream>
#include <vector>
#include <queue>
#define MAX_VERTEX 100000

std::pair<int,int> bfs(const int root, std::vector<std::pair<int, int>> tree[], const int size){
    int dist[size+1] = {0,};
    dist[root] = -1;
    std::queue<int> q;
    q.push(root);
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for (auto [ver, cost] : tree[node]){
            if (dist[ver]) continue;
            dist[ver] = dist[node] + cost;
            q.push(ver);
        }
    }
    int max = -1, idx = -1;
    for (int i = 1; i < size+1; i++){
        if (max > dist[i]) continue;
        max = dist[i];
        idx = i;
    }
    return std::make_pair(idx,max+1); // dist[root] = -1
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int V, from, vertex, cost;
    std::cin >> V;
    std::vector<std::pair<int,int>> tree[V+1]; // vertex, cost
    for (int i = 1; i < V+1; i++){
        std::cin >> from;
        while (true){
            std::cin >> vertex;
            if (vertex == -1) break;
            std::cin >> cost;
            tree[from].emplace_back(vertex, cost);
        }
    }
    std::cout << bfs(bfs(1, tree, V).first, tree, V).second << '\n';
}