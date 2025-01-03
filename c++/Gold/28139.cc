//
// Created by jaehy on 25. 1. 3.
//
#include <iostream>
#include <cmath>
#define MAX_SIZE 5000
typedef std::pair<double, double> dd;

double distance(dd &a, dd &b){
    double x_pos_diff = std::pow((b.first - a.first), 2);
    double y_pos_diff = std::pow((b.second - a.second), 2);
    return std::sqrt(x_pos_diff + y_pos_diff);
}

int main(){
    int N;
    dd positions[MAX_SIZE];
    double x_pos, y_pos, dist = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++){
        std::cin >> x_pos >> y_pos;
        positions[i] = std::make_pair(x_pos, y_pos);
    }
    for (int i = 0; i < N-1; i++){
        for (int j = i + 1; j < N; j++)
            dist += distance(positions[i], positions[j]);
    }
    std::cout << std::fixed;
    std::cout.precision(6);
    std::cout << (dist * 2) / N << '\n';
}