#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int expand(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }

    return right - left - 1;
}

int solution(string s) {
    int answer = 0;
    const int size = s.size();

    for (int mid = size / 2; mid < size; ++mid) {
        int bound = size - mid - 1;
        if (((bound << 1) + 2) <= answer) break;

        int len1 = expand(s, mid, mid);
        int len2 = expand(s, mid, mid + 1);
        answer = max({answer, len1, len2});
    }
    for (int mid = size / 2 - 1; mid >= 0; --mid) {
        if (((mid << 1) + 2) <= answer) break;

        int len1 = expand(s, mid, mid);
        int len2 = expand(s, mid, mid + 1);
        answer = max({answer, len1, len2});
    }
    return answer ? answer : 1;
}