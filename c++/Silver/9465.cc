//
// Created by jaehy on 25. 7. 9..
//

#include <iostream>
#define MAX_SIZE 100'000

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T, stickers[MAX_SIZE][2];
    std::cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++) std::cin >> stickers[i][0];
        for (int i = 0; i < n; i++) std::cin >> stickers[i][1];
        stickers[1][0] += stickers[0][1];
        stickers[1][1] += stickers[0][0];
        for (int i = 2; i < n; i++) {
            stickers[i][0] += std::max(std::max(stickers[i-2][0], stickers[i-2][1]), stickers[i-1][1]);
            stickers[i][1] += std::max(std::max(stickers[i-2][0], stickers[i-2][1]), stickers[i-1][0]);
        }
        std::cout << std::max(stickers[n-1][0], stickers[n-1][1]) << '\n';
    }
}