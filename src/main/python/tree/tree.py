class NodeBinaryTree:
    def __init__(self, root):
        self.key = root
        self.left_child = None
        self.right_child = None

    def insert_left(self, key):
        node = NodeBinaryTree(key)
        if self.left_child:
            node.left_child = self.left_child
        self.left_child = node

    def insert_right(self, key):
        node = NodeBinaryTree(key)
        if self.right_child:
            node.right_child = self.right_child
        self.right_child = node

    def get_right_child(self):
        return self.right_child

    def get_left_child(self):
        return self.left_child

    def set_root(self, key):
        self.key = key

    def get_root(self):
        return self.key

def test_node_bt():
    t = NodeBinaryTree('root')
    assert t.get_root() == 'root'
    t.insert_left(1)
    assert t.get_left_child().get_root() == 1
    t.insert_right(2)
    assert t.get_right_child().get_root() == 2
    t.insert_right(3)
    assert t.get_right_child().get_root() == 3


def preorder(tree):
    if tree:
        print(tree.get_root())
        preorder(tree.get_left_child())
        preorder(tree.get_right_child())

def midorder(tree):
    if tree:
        midorder(tree.get_left_child())
        print(tree.get_root())
        midorder(tree.get_right_child())

def postorder(tree):
    if tree:
        postorder(tree.get_left_child())
        postorder(tree.get_right_child())
        print(tree.get_root())
