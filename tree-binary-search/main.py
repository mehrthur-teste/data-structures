class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def bst_search(root, key):
    if root is None or root.val == key:
        return root
    if key < root.val:
        return bst_search(root.left, key)
    else:
        return bst_search(root.right, key)

# Exemplo de uso:
root = Node(10)
root.left = Node(5)
root.right = Node(15)
root.left.left = Node(3)
root.left.right = Node(7)

res = bst_search(root, 7)
print(res.val if res else "Not found")
