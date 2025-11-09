#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const vector<int>& lhs, const vector<int>& rhs) {
    return lhs.back() < rhs.back();
}

int find(vector<int>& disjoint, int x) {
    if (disjoint[x] == x)
        return x;
    
    disjoint[x] = find(disjoint, disjoint[x]);
    return disjoint[x];
}

void unions(vector<int>& disjoint, int x, int y) {
    x = find(disjoint, x);
    y = find(disjoint, y);
    disjoint[x] = y;
} 

int solution(int n, vector<vector<int>> costs) {
    vector<int> disjoint;
    disjoint.reserve(n);
    for (int i = 0; i < n; ++i) disjoint.push_back(i);

    int answer = 0;
    
    sort(costs.begin(), costs.end(), comp);
    int edge = 0;
    for (auto& vec : costs) {
        if (find(disjoint, vec[0]) != find(disjoint, vec[1])) {
            answer += vec[2];
            unions(disjoint, vec[0], vec[1]);
            if (++edge == n - 1) break;
        }
    }
    return answer;
}