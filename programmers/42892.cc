//
// Created by jaehy on 25. 7. 22.
//

#include <string>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int xpos;
    int ypos;
    int value;
    Node* left;
    Node* right;
    Node* parent;
    Node(int xpos, int ypos, int value)
        : xpos(xpos), ypos(ypos), value(value), left(nullptr), right(nullptr), parent(nullptr) {};
};

struct compare {
    bool operator()(const Node* a, const Node* b) const {
        if (a->ypos == b->ypos) {
            return a->xpos < b->xpos;
        }
        return a->ypos < b->ypos;
    }
};

void preorder(vector<int>& vec, Node* parent) {
    if (!parent) return;
    vec.push_back(parent->value);
    preorder(vec, parent->left);
    preorder(vec, parent->right);
}

void postorder(vector<int>& vec, Node* parent) {
    if (!parent) return;
    postorder(vec, parent->left);
    postorder(vec, parent->right);
    vec.push_back(parent->value);
}

void delete_node(Node* parent) {
    if (!parent) return;
    delete_node(parent->left);
    delete_node(parent->right);
    delete parent;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    priority_queue<Node*, vector<Node*>, compare> pq;
    const int size = nodeinfo.size();
    for (int i = 0; i < size; ++i) {
        pq.push(new Node(nodeinfo[i].front(), nodeinfo[i].back(), i + 1));
    }
    Node* root = pq.top();
    pq.pop();
    while (!pq.empty()) {
        Node* temp = root;
        Node* parent = root;
        Node* new_node = pq.top();
        pq.pop();
        while (temp) {
            parent = temp;
            if (temp->xpos < new_node->xpos) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
        if (new_node->xpos > parent->xpos) {
            parent->right = new_node;
        } else {
            parent->left = new_node;
        }
        new_node->parent = parent;
    }
    vector<int> vec1, vec2;
    preorder(vec1, root);
    postorder(vec2, root);
    answer.push_back(vec1);
    answer.push_back(vec2);
    delete_node(root);
    return answer;
}