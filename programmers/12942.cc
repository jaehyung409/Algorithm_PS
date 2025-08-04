//
// Created by jaehy on 25. 8. 4.
//

#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

constexpr int INT_MAX = numeric_limits<int>::max();
int m[201][201] = {};

int solution(vector<vector<int>> matrix_sizes) {
    const int size = matrix_sizes.size();
    for (int d = 1; d < size; ++d) {
        for (int i = 0; i + d < size; ++i) {
            const int pi = matrix_sizes[i].front();
            const int j = i + d;
            const int pj = matrix_sizes[j].back();
            int minimum = INT_MAX;
            for (int k = i; k < j; ++k) {
                const int pk = matrix_sizes[k].back();
                minimum = min(minimum, m[i][k] + m[k+1][j] + pi * pk * pj);
            }
            m[i][j] = minimum;
        }
    }
    return m[0][size - 1];
}