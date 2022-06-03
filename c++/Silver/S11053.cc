#include <iostream>
#include <algorithm>

int main(){
    int sizeA, length = 0;
    std::cin >> sizeA;
    int arr[sizeA];
    int ans[sizeA];
    for(int i = 0; i < sizeA; ++i)
        std::cin >> arr[i];
    for(int i = 0; i < sizeA; ++i){
        int max = 0;
        for(int j = i - 1; j >= 0; --j){
            if(arr[i] > arr[j]) max = std::max(max,ans[j]);
        }
        ans[i] = max + 1;
        length = std::max(length, ans[i]);
    }
    std::cout << length << std::endl;
    return 0;
}