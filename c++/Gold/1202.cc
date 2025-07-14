//
// Created by jaehy on 25. 7. 13.
//

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using ii = std::pair<int, int>;

bool compare(ii p1, ii p2) {
    if (p1.second > p2.second)
        return true;
    return false;
}

int main() {
    int n, k, bag;
    long long total_price = 0;
    std::cin >> n >> k;
    std::vector<ii> jewels(n);
    std::multiset<int> bags;

    for (int i = 0; i < n; ++i)
        std::cin >> jewels[i].first >> jewels[i].second;

    for (int i = 0; i < k; ++i) {
        std::cin >> bag;
        bags.insert(bag);
    }

    std::sort(jewels.begin(), jewels.end(), compare);

    for (auto jewel : jewels) {
        auto it = bags.lower_bound(jewel.first);
        if (it == bags.end()) continue;
        total_price += jewel.second;
        bags.erase(it);
    }
    std::cout << total_price << std::endl;
}