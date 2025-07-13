#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BPlusNode {
public:
    bool leaf;
    vector<int> keys;
    vector<BPlusNode*> children;
    BPlusNode* next;

    BPlusNode(bool leaf) : leaf(leaf), next(nullptr) {}
};

class BPlusTree {
public:
    BPlusNode* root;
    int t;

    BPlusTree(int t) : t(t) {
        root = new BPlusNode(true);
    }

    void insert(int key);
    void insertNonFull(BPlusNode* node, int key);
    void splitChild(BPlusNode* parent, int i);
    bool search(int key);
    void traverse();
};

void BPlusTree::insert(int key) {
    if (root->keys.size() == 2 * t - 1) {
        BPlusNode* newRoot = new BPlusNode(false);
        newRoot->children.push_back(root);
        splitChild(newRoot, 0);
        root = newRoot;
    }
    insertNonFull(root, key);
}

void BPlusTree::insertNonFull(BPlusNode* node, int key) {
    if (node->leaf) {
        node->keys.insert(lower_bound(node->keys.begin(), node->keys.end(), key), key);
    } else {
        int i = upper_bound(node->keys.begin(), node->keys.end(), key) - node->keys.begin();
        if (node->children[i]->keys.size() == 2 * t - 1) {
            splitChild(node, i);
            if (key > node->keys[i]) i++;
        }
        insertNonFull(node->children[i], key);
    }
}

void BPlusTree::splitChild(BPlusNode* parent, int i) {
    BPlusNode* node = parent->children[i];
    BPlusNode* sibling = new BPlusNode(node->leaf);

    int mid = t;

    sibling->keys.assign(node->keys.begin() + mid, node->keys.end());
    node->keys.resize(mid);

    if (!node->leaf) {
        sibling->children.assign(node->children.begin() + mid, node->children.end());
        node->children.resize(mid);
    }

    parent->keys.insert(parent->keys.begin() + i, sibling->keys[0]);
    parent->children.insert(parent->children.begin() + i + 1, sibling);

    if (node->leaf) {
        sibling->next = node->next;
        node->next = sibling;
    }
}

bool BPlusTree::search(int key) {
    BPlusNode* curr = root;
    while (!curr->leaf) {
        int i = upper_bound(curr->keys.begin(), curr->keys.end(), key) - curr->keys.begin();
        curr = curr->children[i];
    }
    return binary_search(curr->keys.begin(), curr->keys.end(), key);
}

void BPlusTree::traverse() {
    BPlusNode* curr = root;
    while (!curr->leaf)
        curr = curr->children[0];

    while (curr) {
        for (int k : curr->keys)
            cout << k << " ";
        curr = curr->next;
    }
    cout << endl;
}

// --- Teste
int main() {
    BPlusTree tree(2);
    vector<int> vals = {10, 20, 5, 6, 12, 30, 7, 17};
    for (int v : vals) tree.insert(v);

    cout << "B+ Tree folhas (sequencial): ";
    tree.traverse();

    cout << "Buscar 12: " << (tree.search(12) ? "OK\n" : "NOK\n");
    cout << "Buscar 99: " << (tree.search(99) ? "OK\n" : "NOK\n");
    return 0;
}
