from unittest import main, TestCase
import types
from index import *

class Test(TestCase):
    def test_node(self):
        self.assertIsInstance(Node('a'), Node, 'Node isnt a class')

    def test_node_properties(self):
        try:
            n = Node('a')
            self.assertEqual(n.data, 'a')
            self.assertEqual(n.children, [])
        except:
            self.fail('Node doesnt have data and children props')

    def test_node_add(self):
        try:
            n = Node('a')
            n.add('b')
            self.assertEqual(len(n.children), 1)
            self.assertEqual(len(n.children[0].children), 0)
        except:
            self.fail('Add method doesnt exist')

    def test_node_remove(self):
        try:
            n = Node('a')
            n.add('b')
            self.assertEqual(len(n.children), 1)
            n.remove('b')
            self.assertEqual(len(n.children), 0)
        except:
            self.fail('Remove method doesnt exist')

    def test_tree(self):
        self.assertIsInstance(Tree(), Tree, 'Tree isnt a class')
        self.assertEqual(Tree().root, None, 'Tree starts out empty')

    def test_traverse_bf(self):
        t = Tree()
        t.root = Node('a')
        t.root.add('b')
        t.root.add('c')
        t.root.children[0].add('d')

        letters = []
        def addToLetters(node):
            letters.append(node.data)

        t.traverseBF(addToLetters)

        self.assertEqual(letters, ['a', 'b', 'c', 'd'])

    def test_traverse_df(self):
        t = Tree()
        t.root = Node('a')
        t.root.add('b')
        t.root.add('d')
        t.root.children[0].add('c')

        letters = []
        def addToLetters(node):
            letters.append(node.data)

        t.traverseDF(addToLetters)

        self.assertEqual(letters, ['a', 'b', 'c', 'd'])

if __name__ == '__main__':
    main()