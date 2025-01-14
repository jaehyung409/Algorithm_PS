//
// Created by jaehy on 25. 1. 15.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool greedy_compare(const std::string& fir, const std::string& sec){
    if (fir == sec) return false;
    std::string first = fir + sec, second = sec + fir;
    size_t size = first.length();
    for (size_t idx = 0; idx < size; idx++) {
        if (first[idx] == second[idx]) continue;
        return first[idx] > second[idx];
    }
    if (fir.length() > sec.length()) return true;
    return false;
}

int main(){
    int N, num;
    std::cin >> N;
    std::vector<std::string> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        arr[i] = std::to_string(num);
    }
    std::sort(arr.begin(), arr.end(), greedy_compare);
    if (arr[0] == "0"){
        std::cout << 0 << '\n';
        return 0;
    }
    for (auto str : arr)
        std::cout << str;
    std::cout << '\n';

    return 0;
}