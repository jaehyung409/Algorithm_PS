//
// Created by jaehy on 25. 1. 4.
//
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int main(){
    int N, M, K, i, j, counter;
    std::cin >> N >> M;
    std::unordered_map<std::string, int> lamp_counter;
    std::pair<int, int> switches[50];
    std::string lamps;
    for (i = 0; i < N; i++){
        std::cin >> lamps;
        lamp_counter[lamps]++;
    }
    std::cin >> K;
    i = 0;
    for (auto a : lamp_counter){
        counter = 0;
        for (auto state : a.first)
            if (state == '0') counter++;
        switches[i++] = std::make_pair(a.second, counter);
    }
    std::sort(switches, switches+i, std::greater<>());
    for (j = 0; j < i; j++){
        if (switches[j].second > K) continue;
        if ((K - switches[j].second) % 2 == 0) break;
    }
    std::cout << switches[j].first << '\n';
    return 0;
}