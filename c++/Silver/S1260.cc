#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>

std::array<bool,1001> visit{false};
std::array<std::vector<int>,1001> node;

void dfs(int start){
    std::cout << start << " ";
    visit[start] = true;
    std::vector<int> next = node[start];
    std::sort(next.begin(),next.end());
    for(const auto& n : next){
        if(!visit[n])
            dfs(n);
    }
}
void bfs(int start){
    std::queue<int> q;
    q.push(start);
    visit[start] = true;
    while(!q.empty()){
        int idx = q.front();
        std::cout << idx << " ";
        q.pop();
        std::vector<int> next = node[idx];
        std::sort(next.begin(),next.end());
        for(const auto& n : next){
            if(!visit[n]) {
                q.push(n);
                visit[n] = true;
            }
        }
    }
}

int main() {
    int N,M,V;
    std::cin >> N >> M >> V;
    for(int i = 0; i < M; ++i){
        int x,y;
        std::cin >> x >> y;
        node[x].push_back(y);
        node[y].push_back(x);
    }
    dfs(V);
    std::cout << '\n';
    visit = {false};
    bfs(V);
    std::cout << '\n';

    return 0;
}