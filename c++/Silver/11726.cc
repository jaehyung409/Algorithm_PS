//
// Created by jaehy on 2024-10-30.
//

#include <iostream>

int main(){
    int N, ans{0}, first{1}, second{2};
    std::cin >> N;
    for (int i = 2; i < N; ++i){
        ans = first + second;
        first = second % 10007;
        second = ans % 10007;
    }
    if (N == 1) std::cout << first << '\n';
    else if (N == 2) std::cout << second << '\n';
    else std::cout << ans%10007 << '\n';
    return 0;
}