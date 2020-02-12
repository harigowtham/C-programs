class node:
    def __init__(self,data):
        self.head=data
        self.left=None
        self.right=None

class tree:
    def __init__(self,data):
        self.head=None
        self.left=None
        self.right=None

    def inorder(self):
        if(self.head):
            self.inorder(self.left)
            print(self.head)
            self.inorder(self.right)

    def insert(self,data):
        if self.head:
            if data < self.head:
                if self.left is None:
                    self.left = tree(data)
                else:
                    self.left.insert(data)
            else:
                if self.right is None:
                    self.right = tree(data)
                else:
                    self.right.insert(data)
        else:
            self.head = tree(data)


if __name__=='__main__':
    ttree = tree(None)
    ttree.insert(1)
    ttree.insert(2)
    ttree.insert(3)
    #ttree.head = node(1)
    #ttree.head.left = node(2)
    #ttree.head.right = node(3)

    ttree.inorder()

