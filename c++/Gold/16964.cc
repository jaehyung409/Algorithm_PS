//
// Created by jaehy on 25. 1. 6.
//
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

bool valid_dfs(std::vector<bool> &visited, std::vector<int> adj[], std::queue<int> &dfs_path, int node, std::stack<int> root){
    bool check = false;
    if (dfs_path.empty()) return true;
    if ((dfs_path.size() == visited.size() - 2) && (node != 1)) return false;
    else {
        int next = dfs_path.front();
        dfs_path.pop();
        if (visited[next]) return false;
        while (!root.empty()){
            if (node == 0) return false;
            for (auto it = adj[node].begin(); it != adj[node].end();){
                if (visited[*it]) it = adj[node].erase(it);
                else if (*it == next){
                    check = true;
                    it = adj[node].erase(it);
                }
                else ++it;
            }
            if (check) break;
            if (!adj[node].empty()) return false;
            node = root.top();
            root.pop();
        }
        visited[next] = true;
        return valid_dfs(visited, adj, dfs_path, next, root);
    }
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, a, b, node, start;
    std::cin >> N;
    std::vector<bool> visited(N+1, false);
    std::queue<int> dfs_path;
    std::stack<int> root;
    std::vector<int> adj[N+1];
    for (int i = 0; i < N-1; i++){
        std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        std::cin >> node;
        dfs_path.push(node);
    }
    root.push(0);
    start = dfs_path.front();
    visited[start] = true;
    dfs_path.pop();
    if (valid_dfs(visited, adj, dfs_path, start, root)) std::cout << "1\n";
    else std::cout << "0\n";
}