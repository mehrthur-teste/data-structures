#include <iostream>

struct Node {
    char val;
    Node* left;
    Node* right;
    Node(char v) : val(v), left(nullptr), right(nullptr) {}
};

void preorder(Node* root) {
    if (root) {
        std::cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        std::cout << root->val << " ";
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        std::cout << root->val << " ";
    }
}

int main() {
    // Construindo a árvore:
    //         A
    //        / \
    //       B   C
    //      / \
    //     D   E

    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');

    std::cout << "Pré-Ordem: ";
    preorder(root);    // A B D E C
    std::cout << "\n";

    std::cout << "Em-Ordem: ";
    inorder(root);     // D B E A C
    std::cout << "\n";

    std::cout << "Pós-Ordem: ";
    postorder(root);   // D E B C A
    std::cout << "\n";

    return 0;
}
