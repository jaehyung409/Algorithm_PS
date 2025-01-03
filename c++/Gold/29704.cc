//
// Created by jaehy on 25. 1. 3.
//
#include <iostream>
#include <algorithm>
#define MAX_SIZE 1000
typedef std::pair<int, int> ii;

bool compare(ii &a, ii &b){
    if (a.first < b.first) return true;
    else if (a.first == b.first) return a.second > b.second;
    else return false;
}

int knapsack(int deadline, int size, ii (&assignments)[MAX_SIZE+1]){
    int i, j, time, fee;
    int matrix[MAX_SIZE+1][MAX_SIZE+1];
    for (i = 0; i < deadline + 1; i++)
        matrix[i][0] = 0;
    for (j = 1; j < size + 1; j++){
        time = assignments[j].first;
        fee = assignments[j].second;
        for (i = 0; i < deadline + 1; i++) {
            if (i < time) matrix[i][j] = matrix[i][j-1];
            else matrix[i][j] = std::max(matrix[i-time][j-1] + fee, matrix[i][j-1]);
        }
    }
    return matrix[i-1][j-1];
}

int main(){
    int N, T, day, fee, total_fee = 0;
    ii assignments[MAX_SIZE+1];
    assignments[0] = std::make_pair(0, 0);
    std::cin >> N >> T;
    for (int i = 1; i < N + 1; i++){
        std::cin >> day >> fee;
        total_fee += fee;
        assignments[i] = std::make_pair(day, fee);
    }
    std::sort(assignments, assignments+N, compare);
    std::cout << total_fee - knapsack(T, N, assignments) << '\n';

    return 0;
}