class BTreeNode:
    def __init__(self, t, leaf=False):
        self.t = t  # Grau mínimo (mínimo de filhos por nó não-raiz)
        self.keys = []
        self.children = []
        self.leaf = leaf

    def insert_non_full(self, key):
        i = len(self.keys) - 1

        if self.leaf:
            self.keys.append(0)
            while i >= 0 and key < self.keys[i]:
                self.keys[i + 1] = self.keys[i]
                i -= 1
            self.keys[i + 1] = key
        else:
            while i >= 0 and key < self.keys[i]:
                i -= 1
            i += 1
            if len(self.children[i].keys) == 2 * self.t - 1:
                self.split_child(i)
                if key > self.keys[i]:
                    i += 1
            self.children[i].insert_non_full(key)

    def split_child(self, i):
        t = self.t
        y = self.children[i]
        z = BTreeNode(t, y.leaf)

        z.keys = y.keys[t:]
        y.keys = y.keys[:t - 1]

        if not y.leaf:
            z.children = y.children[t:]
            y.children = y.children[:t]

        self.children.insert(i + 1, z)
        self.keys.insert(i, y.keys.pop())

    def search(self, key):
        i = 0
        while i < len(self.keys) and key > self.keys[i]:
            i += 1

        if i < len(self.keys) and key == self.keys[i]:
            return True
        if self.leaf:
            return False
        return self.children[i].search(key)

    def traverse(self):
        for i in range(len(self.keys)):
            if not self.leaf:
                self.children[i].traverse()
            print(self.keys[i], end=" ")
        if not self.leaf:
            self.children[-1].traverse()


class BTree:
    def __init__(self, t):
        self.root = BTreeNode(t, True)
        self.t = t

    def insert(self, key):
        root = self.root
        if len(root.keys) == 2 * self.t - 1:
            new_root = BTreeNode(self.t, False)
            new_root.children.append(self.root)
            new_root.split_child(0)
            self.root = new_root

        self.root.insert_non_full(key)

    def search(self, key):
        return self.root.search(key)

    def traverse(self):
        self.root.traverse()
        print()
        
        
# Testando a B-Tree
if __name__ == "__main__":  
    btree = BTree(3)  # Grau mínimo 3
    keys = [10, 20, 5, 6, 12, 30, 7, 17]
    
    for key in keys:
        btree.insert(key)

    print("Árvore B após inserções:")
    btree.traverse()  # Deve imprimir os valores na ordem correta

    print("Busca por 12:", btree.search(12))  # True
    print("Busca por 99:", btree.search(99))  # False
    # A saída deve ser:
    # Árvore B após inserções: 5 6 7 10 12 17 20 30
    # Busca por 12: True
