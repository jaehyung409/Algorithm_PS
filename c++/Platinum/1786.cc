//
// Created by jaehy on 25. 7. 14.
//

#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> ans;
    std::vector<int> pre_search;
    std::string text;
    std::string pattern;
    std::getline(std::cin, text);
    std::getline(std::cin, pattern);
    const size_t size = pattern.size();
    const size_t size_minus_one = size - 1;
    pre_search.resize(size);
    pre_search[0] = 0;
    for (int i = 1; i < size; i++) {
        int temp = pre_search[i - 1];
        while (true) {
            if (pattern[temp] == pattern[i]) {
                pre_search[i] = temp + 1;
                break;
            }
            if (temp == 0) {
                pre_search[i] = 0;
                break;
            }
            temp = pre_search[temp - 1];
        }
    }

    int idx = 0;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == pattern[idx]) {
            if (idx == size_minus_one) {
                ans.push_back(i + 1);
                idx = pre_search[idx];
            } else {
                idx++;
            }
        } else {
            while (idx != 0) {
                idx = pre_search[idx - 1];
                if (text[i] == pattern[idx]) {
                    idx++;
                    break;
                }
            }
        }
    }

    std::cout << ans.size() << "\n";
    for (const auto i : ans)
        std::cout << i - size_minus_one << " ";
    std::cout << "\n";
}