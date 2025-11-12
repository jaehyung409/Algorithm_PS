#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

pair<int, int> convert(string& s) {
    int time = stoi(s.substr(11,2));
    int min = stoi(s.substr(14,2));
    int sec = stoi(s.substr(17,2));
    int ms = stoi(s.substr(20,3));
    int dur = round(stod(s.substr(24, s.size() - 25)) * 1000);

    int end_time_ms = (time * 3600 + min * 60 + sec) * 1000 + ms;

    return {end_time_ms, dur};
}

int solution(vector<string> lines) {
    priority_queue<int> heap;
    int count = 0;
    for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
        auto p = convert(*it);
        int cur = p.first + 999;
        int start = p.first - p.second + 1;
        while (!heap.empty() && heap.top() > cur) {
            heap.pop();
        }
        heap.push(start);
        count = max(count, static_cast<int>(heap.size()));
    }
    return count;
}