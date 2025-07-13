#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* bst_search(Node* root, int key) {
    if (!root || root->val == key) return root;
    if (key < root->val) return bst_search(root->left, key);
    else return bst_search(root->right, key);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    Node* res = bst_search(root, 7);
    if (res) cout << res->val << endl;
    else cout << "Not found" << endl;

    return 0;
}
