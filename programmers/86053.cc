#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

bool build(long long target, int a, int b, vector<int>&g, vector<int>&s, vector<int>&w, vector<int>& t) {
    const int size = g.size();
    long long total = 0, gold = 0, silver = 0;
    for (int i = 0; i < size; ++i) {
        long long capacity = (target >= t[i]) ? (target - t[i]) / (2 * t[i]) + 1 : 0;
        capacity *= w[i];
        total += min(static_cast<long long>(g[i] + s[i]), capacity);
        gold += min(static_cast<long long>(g[i]), capacity);
        silver += min(static_cast<long long>(s[i]), capacity);
    }
    return (gold >= static_cast<long long>(a) && silver >= static_cast<long long>(b) && total >= static_cast<long long>(a + b));

}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long low = 1, high = numeric_limits<long long>::max() / 100;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (build(mid, a, b, g, s, w, t)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}