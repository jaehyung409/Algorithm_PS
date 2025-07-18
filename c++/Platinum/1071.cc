//
// Created by jaehy on 25. 7. 18.
//

#include <iostream>
#include <map>

int main () {
    int n;
    std::map<int, int> num;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (!num.contains(x)) {
            num[x] = 1;
        } else {
            num[x]++;
        }
    }
    int before = -2;
    while (!num.empty()) {
        auto it = num.begin();
        if (it->first == before + 1) {
            it++; // it can't be the last element because it violates the condition
        }
        while (std::next(it) != num.end() && (it == num.begin() && std::next(it)->first == it->first + 1 && num.upper_bound(it->first + 1) == num.end())) {
            ++it;
        }
        before = it->first;
        std::cout << it->first << " ";
        if (it->second > 1) {
            it->second--;
        } else {
            num.erase(it);
        }
    }
    std::cout << '\n';
}