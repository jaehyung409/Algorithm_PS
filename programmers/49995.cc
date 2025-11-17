#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int sum = cookie.front(), left, total, l_pointer, temp;
    const int size = cookie.size();
    for (int i = 1; i < size; ++i) {
        sum += cookie[i];
        temp = sum;
        left = 0;
        l_pointer = 0;
        for (int j = 0; j < i; ++j) {
            left += cookie[j];
            total = left << 1;
            while (total > temp) {
                left -= cookie[l_pointer];
                temp -= cookie[l_pointer++];
                total = left << 1;
            }
            if (total == temp) {
                answer = max(answer, left);
                break;
            }
        }
    }
    return answer;
}