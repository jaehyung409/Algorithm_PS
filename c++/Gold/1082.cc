//
// Created by jaehy on 25. 1. 15.
//
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int N, M, cost[10] = {0,}, min_cost = 51, idx;
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> cost[i];
    for (int i = N-1; i >=0; i--){
        if (cost[i] < min_cost){
            min_cost = cost[i];
            idx = i;
        }
    }
    std::cin >> M;
    int size = M / min_cost;
    if (idx ==0) {
        int temp = *std::min_element(cost + 1, cost + N);
        if (M < temp || temp == 0) size = 1;
        else size = (M - temp) / min_cost + 1;
    }
    std::vector<int> room(size, idx);
    M -= size * min_cost;
    int count = 0;
    while (M > 0 && count < size){
        int change = -1;
        for (int i = N-1; i > idx; i--){
            if (cost[i] - min_cost <= M){
                M -= (cost[i] - min_cost);
                change = i;
                break;
            }
        }
        if (change == -1) break;
        room[count++] = change;
    }
    for (auto num: room)
        std::cout << num;
    std::cout << '\n';

    return 0;
}