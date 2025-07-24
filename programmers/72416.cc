//
// Created by jaehy on 25. 7. 24.
//

#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void post_order(int node, vector<vector<int>>& tree, vector<int> &ret) {
    for (auto a : tree[node]) {
        post_order(a, tree, ret);
    }
    ret.push_back(node);
}

int solution(vector<int> sales, vector<vector<int>> links) {
    const int size = sales.size();
    vector<vector<int>> tree(size + 1);
    vector<pair<int, int>> dp(size + 1); // front : O, back : X
    for (auto vec : links) {
        tree[vec.front()].push_back(vec.back());
    }
    vector<int> post_order_tree;
    post_order(1, tree, post_order_tree);
    for (auto num : post_order_tree) {
        int no = INT_MAX, yes = 0;
        for (auto child : tree[num]) {
            int temp = dp[child].first;
            for (auto another : tree[num]) {
                if (child == another) continue;
                temp += min(dp[another].first, dp[another].second);
            }
            no = min(no, temp);
            yes += min(dp[child].first, dp[child].second);
        }
        if (no == INT_MAX) { // no children
            dp[num].first = sales[num - 1];
            dp[num].second = 0;
        } else {
            dp[num].first = yes + sales[num - 1];
            dp[num].second = no;
        }
    }
    return min(dp[1].first, dp[1].second);
}