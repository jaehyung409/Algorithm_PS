#include <iostream>
/* Tree with struct
 * preorder ; root -> left -> right
 * inorder  ; left -> root -> right
 * postorder; left -> right -> root
 * with recursive(or stack) */

struct tree{
    tree() : left(nullptr), right(nullptr) {};
    char key;
    tree* left;
    tree* right;
};
void preorder(tree root){
    std::cout << root.key;
    if(root.left != nullptr) preorder(*root.left);
    if(root.right != nullptr) preorder(*root.right);
}
void inorder(tree root){
    if(root.left != nullptr) inorder(*root.left);
    std::cout << root.key;
    if(root.right != nullptr) inorder(*root.right);
}
void postorder(tree root){
    if(root.left != nullptr) postorder(*root.left);
    if(root.right != nullptr) postorder(*root.right);
    std::cout << root.key;
}
int main(){
    int N;
    std::cin >> N;
    tree trees[N];
    for(int i = 0; i < N; ++i) trees[i].key = 'A' + i;
    for(int i = 0; i < N; ++i){
        char root, left, right;
        std::cin >> root >> left >> right;
        if(left != '.') trees[root - 'A'].left = &trees[left - 'A'];
        if(right != '.') trees[root - 'A'].right = &trees[right - 'A'];
    }
    preorder(trees[0]);
    std::cout << std::endl;
    inorder(trees[0]);
    std::cout << std::endl;
    postorder(trees[0]);
    std::cout << std::endl;

    return 0;
}