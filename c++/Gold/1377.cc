//
// Created by jaehy on 25. 1. 11.
//
#include <iostream>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, temp, ans = 0;
    std::cin >> N;
    int idx[N];
    std::pair<int,int> A[N];
    for (int i = 0; i < N; i++) {
        std::cin >> temp;
        A[i] = std::make_pair(temp, i);
    }
    std::stable_sort(A, A+N);
    for (int i = 0; i < N; i++)
        idx[A[i].second]=i;
    for (int i = 0; i < N; i++)
        ans = std::max(ans, i - idx[i]);
    std::cout << ans+1 << '\n';
    return 0;
}