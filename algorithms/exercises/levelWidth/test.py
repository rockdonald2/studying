from unittest import main, TestCase
import types
from node import *
from index import *

class Test(TestCase):
    def test_func(self):
        self.assertEqual(type(levelWidth), types.FunctionType, 'levelWidth isnt a function')

    def test_v1(self):
        root = Node(0)
        root.add(1)
        root.add(2)
        root.add(3)
        root.children[0].add(4)
        root.children[2].add(5)

        self.assertEqual(levelWidth(root), [1, 3, 2], 'levelWidth returns number of nodes at widest point')

    def test_v2(self):
        root = Node(0)
        root.add(1)
        root.children[0].add(2)
        root.children[0].add(3)
        root.children[0].children[0].add(4)

        self.assertEqual(levelWidth(root), [1, 1, 2, 1], 'levelWidth returns number of nodes at widest point')

if __name__ == '__main__':
    main()