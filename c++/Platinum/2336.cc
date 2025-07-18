//
// Created by jaehy on 25. 7. 17.
//

#include <iostream>
#include <tuple>
#include <algorithm>

using triple = std::tuple<int, int, int>;

void input_grades(triple students[], int n) {
    int student_id;
    for (int grades = 0; grades < n; ++grades) {
        std::cin >> student_id;
        std::get<0>(students[student_id - 1]) = grades + 1;
    }
    for (int grades = 0; grades < n; ++grades) {
        std::cin >> student_id;
        std::get<1>(students[student_id - 1]) = grades + 1;
    }
    for (int grades = 0; grades < n; ++grades) {
        std::cin >> student_id;
        std::get<2>(students[student_id - 1]) = grades + 1;
    }
}

int compare(triple& a, triple& b) {
    return std::get<0>(a) < std::get<0>(b);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    triple students[n];
    input_grades(students, n);
    std::sort(students, students + n, compare);

    int fenwick_tree[n + 1] = {};
    std::fill(fenwick_tree, fenwick_tree + n + 1, 500001);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int student_id = std::get<1>(students[i]);
        int min_grade = 500001;
        for (int j = student_id; j > 0; j -= j & -j) {
            min_grade = std::min(min_grade, fenwick_tree[j]);
        }
        for (int j = student_id; j <= n; j += j & -j) {
            fenwick_tree[j] = std::min(fenwick_tree[j], std::get<2>(students[i]));
        }
        if (min_grade == 500001 || min_grade > std::get<2>(students[i])) {
            ans++;
        }
    }
    std::cout << ans << '\n';
}