#include <string>
#include <vector>
#include <utility>

int solution(std::vector<int> a) {
    if (a.size() <= 1) return 0;
    int answer = 0;
    std::vector<std::pair<int, int>> count(500001); // count, index
    if (a[0] != a[1]) {
        count[a[0]] = {1, 1};
    } else {
        count[a[0]] = {0, 1};
    }
    for (int i = 1; i < a.size(); ++i) {
        if (count[a[i]].second == 0 || count[a[i]].second + 1 < i) {
            answer = std::max(answer, ++count[a[i]].first);
            count[a[i]].second = i;
        } else if (i + 1 < a.size()) {
            if (a[i] != a[i + 1]) {
                answer = std::max(answer, ++count[a[i]].first);
            }
            count[a[i]].second = i + 1;
        }
    }
    return answer << 1;
}