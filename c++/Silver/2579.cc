//
// Created by jaehy on 24. 11. 7.
//
#include <iostream>

int main(){
    int N;
    int stairs, dynamic_stairs[300][2];
    std::cin >> N;

    for (int i = 0; i < N; i++){
        std::cin >> stairs;
        if (i == 0){
            dynamic_stairs[i][0] = stairs;
            dynamic_stairs[i][1] = -10000;
            continue;
        }
        else if (i == 1){
            dynamic_stairs[i][0] = stairs;
            dynamic_stairs[i][1] = dynamic_stairs[i-1][0] + stairs;
        }
        else {
            dynamic_stairs[i][0] = std::max(dynamic_stairs[i-2][0], dynamic_stairs[i-2][1]) + stairs;
            dynamic_stairs[i][1] = dynamic_stairs[i-1][0] + stairs;
        }
    }

    std::cout << std::max(dynamic_stairs[N-1][0], dynamic_stairs[N-1][1]);

    return 0;
}