class AVLNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1

def height(node):
    return node.height if node else 0

def update_height(node):
    node.height = 1 + max(height(node.left), height(node.right))

def right_rotate(y):
    x = y.left
    T2 = x.right
    x.right = y
    y.left = T2
    update_height(y)
    update_height(x)
    return x

def left_rotate(x):
    y = x.right
    T2 = y.left
    y.left = x
    x.right = T2
    update_height(x)
    update_height(y)
    return y

def get_balance(node):
    if not node:
        return 0
    return height(node.left) - height(node.right)

def avl_insert(root, key):
    if not root:
        return AVLNode(key)
    if key < root.key:
        root.left = avl_insert(root.left, key)
    else:
        root.right = avl_insert(root.right, key)

    update_height(root)
    balance = get_balance(root)

    # Left Left
    if balance > 1 and key < root.left.key:
        return right_rotate(root)

    # Right Right
    if balance < -1 and key > root.right.key:
        return left_rotate(root)

    # Left Right
    if balance > 1 and key > root.left.key:
        root.left = left_rotate(root.left)
        return right_rotate(root)

    # Right Left
    if balance < -1 and key < root.right.key:
        root.right = right_rotate(root.right)
        return left_rotate(root)

    return root

def avl_search(root, key):
    if not root or root.key == key:
        return root
    if key < root.key:
        return avl_search(root.left, key)
    return avl_search(root.right, key)

# Uso
root = None
for val in [10, 20, 30, 40, 50, 25]:
    root = avl_insert(root, val)

res = avl_search(root, 25)
print(res.key if res else "Not found")
