//
// Created by jaehy on 25. 1. 10.
//
#include <iostream>
#include <queue>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::priority_queue<int, std::vector<int>, std::greater<>> right;
    std::priority_queue<int> left;
    int N;
    std::cin >> N;
    int mid, num, dir;
    std::cin >> mid;
    std::cout << mid << '\n';
    for (int i = 1; i < N; i++){
        std::cin >> num;
        if (num >= mid) right.push(num);
        else left.push(num);
        dir = right.size() - left.size();
        if (dir > 1) {
            left.push(mid);
            mid = right.top();
            right.pop();
        }
        if (dir < 0) {
            right.push(mid);
            mid = left.top();
            left.pop();
        }
        std::cout << mid << '\n';
    }

    return 0;
}