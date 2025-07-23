//
// Created by jaehy on 25. 7. 20.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class node {
public:
    int value;
    int min;
    vector<int> children;
    vector<int> turn;
    int idx = 0;
};

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    node node_pool[102];
    const int size = target.size();

    int count = 0;
    for (int i = 0; i < size; ++i) {
        node_pool[i + 1].value = target[i];
        if (target[i] == 0) {
            count++;
        }
        node_pool[i + 1].min = (target[i] + 2) / 3;
    }
    for (auto a : edges) {
        node_pool[a.front()].children.push_back(a.back());
    }
    int nchildren = 0;
    for (int i = 1; i <= size; ++i) {
        sort(node_pool[i].children.begin(), node_pool[i].children.end());
        if (node_pool[i].children.empty()) {
            ++nchildren;
        }
    }
    count -= (size - nchildren);
    int i = 0;
    for (; count != nchildren; ++i) {
		int temp = 1;
        while (!node_pool[temp].children.empty()) {
            temp = node_pool[temp].children[node_pool[temp].idx++ % node_pool[temp].children.size()];
        }
        node_pool[temp].turn.push_back(i);
        int visit = node_pool[temp].turn.size();
        if (visit > node_pool[temp].value) {
            answer.resize(1,-1);
            return answer;
        }
        if (visit == node_pool[temp].min) {
            count++;
        }
    }
    answer.resize(i, 0);
    for (i = 1; i <= size; ++i) {
        int nturns = node_pool[i].turn.size();
        if (nturns) {
            for (auto it = node_pool[i].turn.rbegin(); it != node_pool[i].turn.rend(); ++it) {
                if (node_pool[i].value == nturns) {
                    node_pool[i].value -= 1;
                    answer[*it] = 1;
                } else if (node_pool[i].value == nturns + 1) {
                    node_pool[i].value -= 2;
                    answer[*it] = 2;
                } else {
                    node_pool[i].value -= 3;
                    answer[*it] = 3;
                }
                nturns--;
            }
        }
    }
    return answer;
}