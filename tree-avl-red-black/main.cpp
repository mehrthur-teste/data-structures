#include <iostream>
#include <algorithm>
using namespace std;

struct AVLNode {
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

// Função para obter altura de um nó
int height(AVLNode* node) {
    return node ? node->height : 0;
}

// Atualiza altura do nó
void updateHeight(AVLNode* node) {
    if (node)
        node->height = 1 + max(height(node->left), height(node->right));
}

// Cálculo do balanceamento
int getBalance(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Rotação à direita
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Rotação à esquerda
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Inserção em árvore AVL
AVLNode* avl_insert(AVLNode* root, int key) {
    if (!root)
        return new AVLNode(key);

    if (key < root->key)
        root->left = avl_insert(root->left, key);
    else
        root->right = avl_insert(root->right, key);

    updateHeight(root);
    int balance = getBalance(root);

    // Casos de balanceamento
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Busca em árvore AVL
AVLNode* avl_search(AVLNode* root, int key) {
    if (!root || root->key == key)
        return root;
    if (key < root->key)
        return avl_search(root->left, key);
    return avl_search(root->right, key);
}

// Travessia em ordem para debug
void inOrder(AVLNode* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// Main: teste
int main() {
    AVLNode* root = nullptr;
    int values[] = {10, 20, 30, 40, 50, 25};
    for (int v : values)
        root = avl_insert(root, v);

    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;

    int searchKey = 25;
    AVLNode* result = avl_search(root, searchKey);
    if (result)
        cout << "Encontrado: " << result->key << endl;
    else
        cout << "Não encontrado\n";

    return 0;
}
