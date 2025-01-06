//
// Created by jaehy on 25. 1. 6.
//
#include <iostream>
#include <unordered_map>
#define MAX_SIZE 100000

int main(){
    int arr[MAX_SIZE];
    int N, B, pos_B = -1, temp = 0, odd_check;
    std::unordered_map<int, int> odd;
    std::unordered_map<int, int> even;
    std::cin >> N >> B;
    for (int i = 0; i < N; i++){
        std::cin >> arr[i];
        if (pos_B != -1) {
            if (odd_check) {
                if (arr[i] < B) odd[--temp]++;
                else odd[++temp]++;
            }
            else {
                if (arr[i] < B) even[--temp]++;
                else even[++temp]++;
            }
            odd_check = 1 - odd_check;
        }
        if (arr[i] == B) {
            pos_B = i;
            odd_check = 1;
        }
    }
    int ans = even[0];
    odd_check = 1;
    temp = 0;
    for (int i = pos_B-1; i >= 0; i--){
        if (odd_check){
            if (arr[i] < B) temp--;
            else temp++;
            ans += odd[-temp];
        }
        else{
            if (arr[i] < B) temp--;
            else temp++;
            ans += even[-temp];
            if (temp == 0) ans++;
        }
        odd_check = 1 - odd_check;
    }
    std::cout << ans+1 << '\n'; // add self

    return 0;
}