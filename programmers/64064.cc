#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool match(const string& bid, const string& uid) {
    if (bid.size() != uid.size()) return false;
    for (int i = 0; i < bid.size(); ++i) {
        if (bid[i] != '*' && bid[i] != uid[i]) return false;
    }
    return true;
}

void dfs(const vector<string> &user_id, const vector<string> &banned_id, int idx, int bitmask, unordered_set<int>& visited) {
    if (idx == banned_id.size()) {
        if (visited.find(bitmask) != visited.end()) return;
        visited.insert(bitmask);
        return;
    }
    for (int i = 0; i < user_id.size(); ++i) {
        if (bitmask & (1 << i)) continue;
        if (match(banned_id[idx], user_id[i])) {
            dfs(user_id, banned_id, idx + 1, bitmask | (1 << i), visited);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    unordered_set<int> visited;
    dfs(user_id, banned_id, 0, 0, visited);
    return visited.size();
}