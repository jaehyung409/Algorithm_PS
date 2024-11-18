//
// Created by jaehy on 24. 11. 18.
//
#include <iostream>
#define MAX_SIZE 500000

int find_set(int a, int (&set)[MAX_SIZE]){
    if (set[a] == a) return a;
    return set[a] = find_set(set[a], set);
}

bool union_set(int a, int b, int (&set)[MAX_SIZE]){
    int root_a = find_set(a, set);
    int root_b = find_set(b, set);
    set[root_a] = root_b;
    if (root_a == root_b) return true;
    return false;
}

int main(){
    int N, M, disjoint_set[MAX_SIZE];
    int a, b, i, ans = 0;

    std::cin >> N >> M;
    for (i = 0; i < N; i++) disjoint_set[i] = i;
    for (i = 1; i <= M; i++){
        std::cin >> a >> b;
        if (union_set(a, b, disjoint_set) && ans == 0) ans = i;
    }
    std::cout << ans << '\n';

    return 0;
}