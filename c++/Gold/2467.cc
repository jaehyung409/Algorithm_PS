//
// Created by jaehy on 24. 11. 14.
//
#include <iostream>
#define MAX_SIZE 100000
#define MAX_VALUE 1000000000

int main(){
    int N, abs_min = 2 * MAX_VALUE, temp;
    std::cin >> N;
    int solution[MAX_SIZE];
    int fir_idx, sec_idx;
    int front = 0, back = N-1;
    for (int i = 0; i < N; i++) std::cin >> solution[i];
    while (front != back){
        temp = solution[front] + solution[back];
        if (abs_min > std::abs(temp)) {
            abs_min = std::abs(temp);
            fir_idx = front;
            sec_idx = back;
        }
        if (temp == 0) break;
        else if (temp > 0) {
            back--;
        } else {
            front++;
        }
    }
    std::cout << solution[fir_idx] << ' ' << solution[sec_idx] <<'\n';
    return 0;
}