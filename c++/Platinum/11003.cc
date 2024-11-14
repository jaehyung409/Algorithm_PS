//
// Created by jaehy on 24. 11. 14.
//
#include <iostream>
#include <queue>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, L, i, num;
    std::deque<int> input_deque;
    std::priority_queue<int, std::vector<int>, std::greater<>> ans, del;
    std::cin >> N >> L;

    for (i = 0; i < L; i++){
        std::cin >> num;
        input_deque.push_back(num);
        ans.push(num);
        std::cout << ans.top() << ' ';
    }
    for (; i < N; i++){
        std::cin >> num;
        input_deque.push_back(num);
        ans.push(num);

        num = input_deque.front();
        input_deque.pop_front();
        del.push(num);
        while (!del.empty() && ans.top() == del.top()){
            ans.pop();
            del.pop();
        }
        std::cout << ans.top() << ' ';
    }
    std::cout << '\n';
}