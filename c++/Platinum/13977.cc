//
// Created by jaehy on 25. 1. 15.
//
#include <iostream>
static const long long modular = 1'000'000'007;
static long long factorial[4'000'001];

long long modInverse(long long num, long long mod = modular){
    long long res = 1;
    long long exponent = mod - 2;
    while (exponent > 0){
        if (exponent % 2 == 1)
            res = (res * num) % mod;
        num = (num * num) % mod;
        exponent /= 2;
    }
    return res;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    factorial[0] = 1;
    for (int i = 1; i <= 4'000'000; i++){
        factorial[i] = factorial[i - 1] * i;
        factorial[i] %= modular;
    }
    int M, N, K;
    long long ans;
    std::cin >> M;
    for (int i = 0; i < M; i++){
        std::cin >> N >> K;
        ans = (factorial[N] * modInverse(factorial[K])) % modular;
        std::cout << (ans * modInverse(factorial[N-K])) % modular << '\n';
    }

    return 0;
}