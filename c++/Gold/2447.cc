//
// Created by jaehy on 24. 11. 10.
//
#include <iostream>
#define MAX_SIZE 2187

void star_recursive(int x_pos, int y_pos, int size, char (&pattern)[MAX_SIZE][MAX_SIZE]) {
    if (size == 1) {
        pattern[x_pos][y_pos] = '*';
        return;
    }
    int new_size = size / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            star_recursive(x_pos + i * new_size, y_pos + j * new_size, new_size, pattern);
        }
    }
}

int main(){
    int N;
    std::cin >> N;
    char pattern[MAX_SIZE][MAX_SIZE];

    star_recursive(0, 0, N, pattern);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (pattern[i][j] != '*') std::cout << ' ';
            else std::cout << pattern[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}