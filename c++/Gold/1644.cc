//
// Created by jaehy on 24. 11. 19.
//
#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX_SIZE 4000000

int main(){
    bool num[MAX_SIZE+1];
    std::fill(num, num + MAX_SIZE + 1, true);
    int prime[300000], N;
    std::cin >> N;
    int temp = 0, l_p = 0, r_p = -1;
    int i, j, k = -1, ans = 0;
    for (i = 2; i < std::sqrt(MAX_SIZE) + 1; i++){
        if (num[i]){
            j = 2;
            while (i * j <= MAX_SIZE){
                num[i * j] = false;
                j++;
            }
        }
    }
    for ( i = 2; i < MAX_SIZE+1; i++){
        if(num[i]) {
            prime[++k] = i;
            if (temp < N) {
                temp += i;
                r_p = k;
            }
        }
    }
    while (r_p != k+1){
        if (temp == N) {
            ans++;
            temp += prime[++r_p];
        }
        else if (temp < N) temp += prime[++r_p];
        else temp -= prime[l_p++];
    }
    std::cout << ans << '\n';

    return 0;
}