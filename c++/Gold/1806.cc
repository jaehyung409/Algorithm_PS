//
// Created by jaehy on 24. 11. 16.
//
#include <iostream>
#define MAX_SIZE 100000

int main(){
    int N, S, left_pointer = 0, right_pointer = -1, temp = 0;
    int arr[MAX_SIZE+1], ans = MAX_SIZE + 1;
    std::cin >> N >> S;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    arr[N] = 0;
    while (right_pointer != N){
        if (temp < S)
            temp += arr[++right_pointer];
        else {
            ans = std::min(ans, right_pointer - left_pointer + 1);
            temp -= arr[left_pointer++];
        }
    }
    std::cout << ((ans == MAX_SIZE+1) ? 0 : ans) <<'\n';
}