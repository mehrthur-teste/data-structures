#include <iostream>
#include <vector>
using namespace std;

class BTreeNode {
public:
    vector<int> keys;
    vector<BTreeNode*> children;
    bool leaf;
    int t;

    BTreeNode(int t, bool leaf) : t(t), leaf(leaf) {}

    void insertNonFull(int key);
    void splitChild(int i);
    bool search(int key);
    void traverse();
};

class BTree {
public:
    BTreeNode* root;
    int t;

    BTree(int _t) : t(_t) {
        root = new BTreeNode(t, true);
    }

    void insert(int key);
    bool search(int key) {
        return root->search(key);
    }

    void traverse() {
        root->traverse();
        cout << endl;
    }
};

void BTree::insert(int key) {
    if (root->keys.size() == 2 * t - 1) {
        BTreeNode* newRoot = new BTreeNode(t, false);
        newRoot->children.push_back(root);
        newRoot->splitChild(0);
        root = newRoot;
    }
    root->insertNonFull(key);
}

void BTreeNode::insertNonFull(int key) {
    int i = keys.size() - 1;
    if (leaf) {
        keys.push_back(0);
        while (i >= 0 && key < keys[i]) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
    } else {
        while (i >= 0 && key < keys[i])
            i--;
        i++;
        if (children[i]->keys.size() == 2 * t - 1) {
            splitChild(i);
            if (key > keys[i]) i++;
        }
        children[i]->insertNonFull(key);
    }
}

void BTreeNode::splitChild(int i) {
    BTreeNode* y = children[i];
    BTreeNode* z = new BTreeNode(t, y->leaf);
    z->keys.assign(y->keys.begin() + t, y->keys.end());
    y->keys.resize(t - 1);

    if (!y->leaf) {
        z->children.assign(y->children.begin() + t, y->children.end());
        y->children.resize(t);
    }

    children.insert(children.begin() + i + 1, z);
    keys.insert(keys.begin() + i, y->keys[t - 1]);
}

bool BTreeNode::search(int key) {
    int i = 0;
    while (i < keys.size() && key > keys[i]) i++;
    if (i < keys.size() && keys[i] == key) return true;
    if (leaf) return false;
    return children[i]->search(key);
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (!leaf) children[i]->traverse();
        cout << keys[i] << " ";
    }
    if (!leaf) children[i]->traverse();
}

// --- Teste
int main() {
    BTree tree(2); // grau mínimo t = 2
    vector<int> vals = {10, 20, 5, 6, 12, 30, 7, 17};
    for (int v : vals) tree.insert(v);

    cout << "B-Tree in-order: ";
    tree.traverse();

    cout << "Buscar 12: " << (tree.search(12) ? "OK\n" : "NOK\n");
    cout << "Buscar 99: " << (tree.search(99) ? "OK\n" : "NOK\n");
    return 0;
}
