from unittest import main, TestCase
import types
from linkedlist import *
from index import *

class Test(TestCase):
    def test_func(self):
        self.assertEqual(type(circular), types.FunctionType, 'circular isnt a function')

    def test_v1(self):
        l = LinkedList()
        a = Node('a')
        b = Node('b')
        c = Node('c')
        l.head = a
        a.next = b
        b.next = c
        c.next = b

        self.assertTrue(circular(l), 'circular works with circular linked lists')

    def test_v2(self):
        l = LinkedList()
        a = Node('a')
        b = Node('b')
        c = Node('c')
        l.head = a
        a.next = b
        b.next = c
        c.next = l.head

        self.assertTrue(circular(l), 'circular works with circular linked lists')

    def test_v3(self):
        l = LinkedList()
        a = Node('a')
        b = Node('b')
        c = Node('c')
        l.head = a
        a.next = b
        b.next = c

        self.assertFalse(circular(l), 'circular works with non circular linked lists')

if __name__ == '__main__':
    main()