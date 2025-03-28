//
// Created by jaehy on 25. 3. 28.
//
#include <iostream>
#include <string>

std::string  panramg = "I";  // zero input handling

void make_string(int n) {
    if (n == 0) return;
    for (int i = 0; i < n; ++i) {
        panramg.append("A");
    }
    panramg.append("BCDEFGHIJKLMNOPQRSTUVWXY");
    for (int i = 0; i < n; ++i) {
        panramg.append("Z");
    }
}

void lowerBound(int n) {
    if (n <= 1) {
        make_string(n);
        return;
    }
    int num = 1;
    while (num * num < n) {
        num++;
    }
    num--;
    lowerBound(n - num * num);
    make_string(num);
}

int main() {
    int N;
    std::cin >> N;
    lowerBound(N);
    std::cout << panramg << '\n';
}