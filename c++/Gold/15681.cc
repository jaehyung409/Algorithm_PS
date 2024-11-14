//
// Created by jaehy on 24. 11. 14.
//
#include <iostream>
#include <vector>

struct Node{
    std::vector<Node*> link;
    std::vector<Node*> children;
    Node *parent = nullptr;
    int sub_vertex = 1;
    Node() = default;
    int get_suv() {
        for (const auto child : this->children){
            sub_vertex += child->get_suv();
        }
        return sub_vertex;
    }
};

void make_tree(Node *current, Node *parent){
    for (auto sub : current->link){
        if (sub != parent){
            current->children.push_back(sub);
            sub->parent = current;
            make_tree(sub, current);
        }
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, R, Q, ver_a, ver_b, i;
    std::cin >> N >> R >> Q;
    std::vector<Node> nodes(N + 1);
    for (i = 0; i < N - 1; i++){
        std::cin >> ver_a >> ver_b;
        nodes[ver_a].link.push_back(&nodes[ver_b]);
        nodes[ver_b].link.push_back(&nodes[ver_a]);
    }
    make_tree(&nodes[R], nullptr);
    nodes[R].get_suv();
    for (i = 0; i < Q; i++){
        std::cin >> ver_a;
        std::cout << nodes[ver_a].sub_vertex << '\n';
    }
}