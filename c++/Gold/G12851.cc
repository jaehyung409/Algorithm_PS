#include <iostream>
#include <queue>
#include <utility>
/* with queue && visited
 * like dfs
 * why max -> 100000 + 1 ??
 * if value > 100000, then *2 operation needed
 * but *2 op and minus op is slower than minus op and *2 op */
const int MAX = 100000 + 1;

int main(){
    int N, K;
    std::cin >> N >> K;
    bool visited[MAX] = {false,};
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(N,0));
    int min_sec = 0, count = 0;
    while(!q.empty()){
        int loc = q.front().first;
        int sec = q.front().second;
        q.pop();
        visited[loc] = true;
        if(min_sec && min_sec == sec && loc == K) count++;
        if(!min_sec && loc == K){
            min_sec = sec;
            count++;
        }
        if(loc + 1 < MAX && !visited[loc + 1]) q.push(std::make_pair(loc+1,sec+1));
        if(loc - 1 >= 0 && !visited[loc - 1]) q.push(std::make_pair(loc-1,sec+1));
        if(loc * 2 < MAX && !visited[loc * 2]) q.push(std::make_pair(loc*2,sec+1));
    }
    std::cout << min_sec << std::endl;
    std::cout << count << std::endl;
    return 0;
}