//
// Created by jaehy on 24. 12. 28.
//
#include <iostream>
#define MAX_SIZE 500

size_t matrix_chain(int (&matrix)[MAX_SIZE+1], const int size){
    size_t arr[MAX_SIZE][MAX_SIZE];
    int i, j, k, l;
    for (i = 0; i < size; i++){
        arr[i][i] = 0;
    }
    for (l = 1; l < size; l++){
        for (i = 0; i < size - l; i++){
            j = i + l;
            arr[i][j] = 1 << 31;
            for (k = i; k < j; k++)
                arr[i][j] = std::min(arr[i][j],
                                     arr[i][k] + arr[k+1][j] + matrix[i]*matrix[k+1]*matrix[j+1]);
        }
    }
    return arr[0][size-1];
}

int main(){
    int N, r, c;
    int matrix[MAX_SIZE+1];
    std::cin >> N;
    for (int i = 0; i < N; i++){
        std::cin >> r >> c;
        matrix[i] = r;
        matrix[i+1] = c;
    }
    std::cout << matrix_chain(matrix, N) << '\n';

    return 0;
}