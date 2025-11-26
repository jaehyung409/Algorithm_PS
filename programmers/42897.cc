#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& money, int start, int end) {
    int prev = 0, pprev = 0;
    for (int i = start; i <= end; ++i) {
        int current = max(prev, pprev + money[i]);
        pprev = prev;
        prev = current;
    }
    return prev;
}

int solution(vector<int> money) {
    int answer = rob(money, 0, money.size() - 2);
    answer = max(answer, rob(money, 1, money.size() - 1));
    return answer;
}