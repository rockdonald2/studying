class Node:
    def __init__(self, data):
        self.data = data
        self.children = []

    def add(self, data):
        self.children.append(Node(data))

    def remove(self, data):
        self.children = list(filter(lambda c: c.data != data, self.children))

class Tree:
    def __init__(self):
        self.root = None

    def traverseBF(self, fn):
        arr = [self.root]

        while len(arr):
            curr = arr.pop(0)

            arr.extend(curr.children)

            fn(curr)

    def traverseDF(self, fn):
        arr = [self.root]
        
        while len(arr):
            curr = arr.pop(0)

            arr = curr.children + arr

            fn(curr)