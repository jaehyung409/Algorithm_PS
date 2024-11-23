//
// Created by jaehy on 24. 11. 24.
//
#include <iostream>
#include <string>
#define MAX_SIZE 64

std::string quad_tree (char (&arr)[MAX_SIZE][MAX_SIZE], int row, int col, int size){
    if (size == 1) return std::string(1, arr[row][col]);
    std::string left_up = quad_tree(arr, row, col, size/2);
    std::string right_up = quad_tree(arr, row, col + size/2, size/2);
    std::string left_down = quad_tree(arr, row + size/2, col, size/2);
    std::string right_down = quad_tree(arr, row + size/2, col + size/2, size/2);
    std::string total = left_up + right_up + left_down + right_down;
    if (!total.compare("1111")) return "1";
    else if (!total.compare("0000")) return "0";
    else return "(" + total + ")";
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, i ,j;
    char arr[MAX_SIZE][MAX_SIZE];
    std::cin >> N;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++)
            std::cin >> arr[i][j];
    }
    std::cout << quad_tree(arr, 0, 0, N) << '\n';

    return 0;
}