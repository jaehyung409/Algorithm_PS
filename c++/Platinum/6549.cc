//
// Created by jaehy on 24. 11. 11.
//
#include <iostream>
#include <algorithm>
#define MAX_SIZE 100000

long long merge_histogram(int low, int mid, int high, int (&histogram)[MAX_SIZE]){
    long long length = std::min(histogram[mid], histogram[mid+1]);
    long long width = 0;
    long long area = 0;
    int i = mid, j = mid + 1;
    while(i >= low || j <= high) {
        for (; i >= low && histogram[i] >= length; i--) width++;
        for (; j <= high && histogram[j] >= length; j++) width++;
        area = std::max(area, length * width);
        if (j == high + 1) length = histogram[i];
        else if (i == low - 1) length = histogram[j];
        else length = std::max(histogram[i], histogram[j]);
    }
    return area;
}
long long max_rectangle_in_histogram(const int size, int low, int high, int (&histogram)[MAX_SIZE]){
    if (low == high) return histogram[low];
    int mid = (low + high) / 2;
    long long left_max = max_rectangle_in_histogram(size, low, mid, histogram);
    long long right_max = max_rectangle_in_histogram(size, mid + 1, high, histogram);
    long long merge_max = merge_histogram(low, mid, high, histogram);
    return std::max({left_max, merge_max, right_max});
}

int main(){
    int N, i;
    int histogram[MAX_SIZE];

    while (true){
        std::cin >> N;
        if (N == 0) break;
        for (i = 0; i < N; i++) std::cin >> histogram[i];
        std::cout << max_rectangle_in_histogram(N, 0, N-1, histogram) << '\n';
    }

    return 0;
}