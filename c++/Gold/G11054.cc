#include <iostream>
#include <algorithm>

int main(){
    int sizeA, length = 0;
    std::cin >> sizeA;
    int arr[sizeA];
    int ans_right[sizeA];
    int ans_left[sizeA];
    for(int i = 0; i < sizeA; ++i)
        std::cin >> arr[i];
    for(int i = 0; i < sizeA; ++i){
        int left = 0, right = 0;
        for(int j = i - 1; j >= 0; --j){
            if(arr[i] > arr[j]) left = std::max(left, ans_left[j]);
        }
        for(int j = sizeA - i; j < sizeA; ++j){
            if(arr[sizeA - (i+1)] > arr[j]) right = std::max(right, ans_right[j]);
        }
        ans_left[i] = left + 1;
        ans_right[sizeA - (i+1)] = right + 1;
    }
    for(int i = 0; i < sizeA; ++i)
        length = std::max(length, ans_left[i] + ans_right[i]);
    std::cout << length - 1 << std::endl;
    return 0;
}