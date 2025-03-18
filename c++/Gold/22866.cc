//
// Created by jaehy on 25. 3. 18.
//
#include <iostream>
#include <stack>

void see_buildings(int buildings[], int count[], int nearest[], const std::pair<int, int>& ranges)  {
    std::stack<std::pair<int, int>> stack; //height, position
    int step = ranges.first <= ranges.second ? 1 : -1;
    for (int i = ranges.first; i != ranges.second + step; i += step) {
        while (!stack.empty() && stack.top().first <= buildings[i]) {
            stack.pop();
        }
        count[i] += stack.size();
        if (!stack.empty()) {
            if (nearest[i] == 0 || std::abs(nearest[i] - i) > std::abs(i - stack.top().second)) {
                nearest[i] = stack.top().second;
            }
        }
        stack.emplace(buildings[i], i);
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    int buildings[N + 1], count[N + 1] = {}, nearest[N + 1] = {};
    for (int i = 1; i <= N; i++) {
        std::cin >> buildings[i];
    }
    see_buildings(buildings, count, nearest, {1, N});
    see_buildings(buildings, count, nearest, {N, 1});

    for (int i = 1; i <= N; ++i) {
        if (count[i]) {
            std::cout << count[i] << ' ' << nearest[i] << '\n';
        } else {
            std::cout << "0\n";
        }
    }
}
