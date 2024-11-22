//
// Created by jaehy on 24. 11. 22.
//
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T, N, K, W, i;
    int time[1001], complete_time[1001];
    int graph[1001] = {0};

    std::cin >> T;

    while (T--) {
        std::cin >> N >> K;
        for (i = 1; i < N + 1; i++) std::cin >> time[i];
        std::vector<int> order[N + 1];
        std::fill(complete_time, complete_time+N+1, 0);

        for (i = 0; i < K; i++) {
            int X, Y;
            std::cin >> X >> Y;
            order[X].push_back(Y);
            graph[Y]++;
        }

        std::cin >> W;
        std::stack<int> building;

        for (i = 1; i < N + 1; i++) {
            if (graph[i] == 0) {
                complete_time[i] = time[i];
                building.push(i);
            }
        }
        while (!building.empty()){
            int current = building.top();
            building.pop();
            for (auto node : order[current]){
                graph[node]--;
                complete_time[node] = std::max(complete_time[node], time[node] + complete_time[current]);
                if (graph[node] == 0) building.push(node);
            }
        }
        std::cout << complete_time[W] << '\n';
    }

    return 0;
}