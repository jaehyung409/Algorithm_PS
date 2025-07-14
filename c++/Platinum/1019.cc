//
// Created by jaehy on 25. 7. 14.
//

#include <iostream>

int main () {
    long long n, temp, decade = 10;
    std::cin >> n;
    long long count[10] = {};

    for (; decade < n; decade *= 10) {
        const int quotient = n / decade;
        const int remainder = n % decade;
        const int decade_div10 = decade / 10;
        const int digit = remainder / decade_div10;
        for (int j = 0; j < 10; j++) {
            temp = (j == 0) ? quotient - 1 : quotient;
            temp *= decade_div10;
            if (j < digit) {
                temp += decade_div10;
            } else if (j == digit) {
                temp += remainder % (decade_div10) + 1;
            }
            count[j] += temp;
        }
    }
    decade = decade / 10;
    const int digit = n / decade;
    if (digit == 10) {
        count[0] += 1;
        count[1] += 1;
    }
    for (int j = 1; j < 10; j++) {
        if (j < digit) {
            count[j] += decade;
        } else if (j == digit) {
            count[j] += n % decade + 1;
        } else {
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        std::cout << count[i] << ' ';
    }
    std::cout << '\n';
}