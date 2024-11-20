//
// Created by jaehy on 24. 11. 20.
//
#include <iostream>
#include <cmath>

int shape_z(size_t N, int row, int col){
    if (N == 0) return 0;
    int ran = static_cast<int>(std::pow(2, N-1));
    int section = static_cast<int>(std::pow(ran, 2));
    if (row < ran){
        if (col < ran)
            return 0 + shape_z(N-1, row, col);
        else
            return section + shape_z(N-1, row, col - ran);
    }
    else {
        if (col < ran)
            return 2 * section + shape_z(N-1, row - ran, col);
        else
            return 3 * section + shape_z(N-1, row - ran, col - ran);
    }
}

int main(){
    int N, r, c;
    std::cin >> N >> r >> c;

    std::cout << shape_z(N, r, c) << '\n';

    return 0;
}