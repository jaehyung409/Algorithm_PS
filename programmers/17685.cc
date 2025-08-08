//
// Created by jaehy on 25. 8. 8..
//

#include <string>
#include <vector>

using namespace std;

int answer = 0;

struct Node {
    int count = 1;
    Node* children[26] = {};
    Node() = default;
};

void bfs(Node* temp) {
    answer += temp->count;
    if (temp->count == 1) return;
    for (int i = 0; i < 26; ++i) {
        if (temp->children[i]) {
            bfs(temp->children[i]);
        }
    }
}

int solution(vector<string> words) {
    Node* root = new Node();
    for (const auto& word : words) {
        Node* temp = root;
        for (const auto& a : word) {
            if (temp->children[a - 'a']) {
                ++temp->children[a - 'a']->count;
                temp = temp->children[a -'a'];
            } else {
                temp->children[a - 'a'] = new Node();
                temp = temp->children[a - 'a'];
            }
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (root->children[i]) {
            bfs(root->children[i]);
        }
    }
    return answer;
}