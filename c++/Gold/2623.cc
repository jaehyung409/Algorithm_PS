//
// Created by jaehy on 24. 11. 21.
//
#include <iostream>
#include <vector>
#include <queue>

int main(){
    int N, M, manage, temp, current, i;
    int graph[1002] = {0};
    int ans[1000];
    std::cin >> N >> M;
    std::vector<int> singer_order[N+1];
    for (i = 0; i < M; i++){
        std::cin >> manage;
        if (manage < 2) continue;
        std::cin >> temp;
        for (int j = 1; j < manage; j++){
            std::cin >> current;
            if (current == temp) {
                std::cout << 0 << '\n';
                exit(0);
            }
            graph[current]++;
            singer_order[temp].push_back(current);
            temp = current;
        }
    }

    std::queue<int> nodes;
    for (i = 1; i < N+1; i++) if (graph[i] == 0) nodes.push(i);
    i = 0;
    while(!nodes.empty()){
        temp = nodes.front();
        ans[i++] = temp;
        nodes.pop();
        for (auto edges : singer_order[temp]){
            graph[edges]--;
            if (graph[edges] == 0) nodes.push(edges);
        }
    }
    if (i != N) std::cout << 0 << '\n';
    else {
        for (i = 0; i < N; i++)
            std::cout << ans[i] << '\n';
    }

    return 0;
}