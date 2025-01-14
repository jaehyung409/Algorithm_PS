//
// Created by jaehy on 25. 1. 14.
//
#include <iostream>

static const long long modular = 1'000'000'007;
typedef long long ll;

ll modInverse(ll num, int mod = modular){
    if (num == 1) return 1LL;
    ll result = 1;
    int exponent = mod - 2;
    while (exponent > 0){
        if(exponent % 2 ==1) result = (result * num) % mod;
        num = (num * num) % mod;
        exponent /= 2;
    }
    return result;
}
void zero_add(int fenwick[], int size, int idx, int num){
    while (idx <= size){
        fenwick[idx] += num;
        idx += idx & -idx;
    }
} // add 1 (no zero), 0 (zero)

int zero_sum(const int fenwick[], int idx){
    int sum = 0;
    while (idx > 0){
        sum += fenwick[idx];
        idx -= idx & -idx;
    }
    return sum;
}

void update(ll fenwick[], int size, int idx, int num){
    while (idx <= size){
        fenwick[idx] *= num;
        fenwick[idx] %= modular;
        idx += idx & -idx;
    }
}

ll mul(const ll fenwick[], int idx){
    ll ans = 1;
    while(idx > 0){
        ans *= fenwick[idx];
        ans %= modular;
        idx -= idx & -idx;
    }
    return ans;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, K, i;
    std::cin >> N >> M >> K;
    int arr[N+1], fenwick_zero[N+1];
    bool zeros[N+1];
    std::fill(zeros, zeros+N+1, false);
    std::fill(fenwick_zero, fenwick_zero+N+1, 0);
    ll fenwick_mul[N+1];
    std::fill(fenwick_mul, fenwick_mul+N+1, 1);
    for (i = 1; i < N+1; i++){
        std::cin >> arr[i];
    }
    for (i = 1 ; i < N+1; i++){
        if (arr[i] == 0) {
            arr[i] = 1;
            zeros[i] = true;
        }
        update(fenwick_mul, N, i, arr[i]);
        zero_add(fenwick_zero, N, i, (zeros[i]) ? 0 : 1);
    }
    int order, fir, sec;
    for (i = 0; i < M + K; i++){
        std::cin >> order >> fir >> sec;
        if (order == 1){
            if (sec == 0) {
                zero_add(fenwick_zero, N, fir, -1);
                zeros[fir] = true;
                continue;
            }
            if (zeros[fir]) {
                zero_add(fenwick_zero, N, fir, 1);
                zeros[fir] = false;
            }
            update(fenwick_mul, N, fir, modInverse(arr[fir]));
            update(fenwick_mul, N, fir, sec);
            arr[fir] = sec;
        }
        else {
            if (zero_sum(fenwick_zero,sec) - zero_sum(fenwick_zero,fir-1) != sec - fir + 1)
                std::cout << 0 << '\n';
            else
                std::cout << (mul(fenwick_mul, sec) * modInverse(mul(fenwick_mul, fir-1)))
                           % modular << '\n';
        }
    }

    return 0;
}