#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    if (s < n) return vector<int>{ -1 };
    int small = s / n;
    int big_n = s - small * n;
    vector<int> answer(n);
    fill_n(answer.begin(), n - big_n, small);
    fill(answer.begin() + n - big_n, answer.end(), small + 1);
    return answer;
}