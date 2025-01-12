//
// Created by jaehy on 25. 1. 13.
//
#include <algorithm>
#include <iostream>

long long ans = 0;

void merge(int list[], int left, int mid, int right){
    for (int i = left; i <= mid; i++)
        ans += std::lower_bound(list + mid + 1, list + right, list[i]) - (list + mid + 1);
    std::sort(list + left, list + right);
}

void merge_sort(int list[], int left, int right){
    int mid;
    if (left < right){
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right+1);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    merge_sort(arr, 0, N-1);

    std::cout << ans << '\n';
}