#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> max_h;
    priority_queue<int, vector<int>, greater<>> min_h;
    unordered_multiset<int> elem;
    for (auto str : operations) {
        int num = stoi(str.substr(1));
        if (str[0] == 'I') {
            min_h.push(num);
            max_h.push(num);
            elem.insert(num);
        } else if (str[0] == 'D' && num == 1) {
            while (!max_h.empty()) {
                int del = max_h.top();
                if (elem.find(del) == elem.end()) {
                    max_h.pop();
                    continue;
                }
                elem.erase(del);
                max_h.pop();
                break;
            }
        } else if (str[0] == 'D' && num == -1) {
            while (!min_h.empty()) {
                int del = min_h.top();
                if (elem.find(del) == elem.end()) {
                    min_h.pop();
                    continue;
                }
                elem.erase(del);
                min_h.pop();
                break;
            }
        }
    }
    int minimum = 0, maximum = 0;
    while (!min_h.empty()) {
        int cand = min_h.top();
        if (elem.find(cand) == elem.end()) {
            min_h.pop();
            continue;
        }
        minimum = cand;
        break;
    }
    while (!max_h.empty()) {
        int cand = max_h.top();
        if (elem.find(cand) == elem.end()) {
            max_h.pop();
            continue;
        }
        maximum = cand;
        break;
    }
    return vector<int>{maximum, minimum};
}