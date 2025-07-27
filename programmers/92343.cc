//
// Created by jaehy on 25. 7. 28.
//

#include <vector>
#include <list>
#include <algorithm>
#include <stack>

using namespace std;

int left[17] = {};
int right[17] = {};
int parent[17] = {};
bool visit[17] = {};
int answer = 0;

int find_root(int node, int wolves, stack<int>& restore, vector<int>& info) {
    while (!visit[node]) {
        visit[node] = true;
        if (info[node])
            wolves++;
        restore.push(node);
        node = parent[node];
    }
    return wolves;
}

void restore_visit(stack<int>& restore) {
    while(!restore.empty()) {
        visit[restore.top()] = false;
        restore.pop();
    }
}

void find_candidate(int node, list<int>& candidate, int sheep, vector<int>& info) {
    if (!visit[node]) {
        if (info[node]) sheep -= 1;
        else candidate.push_back(node);
    }

    if (sheep == 0) return;

    if (left[node]) {
        find_candidate(left[node], candidate, sheep, info);
    }
    if (right[node]) {
        find_candidate(right[node], candidate, sheep, info);
    }
}

int bfs(int node, int sheep, int wolves, vector<int>& info) {
    visit[node] = true;
    list<int> candidate;
    stack<int> restore;
    find_candidate(0, candidate, sheep + 1 - wolves, info);
    for (auto a : candidate) {
        int visit_wolves = find_root(a, wolves, restore, info);
        answer = max(answer, bfs(a, sheep + 1, visit_wolves, info));
        restore_visit(restore);
    }
    visit[node] = false;
    return sheep + 1;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    for (auto vec : edges) {
        parent[vec.back()] = vec.front();
        if (left[vec.front()] == 0) {
            left[vec.front()] = vec.back();
        } else {
            right[vec.front()] = vec.back();
        }
    }
    return max(bfs(0, 0, 0, info), answer);
}