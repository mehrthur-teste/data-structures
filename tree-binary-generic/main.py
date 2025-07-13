class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def preorder(root):
    if root:
        print(root.val, end=' ')
        preorder(root.left)
        preorder(root.right)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.val, end=' ')
        inorder(root.right)

def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.val, end=' ')

# Função principal (main)
if __name__ == "__main__":
    # Construindo a árvore:
    #         A
    #        / \
    #       B   C
    #      / \
    #     D   E

    root = Node('A')
    root.left = Node('B')
    root.right = Node('C')
    root.left.left = Node('D')
    root.left.right = Node('E')

    print("Pré-Ordem:")
    preorder(root)    # A B D E C

    print("\nEm-Ordem:")
    inorder(root)     # D B E A C

    print("\nPós-Ordem:")
    postorder(root)   # D E B C A
    # A saída deve ser:
    # Pré-Ordem: A B D E C
    # Em-Ordem: D B E A C
    # Pós-Ordem: D E B C A