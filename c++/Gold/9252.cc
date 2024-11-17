//
// Created by jaehy on 24. 11. 18.
//
#include <iostream>
#include <string>
#define MAX_SIZE 1000

int main() {
    std::string fir, sec;
    std::cin >> fir >> sec;
    int arr[MAX_SIZE + 1][MAX_SIZE + 1][2] = {0}; // num,  dir
    char ans[MAX_SIZE];
    int i, j, k = 0, length;
    size_t f_l = fir.length(), s_l = sec.length(), temp;
    for (i = 1; i <= f_l; i++) {
        for (j = 1; j <= s_l; j++) {
            if (fir[i-1] == sec[j-1]) {
                arr[i][j][0] = arr[i - 1][j - 1][0] + 1;
                arr[i][j][1] = 0; // <^
            } else if (arr[i - 1][j][0] >= arr[i][j - 1][0]) {
                arr[i][j][0] = arr[i - 1][j][0];
                arr[i][j][1] = 1; // ^
            } else {
                arr[i][j][0] = arr[i][j - 1][0];
                arr[i][j][1] = 2;
            }
        }
    }
    length = arr[--i][--j][0];
    std::cout << length << '\n';
    while (arr[i][j][0] != 0) {
        if (arr[i][j][1] == 0) {
            ans[k++] = fir[i-1];
            i--;
            j--;
        }
        else if (arr[i][j][1] == 1) i--;
        else j--;
    }
    for (;k > 0;) std::cout << ans[--k];
    std::cout << '\n';

    return 0;
}
