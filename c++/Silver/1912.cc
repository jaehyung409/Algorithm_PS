//
// Created by jaehy on 24. 11. 1.
//

#include <iostream>

int main(){
    int N;
    int arr[100000];
    std::cin >> N;
    long long check_sum = 0;
    long long max_sum = -1001;
    for(int i = 0; i < N; ++i)
        std::cin >> arr[i];
    for(int i = 0; i < N; ++i){
        check_sum += arr[i];
        if (check_sum > max_sum) max_sum = check_sum;
        if (check_sum < 0) check_sum = 0;
    }
    std::cout << max_sum << '\n';
    return 0;
}