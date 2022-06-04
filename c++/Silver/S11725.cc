#include <iostream>
#include <vector>
#include <queue>
/* find node with array && bfs
 * arr[i] = root of i
 * bfs with queue */

int main(){
    int N;
    std::cin >> N;
    std::vector<int> nodes[N+1];
    int arr[N+1];
    for(int i = 1; i < N + 1; ++i) arr[i] = i;
    for(int i = 1; i < N; ++i){
        int a, b;
        std::cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    std::queue<int> tmp;
    tmp.push(1);
    while(!tmp.empty()){
        int i = tmp.front();
        tmp.pop();
        for(int k = 0; k < nodes[i].size(); ++k){
            if(arr[nodes[i][k]] == nodes[i][k]) {
                arr[nodes[i][k]] = i;
                tmp.push(nodes[i][k]);
            }
        }
    }
    for(int i = 2; i < N + 1; ++i) std::cout << arr[i] << '\n';
    return 0;
}