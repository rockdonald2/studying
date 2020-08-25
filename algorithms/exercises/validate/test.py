from unittest import main, TestCase
from node import *
from index import *

class Test(TestCase):
    def test_v1(self):
        n = Node(10)
        n.insert(5)
        n.insert(15)
        n.insert(0)
        n.insert(20)

        self.assertTrue(validate(n), 'Validate recognizes a valid BST')

    def test_v2(self):
        n = Node(10)
        n.insert(5)
        n.insert(15)
        n.insert(0)
        n.insert(20)
        n.left.left.right = Node(999);

        self.assertFalse(validate(n), 'Validate recognizes an invalid BST')

if __name__ == '__main__':
    main()