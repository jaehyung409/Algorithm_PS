#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    const int size = a.size();
    vector<int> left(size + 1, 1000000001), right(size + 1, 1000000001);
    for (int i = 0; i < size; ++i) {
        left[i + 1] = min(left[i], a[i]);
    }
    for (int i = size - 1; i >= 0; --i) {
        right[i] = min(right[i + 1], a[i]);
    }
    int answer = 0;
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (left[i] < a[i]) ++count;
        if (right[i + 1] < a[i]) ++count;
        if (count <= 1) ++answer;
        count = 0;
    }
    return answer;
}