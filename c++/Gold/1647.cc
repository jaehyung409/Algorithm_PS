//
// Created by jaehy on 24. 11. 16.
//
#include <iostream>
#include <algorithm>
#define MAX_SIZE 1000000
static int house[100001];

int find_set(int a){
    if (house[a] == a) return a;
    return house[a] = find_set(house[a]);
}

void union_set(int a, int b){
    int root_a = find_set(a);
    int root_b = find_set(b);
    house[root_a] = root_b;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M, house_A, house_B, path_cost, i, last;
    long long sum = 0;
    std::pair<int, std::pair<int, int>> graph[MAX_SIZE+1];
    std::cin >> N >> M;
    for (i = 0; i < M; i++){
        std::cin >> house_A >> house_B >> path_cost;
        graph[i] = {path_cost, {house_A, house_B}};
    }
    std::sort(graph, graph+M);
    for (i = 1; i < N+1; i++){
        house[i] = i;
    }
    i = -1;
    int connected = 0;
    while(connected != N-1){
        i++;
        if (find_set(graph[i].second.first) == find_set(graph[i].second.second))
            continue;
        union_set(graph[i].second.first, graph[i].second.second);
        sum += graph[i].first;
        last = graph[i].first;
        connected++;
    }
    std::cout << sum - last << '\n';
    return 0;
}