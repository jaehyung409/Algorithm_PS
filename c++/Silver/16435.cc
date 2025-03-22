//
// Created by jaehy on 25. 3. 22.
//
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int num_of_fruits, snake_bird;
    std::cin >> num_of_fruits >> snake_bird;
    std::vector<int> fruit_height(num_of_fruits);

    for (int i = 0; i < num_of_fruits; ++i) {
        std::cin >> fruit_height[i];
    }
    std::ranges::sort(fruit_height);
    for (auto height : fruit_height) {
        if (snake_bird < height) break;
        snake_bird++;
    }
    std::cout << snake_bird << '\n';
}
