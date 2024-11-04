//
// Created by jaehy on 24. 11. 4.
//
#include <iostream>
#include <string>
#include <queue>

int main(){
    std::priority_queue<int> ordered_num;
    std::string inp_num;
    std::cin >> inp_num;
    for (const auto &num : inp_num){
        ordered_num.push(num - '0');
    }
    while (!ordered_num.empty()){
        std::cout << ordered_num.top();
        ordered_num.pop();
    }
    std::cout << '\n';
    return 0;
}