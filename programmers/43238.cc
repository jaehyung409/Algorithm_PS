#include <string>
#include <vector>
#include <limits>

using namespace std;

long long solution(int n, vector<int> times) {
    long long low = 1, high = std::numeric_limits<long long>::max() - 2;
    while (low < high) {
        long long mid = (low + high) / 2;
        long long can = 0;
        for (auto t : times) {
            can += mid / t;
            if (can >= n) break;
        }
        if (can >= n) high = mid;
        else low = mid + 1;
    }
    return low;
}