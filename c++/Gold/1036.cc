//
// Created by jaehy on 25. 3. 15.
//
#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <unordered_map>

std::unordered_map<char, int> base36Map;
char base36[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                   'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

std::string digits[36];

void plus_base36(std::string& lhs, char& rhs, int digit) {
    int added = base36Map[lhs[digit]] + base36Map[rhs];
    if (added < 36) {
        lhs[digit] = base36[added];
    } else {
        lhs[digit] = base36[added % 36];
        plus_base36(lhs, base36[added / 36], digit - 1);
    }
}

void update_digits(int idx, int digit) {
    plus_base36(digits[idx], base36[35 - idx], digit);
}

int main()
{
    // mapping
    for (int i = 0; i < 36; ++i) {
        base36Map[base36[i]] = i;
    }
    const std::string based = "0000000000000000000000000000000000000000000000000000"; // 52
    std::fill_n(digits, 36, based);

    // main
    int N, K;
    std::string sum = based;
    std::string base36;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> base36;
        int k = 51;
        for (auto num : std::ranges::reverse_view(base36)) {
            update_digits(base36Map[num], k);
            plus_base36(sum, num, k);
            --k;
        }
    }
    std::sort(digits, digits + 36, std::greater<>());

    std::cin >> K;
    for (int i = 0; i < K; ++i) {
        int k = 51;
        for (auto num : std::ranges::reverse_view(digits[i])) {
            plus_base36(sum, num, k--);
        }
    }
    bool non_zero_appeared = false;
    for (const auto num : sum) {
        if (!non_zero_appeared && num == '0') {
            continue;
        }
        non_zero_appeared = true;
        std::cout << num;
    }
    if (!non_zero_appeared) {
        std::cout << '0' << '\n';
    }
}