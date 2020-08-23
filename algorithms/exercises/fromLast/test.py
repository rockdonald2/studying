from unittest import main, TestCase
import types
from linkedlist import *
from index import *

class Test(TestCase):
    def test_func(self):
        self.assertEqual(type(fromLast), types.FunctionType, 'fromLast isnt a function')

    def test_v1(self):
        l = LinkedList()

        l.insertLast('a')
        l.insertLast('b')
        l.insertLast('c')
        l.insertLast('d')

        self.assertEqual(fromLast(l, 2).data, 'b', 'fromLast doesnt work with even lengths')

    def test_v2(self):
        l = LinkedList()

        l.insertLast('a')
        l.insertLast('b')
        l.insertLast('c')
        l.insertLast('d')
        l.insertLast('e')

        self.assertEqual(fromLast(l, 2).data, 'c', 'fromLast doesnt work with odd lengths')

if __name__ == '__main__':
    main()