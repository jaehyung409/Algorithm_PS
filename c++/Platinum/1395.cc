//
// Created by jaehy on 24. 11. 15.
//
#include <iostream>
#define MAX_SIZE 100000

int seg_tree[4 * MAX_SIZE] = {0};
int lazy[4 * MAX_SIZE] = {0};

void update_lazy(int start, int end, int node){
    if (lazy[node] != 0) {
        seg_tree[node] = (end - start + 1) * lazy[node] - seg_tree[node];
        if (start != end) {
            lazy[node << 1] ^= 1;
            lazy[(node << 1) + 1] ^= 1;
        }
        lazy[node] = 0;
    }
}

void update(int start, int end, int left, int right, int node){
    update_lazy(start, end, node);
    if (right < start || left > end) return;
    if (start >= left && end <= right) {
        seg_tree[node] = end - start + 1 - seg_tree[node];
        if (start != end){
            lazy[node << 1] ^= 1;
            lazy[(node << 1) + 1] ^= 1;
        }
        return;
    }
    int mid = (start + end)/2;
    update(start, mid, left, right, node << 1);
    update(mid+1, end, left, right, (node<<1) + 1);
    seg_tree[node] = seg_tree[node << 1] + seg_tree[(node << 1) + 1];
}

int sum(int start, int end, int left, int right, int node) {
    update_lazy(start, end, node);
    if (right < start || left > end) return 0;
    if (start >= left && end <= right) return seg_tree[node];
    int mid = (start + end)/2;
    return sum(start, mid, left, right, node << 1) + sum(mid+1, end, left, right, (node << 1) + 1);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M, O, S, T;
    std::cin >> N >> M;
    for (int i = 0; i < M; i++){
        std::cin >> O >> S >> T;
        if (O == 0) update(1, N, S, T, 1);
        else std::cout << sum(1, N, S, T, 1) << '\n';
    }
    return 0;
}