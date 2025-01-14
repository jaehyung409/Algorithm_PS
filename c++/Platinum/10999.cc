//
// Created by jaehy on 25. 1. 15.
//
#include <iostream>

void lazy_update(long long segment[], long long lazy[], int start, int end, int node){
    if (lazy[node] != 0){
        segment[node] += (end - start + 1) * lazy[node];
        if (start != end){
            lazy[node << 1] += lazy[node];
            lazy[(node << 1) + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void build(long long segment[], long long arr[], int start, int end, int node){
    if (start == end) segment[node] = arr[start];
    else {
        int mid = (start + end) / 2;
        build(segment, arr, start, mid, node << 1);
        build(segment, arr, mid + 1, end, (node << 1) + 1);
        segment[node] = segment[node << 1] + segment[(node << 1) + 1];
    }
}

void range_update(long long segment[], long long lazy[], int start, int end, int left, int right, int node, long long diff){
    lazy_update(segment, lazy, start, end, node);
    if (right < start || left > end) return;
    if (start >= left && end <= right){
        segment[node] += (end - start + 1) * diff;
        if (start != end){
            lazy[node << 1] += diff;
            lazy[(node << 1) + 1] += diff;
        }
        return;
    }
    int mid = (start + end) / 2;
    range_update(segment, lazy, start, mid, left, right, node << 1, diff);
    range_update(segment, lazy, mid + 1, end, left, right, (node << 1) + 1, diff);
    segment[node] = segment[node << 1] + segment[(node << 1) + 1];
}

long long range_sum(long long segment[], long long lazy[], int start, int end, int left, int right, int node){
    lazy_update(segment, lazy, start, end, node);
    if (right < start || left > end) return 0;
    if (start >= left && end <= right) return segment[node];
    int mid = (start + end) / 2;
    return range_sum(segment, lazy, start, mid, left, right, node << 1)
         + range_sum(segment, lazy, mid + 1, end, left, right, (node << 1) + 1);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M, K;
    std::cin >> N >> M >> K;
    long long segment[4 * N], lazy[4 * N], arr[N+1];
    for (int i = 1; i <= N; i++)
        std::cin >> arr[i];
    std::fill(lazy, lazy + 4 * N, 0);
    build(segment, arr, 1, N, 1);
    int order, left, right;
    long long diff;
    for (int i = 0; i < M + K; i++){
        std::cin >> order;
        if (order == 1){
            std::cin >> left >> right >> diff;
            range_update(segment, lazy, 1, N, left, right, 1, diff);
        }
        else {
            std::cin >> left >> right;
            std::cout << range_sum(segment, lazy, 1, N ,left, right, 1) << '\n';
        }
    }

    return 0;
}