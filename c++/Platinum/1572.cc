//
// Created by jaehy on 25. 1. 13.
//
#include <iostream>
#define MAX_NUM 65536

void update(int fenwick[], int idx, int diff){
    while (idx <= MAX_NUM+1){
        fenwick[idx] += diff;
        idx += (idx & -idx);
    }
}

long long get_sum(int fenwick[], int idx){
    long long sum = 0;
    while (idx > 0){
        sum += fenwick[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

long long get_mid(int fenwick[], int low, int high, int K){
    K = (K + 1)/2;
    int mid;
    while (low < high){
        mid = (low + high) / 2;
        if (get_sum(fenwick, mid) < K) low = mid + 1;
        else high = mid;
    }
    return static_cast<long long>(low-1);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K, i;
    long long ans;
    std::cin >> N >> K;
    int fenwick[MAX_NUM+2], arr[N]; // 0 ~ 65536
    std::fill(fenwick, fenwick+MAX_NUM+2, 0);
    for (i = 1; i <= K; i++){
        std::cin >> arr[i];
        update(fenwick, arr[i]+1, 1);
    }
    ans = get_mid(fenwick, 0, MAX_NUM+1, K);
    for (i = 1; i <= N - K; i++) {
        std::cin >> arr[i + K];
        update(fenwick, arr[i]+1, -1);
        update(fenwick, arr[i + K]+1, 1);
        ans += get_mid(fenwick, 0, MAX_NUM+1, K);
    }
    std::cout << ans << '\n';

    return 0;
}