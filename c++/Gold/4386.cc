//
// Created by jaehy on 25. 1. 7.
//
#include <iostream>
#include <queue>
#include <cmath>
#define MAX_SIZE 100
typedef std::pair<float, std::pair<int, int>> fii;
typedef std::pair<float, float> ff;

float get_distance(ff &a, ff &b){
    float x_diff = std::pow(a.first - b.first, 2);
    float y_diff = std::pow(a.second - b.second, 2);
    return std::sqrt(x_diff + y_diff);
}

int find(int (&visited)[MAX_SIZE+1], int node){
    if (visited[node] == node) return node;
    return visited[node] = find(visited, visited[node]);
}

void union_set(int (&visited)[MAX_SIZE+1], int a, int b){
    int root_a = find(visited, a);
    int root_b = find(visited, b);
    visited[root_a] = visited[root_b];
}

int main(){
    ff stars[MAX_SIZE+1];
    std::priority_queue<fii, std::vector<fii>, std::greater<>> pq;
    int N;
    int visited[MAX_SIZE+1];
    float a, b;
    std::cin >> N;
    for (int i = 1; i < N+1; i++){
        std::cin >> a >> b;
        stars[i] = std::make_pair(a, b);
        visited[i] = i;
    }
    for (int i = 1; i < N; i++){
        for (int j = i+1; j < N+1; j++)
            pq.emplace(get_distance(stars[i], stars[j]), std::make_pair(i, j));
    }
    float result = 0;
    while (!pq.empty()){
        float dist = pq.top().first;
        int pos_a = pq.top().second.first;
        int pos_b = pq.top().second.second;
        pq.pop();
        if (find(visited, pos_a) != find(visited, pos_b)){
            union_set(visited, pos_a, pos_b);
            result += dist;
        }
    }
    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << result << '\n';

    return 0;
}