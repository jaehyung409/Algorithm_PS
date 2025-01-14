//
// Created by jaehy on 25. 1. 15.
//
#include <iostream>

void update_lazy(long long segment[], long long lazy[], int start, int end, int node){
    if (lazy[node] != 0){
        segment[node] += (end - start + 1) * lazy[node];
        if (start != end){
            lazy[node << 1] += lazy[node];
            lazy[(node << 1) + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void build(long long segment[], int arr[], int start, int end, int node){
    if (start == end) segment[node] = arr[start];
    else {
        int mid = (start + end) / 2;
        build(segment, arr, start, mid, node << 1);
        build(segment, arr, mid + 1, end, (node << 1) + 1);
        segment[node] = segment[node << 1] + segment[(node << 1) + 1];
    }
}

void update(long long segment[], long long lazy[], int node, int start, int end, int left, int right, long long diff){
    update_lazy(segment, lazy, start, end, node);
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
    update(segment, lazy, node << 1, start, mid, left, right, diff);
    update(segment, lazy, (node<<1)+1, mid+1, end, left, right, diff);
    segment[node] = segment[node << 1] + segment[(node << 1) + 1];
}

long long query_idx(long long segment[], long long lazy[], int node, int start, int end, int idx){
    update_lazy(segment, lazy, start, end, node);
    if (start == end) return segment[node];
    int mid = (start + end) / 2;
    if (idx <= mid) return query_idx(segment, lazy, node << 1, start, mid, idx);
    else return query_idx(segment, lazy, (node<<1)+1, mid+1, end, idx);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    long long segment[4 * N], lazy[4 * N];
    int arr[N+1];
    std::fill(lazy, lazy + 4*N, 0);
    for (int i = 1; i < N+1; i++)
        std::cin >> arr[i];
    build(segment, arr, 1, N, 1);
    int order, first, second, M;
    long long diff;
    std::cin >> M;
    for (int i = 0; i < M; i++){
        std::cin >> order;
        if (order == 1){
            std::cin >> first >> second >> diff;
            update(segment, lazy, 1, 1, N, first, second, diff);
        }
        else {
            std::cin >> first;
            std::cout << query_idx(segment, lazy, 1, 1, N, first) << '\n';
        }
    }

    return 0;
}
