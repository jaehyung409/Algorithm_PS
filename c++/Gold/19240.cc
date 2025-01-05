//
// Created by jaehy on 25. 1. 5.
//
#include <iostream>
#include <stack>
#include <vector>

bool dfs(int start, std::vector<int> adj[], std::vector<int> &group){
    std::stack<int> toys;
    group[start] = 0;
    toys.push(start);
    int toy;
    while (!toys.empty()){
        toy = toys.top();
        toys.pop();
        for (auto others : adj[toy]){
            if (group[others] == -1){
                group[others] = 1 - group[toy];
                toys.push(others);
            } else if (group[others] == group[toy]) return false;
        }
    }
    return true;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T, N, M, toy_a, toy_b;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> N >> M;
        std::vector<int> adj[N + 1];
        std::vector<int> group(N + 1, -1);
        for (int j = 0; j < M; j++) {
            std::cin >> toy_a >> toy_b;
            adj[toy_a].push_back(toy_b);
            adj[toy_b].push_back(toy_a);
        }
        bool is_possible = true;
        for (int j = 1; j < N + 1; j++) {
            if (group[j] == -1) {
                if(!dfs(j, adj, group)){
                    is_possible = false;
                    break;
                }
            }
        }
        if (is_possible) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}