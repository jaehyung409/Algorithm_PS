//
// Created by jaehy on 24. 11. 13.
//
#include <iostream>

typedef std::pair<double,double> DD;
double triangle_area(DD &A, DD &B, DD &C){
    DD AB = DD(B.first - A.first, B.second - A.second);
    DD AC = DD(C.first - A.first, C.second - A.second);
    return (AB.first * AC.second - AB.second * AC.first) / 2.0;
}

int main(){
    int N;
    DD pos_0, pos_A, pos_B;
    double ans = 0.0;
    std::cin >> N;
    std::cin >> pos_0.first >> pos_0.second;
    std::cin >> pos_A.first >> pos_A.second;
    for(int i = 2; i < N; i++){
        std::cin >> pos_B.first >> pos_B.second;
        ans += triangle_area(pos_0, pos_A, pos_B);
        pos_A = pos_B;
    }
    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << std::abs(ans) << '\n';

    return 0;
}