#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void sell(vector<int>& parent, vector<int>& answer, int idx, int amount) {
    if (idx == 0  || amount == 0) {
        return;
    }
    int give = amount / 10;
    int mine = amount - give;
    answer[idx - 1] += mine;
    sell(parent, answer, parent[idx], give);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size());
    unordered_map<string, int> m;
    vector<int> parent(enroll.size() + 1);
    int idx = 1; // center is 0
    for (auto& s : enroll) {
        m[s] = idx++;
    }
    idx = 1;
    for (auto& s : referral) {
        if (s == "-") parent[idx++] = 0;
        else {
            parent[idx++] = m[s];
        }
    }
    idx = 0;
    for (auto& s : seller) {
        sell(parent, answer, m[s], amount[idx++] * 100);
    }
    return answer;
}