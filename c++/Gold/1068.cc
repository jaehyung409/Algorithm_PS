//
// Created by jaehy on 25. 3. 22.
//
#include <iostream>
#include <vector>

int bfs(std::vector<std::vector<int>> &tree, int node, int erased) {
    if (node == erased) return 0;
    int count = 0;
    if (tree[node].empty()) return 1;
    if (tree[node].size() == 1 && tree[node].front() == erased) return  1;
    for (const auto child : tree[node]) {
        count += bfs(tree, child, erased);
    }
    return count;
}

int main() {
    int node_num, root, erased;
    std::cin >> node_num;
    std::vector<std::vector<int>> tree(node_num);
    std::vector<int> root_nodes;
    for (int i = 0; i < node_num; ++i) {
        std::cin >> root;
        if (root == -1) root_nodes.push_back(i);
        else {
            tree[root].push_back(i);
        }
    }
    int count = 0;
    std::cin >> erased;
    for (auto node : root_nodes) {
        count += bfs(tree, node, erased);
    }
    std::cout << count << '\n';
}