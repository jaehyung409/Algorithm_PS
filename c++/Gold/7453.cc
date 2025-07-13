//
// Created by jaehy on 25. 7. 13.
//

#include <iostream>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long long ans = 0;
    std::cin >> n;
    int A[n], B[n], C[n], D[n], AB[n * n];
    for (int i = 0; i < n; i++)
        std::cin >> A[i] >> B[i] >> C[i] >> D[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB[i * n + j] = A[i] + B[j];
        }
    }
    std::sort(AB, AB + n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            const int a = -C[i] - D[j];
            auto lb = std::lower_bound(AB, AB + n * n, a);
            auto ub = std::upper_bound(AB, AB + n * n, a);
            if (lb != ub)
                ans += ub - lb;
        }
    }
    std::cout << ans << '\n';
}
