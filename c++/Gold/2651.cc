//
// Created by jaehy on 25. 1. 4.
//
#include <iostream>
#include <stack>
#define MAX_SIZE 100

long long car_race(long long (&repair_shop)[MAX_SIZE+2][4], int max_distance, int shop_num){
    for (int i = 1; i < shop_num+2; i++){
        for (int j = i - 1; j >= 0; j--){
            if (repair_shop[i][0] - repair_shop[j][0] > max_distance) break;
            if (repair_shop[i][2] > repair_shop[i][1] + repair_shop[j][2]){
                repair_shop[i][2] = repair_shop[i][1] + repair_shop[j][2];
                repair_shop[i][3] = j;
            }
        }
    }
    return repair_shop[shop_num+1][2];
}
void print_visited_shop(long long (&repair_shop)[MAX_SIZE+2][4], int shop_num){
    int idx = shop_num+1;
    std::stack<long long> order;
    while (idx){
        order.push(repair_shop[idx][3]);
        idx = repair_shop[idx][3];
    }
    order.pop();
    std::cout << order.size() << '\n';
    for (;!order.empty(); order.pop())
        std::cout << order.top() << ' ';
    std::cout << '\n';
}

int main(){
    int max_distance, shop_num;
    long long dist, total_dist = 0, repair_time;
    long long max_time = 1e10;
    long long repair_shop[MAX_SIZE+2][4]; // 0 : dist, 1 : time, 2 : total_time, 3 : before_visit
    repair_shop[0][0] = 0;
    repair_shop[0][2] = 0;
    std::cin >> max_distance >> shop_num;
    for (int i = 1; i < shop_num + 2; i++){
        std::cin >> dist;
        total_dist += dist;
        repair_shop[i][0] = total_dist;
    }
    for (int i = 1; i < shop_num + 1; i++){
        std::cin >> repair_time;
        repair_shop[i][1] = repair_time;
        repair_shop[i][2] = max_time;
    }
    repair_shop[shop_num+1][1] = 0;
    repair_shop[shop_num+1][2] = max_time;
    std::cout << car_race(repair_shop, max_distance, shop_num) << '\n';
    print_visited_shop(repair_shop, shop_num);

    return 0;
}