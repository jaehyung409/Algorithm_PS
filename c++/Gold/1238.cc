//
// Created by jaehy on 25. 1. 9.
//
#include <iostream>
#include <algorithm>
#define SIZE 1000
#define MAX_INT 1<<29

int floyd_warshall(int (&graph)[SIZE+1][SIZE+1], int N, int dest){
    for (int k = 1; k < N+1; k++){
        for (int i = 1; i < N+1; i++){
            for (int j = 1; j < N+1; j++)
                graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }
    int ret = 0;
    for (int i = 1; i < N+1; i++)
        ret = std::max(ret, graph[i][dest] + graph[dest][i]);
    return ret;
}

int dijkstra(int (&graph)[SIZE+1][SIZE+1], int N, int dest){
    int array[SIZE+1], min = MAX_INT, idx;
    int visited[SIZE+1] = {0,};
    visited[dest] = 1;
    for (int i = 1; i < N+1; i++)
        array[i] = graph[dest][i];
    for (int i = 0; i < N; i++) {
        min = MAX_INT;
        for (int j = 1; j < N+1; j++) {
            if (array[j] < min && !visited[j]) {
                min = array[j];
                idx = j;
            }
        }
        visited[idx] = true;
        for (int j = 1; j < N+1; j++) {
            if (graph[idx][j] && !visited[j])
                array[j] = std::min(array[j], array[idx] + graph[idx][j]);
        }
    }
    int back[SIZE+1];
    std::fill(visited, visited+N+1, 0);
    visited[dest] = 1;
    for (int i = 1; i < N+1; i++)
        back[i] = graph[i][dest];
    for (int i = 0; i < N; i++) {
        min = MAX_INT;
        for (int j = 1; j < N+1; j++) {
            if (back[j] < min && !visited[j]) {
                min = back[j];
                idx = j;
            }
        }
        visited[idx] = true;
        for (int j = 1; j < N+1; j++) {
            if (graph[j][idx] && !visited[j])
                back[j] = std::min(back[j], back[idx] + graph[j][idx]);
        }
    }
    int ret = 0;
    for (int i = 1; i < N+1; i++)
        ret = std::max(ret, array[i] + back[i]);
    return ret;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M, X, start, end, cost, i, j;
    std::cin >> N >> M >> X;
    int graph[SIZE+1][SIZE+1];
    for (i = 1; i < N+1; i++){
        for (j = 1; j < N+1; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = MAX_INT;
        }
    }
    for (i = 0; i < M; i++){
        std::cin >> start >> end >> cost;
        graph[start][end] = cost;
    }
    std::cout << dijkstra(graph, N, X) << '\n';
}