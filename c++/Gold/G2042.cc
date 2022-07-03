#include <iostream>
#include <vector>
#define LL long long
/* Fenwick Tree
 * using binary
 * update && sum with tree[idx] += num && [idx += (idx & -idx)]
 * segment tree ++ (but only sum of given range)
 */

void Update(std::vector<LL>& tree, int idx, LL num){
    while(idx < tree.size()){
        tree[idx] += num;
        idx += (idx & -idx);
    }
}

LL Sum(std::vector<LL>& tree, int idx){
    LL ans = 0;
    while(idx > 0){
        ans += tree[idx];
        idx -= (idx & -idx);
    }
    return ans;
}

void fastIO(){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);
}
int main(){
    fastIO();
    int N, M, K;
    std::cin >> N >> M >> K;
    std::vector<LL> tree(N + 1);
    std::vector<LL> temp(N + 1);
    for(int i = 1; i <= N; ++i){
        int num;
        std::cin >> temp[i];
        Update(tree, i, temp[i]);
    }
    for(int i = 0; i < M + K; ++i){
        LL check, a, b;
        std::cin >> check >> a >> b;
        if(check == 1){
            LL diff = b - temp[a];
            temp[a] = b;
            Update(tree, a, diff);
        }
        if(check == 2)
            std::cout << Sum(tree,b) - Sum(tree, a - 1) << std::endl;
    }

    return 0;
}