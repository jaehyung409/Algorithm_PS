#include <iostream>
#include <algorithm>
/* <dynamic programming>
 * Red -> min of n-1 (Green, Blue)
 * Green -> min of n-1 (Red, Blue)
 * Blue -> min of n-1 (Red, Green) */
int RGB[] = {0, 1, 2};
int arr[1002][3];

int main(){
    int N;
    std::cin >> N;
    for(int i = 0; i < N; ++i){
        for(const auto& n : RGB)
            std::cin >> arr[i][n];
    }
    int cost_RGB[] = {arr[0][0], arr[0][1], arr[0][2]};
    for(int i = 1; i < N; ++i){
        int tmp[3];
        std::fill_n(tmp, 3, 0);
        for(const auto& n : RGB){
            for(const auto& a : RGB){
                if(a == n) continue;
                if(!tmp[n]) tmp[n] = cost_RGB[a] + arr[i][n];
                else tmp[n] = std::min(tmp[n], cost_RGB[a] + arr[i][n]);
            }
        }
        std::swap(tmp, cost_RGB);
    }
    std::cout << *std::min_element(cost_RGB, cost_RGB + 3) << std::endl;

    return 0;
}