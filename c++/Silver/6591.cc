//
// Created by jaehy on 25. 3. 22.
//
#include <cstdint>
#include <iostream>

long long nCk(int n, int k) {
    if (n == 0) return 0LL;
    long long ret = 1;
    k = std::min(k, n - k);
    for (int i = 1; i <= k; ++i) {
        ret = ret * (n - k + i) / i;
    }
    return ret;
}


int main() {
    int n{1}, k;
    while (n || k) {
        std::cin >> n >> k;
        if (const long long temp = nCk(n, k)) {
            std::cout << temp << '\n';
        }
    }
}