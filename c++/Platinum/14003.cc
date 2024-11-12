//
// Created by jaehy on 24. 11. 12.
//
#include <iostream>
#include <algorithm>
#define MAX_SIZE 1000000

int main(){
    int N, i, k = 0, pos_idx = 1;
    long idx;
    int A[MAX_SIZE], mem_array[MAX_SIZE], temp_array[MAX_SIZE], idx_array[MAX_SIZE];

    std::cin >> N;
    for (i = 0; i < N; i++) std::cin >> A[i];
    temp_array[0] = A[0];
    idx_array[0] = 1;
    for (i = 1; i < N; i++){
        if (A[i] > temp_array[k]) {
            temp_array[++k] = A[i];
            idx_array[k] = i+1;
            mem_array[i] = idx_array[k-1];
            pos_idx = i+1;
        }
        else {
            auto temp_pointer = std::lower_bound(temp_array, temp_array + k + 1, A[i]);
            *(temp_pointer) = A[i];
            idx = temp_pointer - temp_array;
            idx_array[idx] = i+1;
            if (idx == 0) mem_array[i] = 0;
            else mem_array[i] = idx_array[idx - 1];
        }
    }
    std::cout << k + 1 << '\n';
    int ans_array[k + 1];
    while(k != -1){
        ans_array[k--] = A[pos_idx-1];
        pos_idx = mem_array[pos_idx-1];
    }
    for (auto num : ans_array) std::cout << num << ' ';
    std::cout << '\n';
}