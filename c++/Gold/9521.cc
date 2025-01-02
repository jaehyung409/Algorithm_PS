//
// Created by jaehy on 25. 1. 2.
//
#include <iostream>
#include <string>

int length_LCS(std::string &str1, std::string &str2){
    int i, j;
    int matrix[str1.length()+1][str2.length()+1];
    for (i = 0; i < str1.length()+1; i++)
        matrix[i][0] = 0;
    for (j = 0; j < str2.length()+1; j++)
        matrix[0][j] = 0;
    for (i = 1; i < str1.length()+1; i++){
        for (j = 1; j < str2.length()+1; j++){
            if (str1[i-1] == str2[j-1])
                matrix[i][j] = matrix[i-1][j-1] + 1;
            else
                matrix[i][j] = std::max(matrix[i-1][j], matrix[i][j-1]);
        }
    }
    return matrix[i-1][j-1];
}

int main(){
    std::string first, second;
    std::cin >> first >> second;
    std::cout << length_LCS(first, second) << '\n';

    return 0;
}