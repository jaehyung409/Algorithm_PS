//
// Created by jaehy on 24. 11. 5.
//
#include <iostream>
#include <algorithm>

bool compare(int a, int b){
    return a > b;
}

int main(){
    int N, num, maximum = -1, temp;
    int rope[100000];

    std::cin >> N;
    for (int i = 0; i < N; ++i){
        std::cin >> rope[i];
    }

    std::sort(rope, rope + N, compare);
    for (int i = 0; i < N; ++i){
        temp = rope[i] * (i + 1);
        if (temp > maximum) maximum = temp;
    }

    std::cout << maximum << '\n';

    return 0;
}