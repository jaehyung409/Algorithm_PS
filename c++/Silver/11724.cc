//
// Created by jaehy on 24. 11. 7.
//
#include <iostream>
#include <stack>

int main(){
    int N, M, u, v, i, j;
    int connected_component = 0, node;
    bool graph[1001][1001] = {false}, visited[1001]={false};
    std::cin >> N >> M;
    for (i = 0; i < M; i++){
        std::cin >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }

    std::stack<int> dfs;
    for (i = 1; i <= N; i++){
        if (visited[i]) continue;
        visited[i] = true;
        connected_component++;
        dfs.push(i);
        while (!dfs.empty()){
            node = dfs.top();
            dfs.pop();
            visited[node] = true;
            for (j = i + 1; j <= N; j++){
                if (graph[node][j] && !visited[j]) dfs.push(j);
            }
        }
    }
    std::cout << connected_component << '\n';
    return 0;
}