//
// Created by jaehy on 25. 7. 19.
//

#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    char num;
    std::vector<char> ans;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        while (!ans.empty() && k > 0 && ans.back() < num) {
            ans.pop_back();
            k--;
        }
        ans.push_back(num);
    }
    for (int i = 0, size = ans.size(); i < size - k; i++) {
        std::cout << ans[i];
    }
}