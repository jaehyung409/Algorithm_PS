//
// Created by jaehy on 24. 11. 15.
//
#include <iostream>
#include <queue>
#define MAX_SIZE 10000

struct node{
    int ver_a;
    int ver_b;
    int span_a_b;
    node(int ver_a, int ver_b, int span_a_b)
    : ver_a(ver_a), ver_b(ver_b), span_a_b(span_a_b){};
};
struct min_span{
    bool operator() (node a, node b){
        return a.span_a_b >= b.span_a_b;
    }
};
int find_root(int x, int (&parent)[MAX_SIZE + 1]){
    if (parent[x] == x) return x;
    return parent[x] = find_root(parent[x], parent);
}
void union_root(int x, int y, int (&parent)[MAX_SIZE + 1]){
    x = find_root(x, parent);
    y = find_root(y, parent);
    if (x != y) parent[y] = x;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long spanning = 0;
    std::priority_queue<node, std::vector<node>, min_span> pq;
    int parent[MAX_SIZE + 1];
    int V, E;
    int ver_a, ver_b, span_a_b;
    std::cin >> V >> E;
    for (int i = 0; i < V + 1; i++) parent[i] = i;
    for (int i = 0; i < E; i++){
        std::cin >> ver_a >> ver_b >> span_a_b;
        pq.emplace(ver_a, ver_b, span_a_b);
    }
    while(!pq.empty()){
        if (find_root(pq.top().ver_a, parent) == find_root(pq.top().ver_b, parent)) {
            pq.pop();
            continue;
        }
        union_root(pq.top().ver_a, pq.top().ver_b, parent);
        spanning += pq.top().span_a_b;
        pq.pop();
    }
    std::cout << spanning << '\n';
}