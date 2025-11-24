#include <string>
#include <vector>

using namespace std;

bool pass(vector<int>& stones, int num, int k) {
    int count = 0;
    for (auto a : stones) {
        if (a <= num) {
            if (++count == k) {
                return false;
            }
        } else {
            count = 0;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int low = 0, high = 200000001;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (pass(stones, mid, k)) low = mid + 1;
        else high = mid;
    }
    return low;
}