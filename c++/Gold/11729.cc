//
// Created by jaehy on 24. 11. 10.
//
#include <iostream>

void hanoi_top_move(int N, int source, int dest){
    if (N == 1) {
        std::cout << source << ' ' << dest << '\n';
        return;
    }
    hanoi_top_move(N-1, source, dest^source);
    std::cout << source << ' ' << dest << '\n';
    hanoi_top_move(N-1, dest^source, dest);
}
int main() {
    int N;
    std::cin >> N;

    std::cout << (1 << N) - 1 << '\n';
    hanoi_top_move(N, 1, 3);

    return 0;
}