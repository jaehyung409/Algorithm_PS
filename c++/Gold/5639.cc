//
// Created by jaehy on 25. 7. 11..
//

#include <iostream>

struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int value;

    explicit Node(int value) : left(nullptr), right(nullptr), parent(nullptr), value(value) {}
};

void traverse(Node* node) {
    if (node == nullptr)
        return;
    traverse(node->left);
    traverse(node->right);
    std::cout << node->value << '\n';
}

void erase_node(Node* node) {
    if (node == nullptr)
        return;
    erase_node(node->left);
    erase_node(node->right);
    delete node;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int value;
    std::cin >> value;
    Node* root = new Node(value);
    Node* current = root;
    while (std::cin >> value) {
        if (value < current->value) {
            Node* temp = new Node(value);
            current->left = temp;
            temp->parent = current;
            current = temp;
        } else {
            while (current->parent != nullptr && current->parent->value < value) {
                current = current->parent;
            }
            Node* temp = new Node(value);
            while (current->right != nullptr) {
                current = current->right;
            }
            current->right = temp;
            temp->parent = current;
            current = temp;
        }
    }
    traverse(root);
    erase_node(root);
}