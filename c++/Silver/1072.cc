//
// Created by jaehy on 25. 7. 18.
//

#include <iostream>

int main() {
    long long x, y;
    std::cin >> x >> y;
    long long z = y * 100 / x;
    if (z >= 99) std::cout << -1 << '\n';
    else {
        long long left = 0, right = 1'000'000'000;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long newZ = (y + mid) * 100 / (x + mid);
            if (newZ > z) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        std::cout << left << '\n';
    }
}