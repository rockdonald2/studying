from unittest import main, TestCase
import types
from index import *

class Test(TestCase):
    def test_node(self):
        self.assertIsInstance(Node(1), Node, 'Node is a class')

    def test_insert(self):
        try:
            node = Node(10)
            node.insert(5)
            node.insert(15)
            node.insert(17)

            self.assertEqual(node.left.data, 5)
            self.assertEqual(node.right.data, 15)
            self.assertEqual(node.right.right.data, 17)

        except:
            self.fail('Insert method doesnt exist')

    def test_contains(self):
        try:
            node = Node(10)
            node.insert(5)
            node.insert(15)
            node.insert(20)
            node.insert(0)
            node.insert(-5)
            node.insert(3)

            self.assertEqual(node.contains(3), node.left.left.right)
        except:
            self.fail('Contains method doesnt exist')

    def test_contains(self):
        try:
            node = Node(10)
            node.insert(5)
            node.insert(15)
            node.insert(20)
            node.insert(0)
            node.insert(-5)
            node.insert(3)

            self.assertEqual(node.contains(9999), None)
        except:
            self.fail('Contains method doesnt exist')


if __name__ == '__main__':
    main()