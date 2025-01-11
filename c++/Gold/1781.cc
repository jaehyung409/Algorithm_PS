//
// Created by jaehy on 25. 1. 11.
//
#include <iostream>
#include <queue>

typedef std::pair<int, long long> il;

struct Compare {
    bool operator()(const il &a, const il &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::priority_queue<il, std::vector<il>, Compare> heap;
    int N, dead_line, time = 1;
    long long reward;
    std::cin >> N;
    for (int i = 0; i < N; i++){
        std::cin >> dead_line >> reward;
        heap.emplace(dead_line, reward);
    }
    std::priority_queue<long long, std::vector<long long>, std::greater<>> ans;
    std::queue<long long> temp;
    long long sum = 0;
    while(!heap.empty()){
        while (ans.size() <= time) {
            dead_line = heap.top().first;
            if (dead_line > time) break;
            reward = heap.top().second;
            if (ans.size() + temp.size() < time) temp.push(reward);
            else if (!ans.empty() && ans.top() < reward){
                temp.push(reward);
                ans.pop();
            }
            heap.pop();
            if (heap.empty()) break;
        }
        while (!temp.empty()){
            ans.push(temp.front());
            temp.pop();
        }
        time++;
    }
    while (!ans.empty()){
        sum += ans.top();
        ans.pop();
    }
    std::cout << sum << '\n';

    return 0;
}