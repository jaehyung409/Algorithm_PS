#include <iostream>
#include <vector>

void swap(std::vector<int>& arr, int i, int j){
    std::vector<int> cp(arr);
    for(int a = 0; a < j - i; ++a)
        arr[i+a+1] = cp[i+a];
    arr[i] = cp[j];
}

int main(){
    int N,S;
    std::cin >> N;
    std::vector<int> A;
    for(int i = 0; i < N; ++i){
        int a;
        std::cin >> a;
        A.push_back(a);
    }
    std::cin >> S;
    for(int i = 0; i < N; ++i){
        int max_e = A[i], check = 0;
        for(int j = i + 1; j < N; ++j){
            if(j - i <= S && A[j] > max_e){
                max_e = A[j];
                check = j;
            }
        }
        if(check) {
            swap(A, i, check);
            S -= (check - i);
        }
    }
    for(int i = 0; i < N; ++i)
        std::cout << A[i] << " ";
    std::cout << std::endl;

    return 0;
}