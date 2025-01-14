//
// Created by jaehy on 25. 1. 14.
//
#include <iostream>
#include <functional>

void build(int segment[], int arr[], int node, int start, int end, std::function<int(int, int)> compare){
    if (start == end) segment[node] = arr[start];
    else {
        int mid = (start + end) / 2;
        build(segment, arr, node * 2, start, mid, compare);
        build(segment, arr, node * 2 + 1, mid + 1, end, compare);
        segment[node] = compare(segment[node * 2], segment[node * 2 + 1]);
    }
}

int get(int segment[], int node, int start, int end, int left, int right, const std::function<int(int, int)>& compare){
    if (left > end || right < start) return 1000000000 - compare(-1, 1000000000);
    if (left <= start && end <= right) return segment[node];
    int mid = (start + end) / 2;
    return compare(get(segment, node * 2, start, mid, left, right, compare),
                   get(segment, node * 2 + 1, mid + 1, end, left, right, compare));
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, fir, sec;
    std::cin >> N >> M;
    int arr[N];
    int segment_min[4 * N], segment_max[4 * N];
    for (int i = 0; i < N; i++) std::cin >> arr[i];
    build(segment_min, arr, 1, 0, N-1, [](int a, int b) {return  std::min(a, b); });

    for (int i = 0; i < M; i++){
        std::cin >> fir >> sec;
        std::cout << get(segment_min, 1, 0, N-1, fir-1, sec-1, [](int a, int b) {return std::min(a, b); }) << '\n';
    }

    return 0;
}