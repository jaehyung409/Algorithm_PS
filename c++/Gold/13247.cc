//
// Created by jaehy on 25. 3. 23.
//
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string_view>
#include <unordered_map>
#include <vector>

enum status {
    Left = -1, Init = -1, Right = 1
};
int simulation(std::string_view board, std::unordered_map<int, status> rabbits, int size) {
    int inst = 0;
    for (; size > 2; size--) {
        std::unordered_map<int, status> temp;
        std::unordered_map<int, int> dup_check;
        for (auto [order, value] : rabbits) {
            if (order == 0) inst = Right;
            else if (order == size-1 || order == size-2) inst = Left;
            else {
                switch (board[order]) {
                case 'W':
                    inst = Left;
                case 'B':
                    inst = Right;
                case 'R':
                    if (value == -1) inst = Left;
                    else inst = Right;
                }
            }
            temp[order + inst] = (inst == Right) ? status::Left : status::Right; // recall previous move (for RED)
            dup_check[order + inst]++;
        }
        for (auto [location, count] : dup_check) {
            if (count != 1) temp.erase(location);
        }
        rabbits.swap(temp);
        board.remove_suffix(1);
    }
    return rabbits.size();
}

int main() {
    std::string board;
    int rabbits_num;
    double total_rabbits{0}, total_simul{0};
    std::cin >> board >> rabbits_num;
    const int size = board.size();
    std::vector<int> v(size);
    std::iota(v.begin(), v.end(), 1);
    std::vector<bool> rabbits(size);
    std::fill(rabbits.end() - rabbits_num, rabbits.end(), true);
    do {
        total_simul++;
        std::unordered_map<int, status> rabit_comb;
        for (int i = 0; i < size; ++i) {
            if (rabbits[i]) rabit_comb[i] = Init;
        }
        total_rabbits += simulation(board, rabit_comb, size);
    } while (std::next_permutation(rabbits.begin(), rabbits.end()));
    std::cout << std::fixed << std::setprecision(10) << total_rabbits / total_simul;
}