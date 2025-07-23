//
// Created by jaehy on 25. 7. 23.
//

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Node {
public:
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    Node(int v) : value(v) {}
};

pair<int, int> groups(Node* node, int max_sum) {
    if (!node) return {0, 0};
    auto left = groups(node->left, max_sum);
    auto right = groups(node->right, max_sum);
    int total = left.second + right.second + node->value;
    if (total <= max_sum)
        return {left.first + right.first, total};
    if (left.second + node->value <= max_sum || right.second + node->value <= max_sum)
        return {1 + left.first + right.first, node->value + min(left.second, right.second)};
    return {2 + left.first + right.first, node->value};
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    const int size = num.size();
    Node* nodes[size];
    int minimum = 0;
    for (int i = 0; i < size; ++i) {
        nodes[i] = new Node(num[i]);
        minimum = max(minimum, num[i]);
    }
    for (int i = 0; i < size; ++i) {
        if (links[i].front() != -1) {
            nodes[i]->left = nodes[links[i].front()];
            nodes[links[i].front()]->parent = nodes[i];
        }
        if (links[i].back() != -1) {
            nodes[i]->right = nodes[links[i].back()];
            nodes[links[i].back()]->parent = nodes[i];
        }
    }
    Node* root =  nodes[size / 2];
    while (root->parent != nullptr) {
        root = root->parent;
    }
    int maximum = 10000 * size;
    while (minimum <= maximum) {
        Node* temp = root;
        int mid = (minimum + maximum) / 2;
        int max_groups = groups(temp, mid).first + 1;
        if (max_groups <= k) maximum = mid - 1;
        else minimum = mid + 1;
    }
    return minimum;
}