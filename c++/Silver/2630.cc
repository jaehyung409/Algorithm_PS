//
// Created by jaehy on 25. 5. 10.
//
#include <iostream>
#include <vector>

int white = 0, blue = 0;

int quad_tree(int x_begin, int y_begin, const int size, std::vector<std::vector<int>>& arr) {
    if (size == 1) return arr[x_begin][y_begin];
    int child[4];
    child[0] = quad_tree(x_begin, y_begin, size/2, arr);
    child[1] = quad_tree(x_begin + size/2, y_begin, size/2, arr);
    child[2] = quad_tree(x_begin, y_begin + size/2, size/2, arr);
    child[3] = quad_tree(x_begin + size/2, y_begin + size/2, size/2, arr);
    int temp_w = 0, temp_b = 0, sum = 0;
    for (int i = 0; i < 4; ++i) {
        if (child[i] == size * size / 4) temp_b++;
        if (child[i] == 0) temp_w++;
        sum += child[i];
    }
    if (temp_w != 4 && temp_b != 4) {
        white += temp_w;
        blue += temp_b;
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int size;
    std::cin >> size;
    std::vector<std::vector<int>> arr(size, std::vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            std::cin >> arr[i][j];
    }
    int null_check = quad_tree(0, 0, size, arr);
    if (!white && !blue) (null_check == 0) ? white++ : blue++;
    std::cout << white << '\n' << blue << '\n';
}
