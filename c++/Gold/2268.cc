//
// Created by jaehy on 25. 1. 14.
//
#include <iostream>

void update(long long fenwick[], int idx, int size, long long diff){
    while (idx <= size){
        fenwick[idx] += diff;
        idx += idx & -idx;
    }
}

long long sum(const long long fenwick[], int idx){
    long long ret = 0;
    while (idx > 0){
        ret += fenwick[idx];
        idx -= idx & -idx;
    }
    return ret;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, order;
    long long fir, sec;
    std::cin >> N >> M;
    long long fenwick[N+1], arr[N+1];
    std::fill(fenwick, fenwick+N+1, 0);
    std::fill(arr, arr+N+1, 0);
    for (int i = 0; i < M; i++){
        std::cin >> order >> fir >> sec;
        if (order == 0) {
            if (sec < fir) std::swap(fir, sec);
            std::cout << sum(fenwick, sec) - sum(fenwick, fir-1) << '\n';
        }
        else {
            update(fenwick, fir, N, sec - arr[fir]);
            arr[fir] = sec;
        }
    }
}