//
// Created by jaehy on 24. 11. 11.
//
#include <iostream>
#include <algorithm>

int main(){
    int N, temp;
    int prev_arr[500], current_arr[500];
    std::cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < i + 1; j++){
            std::cin >> temp;
            if (i == 0){
                current_arr[j] = temp;
                continue;
            }
            if (j == 0) current_arr[j] = temp + prev_arr[j];
            else if (j == i) current_arr[j] = temp + prev_arr[j-1];
            else current_arr[j] = temp + std::max(prev_arr[j-1], prev_arr[j]);
        }
        std::swap(prev_arr, current_arr);
    }
    std::cout << *std::max_element(prev_arr, prev_arr + N) << '\n';
    return 0;
}