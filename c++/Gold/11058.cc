//
// Created by jaehy on 24. 11. 2.
//

#include <iostream>

int main(){
    int N, i;
    long long ans_table[100][2];
    for (i = 0; i < 3; ++i) {
        ans_table[i][0] = i+1; // max A
        ans_table[i][1] = 0; // buffer size
    }
    std::cin >> N;
    for (; i < N; ++i){
        long long max_value = ans_table[i-1][0] + std::max((long long)1, ans_table[i-1][1]);
        long long buffer = ans_table[i-1][1];
        for (int j = i - 3; j > 0; j--){
            if (ans_table[j][0] * (i - j - 1) > max_value) {
                max_value = ans_table[j][0] * (i - j - 1);
                buffer = ans_table[j][0];
            }
        }
        ans_table[i][0] = max_value;
        ans_table[i][1] = buffer;
    }
    std::cout << ans_table[N-1][0] << '\n';

    return 0;
}