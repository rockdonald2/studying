from unittest import main, TestCase
import types
from linkedlist import *
from index import *

class Test(TestCase):
    def test_fn(self):
        try:
            self.assertEqual(type(midpoint), types.FunctionType, 'midpoint isn\'t a function')
        except:
            self.fail('midpoint isn\'t a function')

    def test_odd(self):
        try:
            l = LinkedList()
            l.insertLast(1)
            l.insertLast(2)
            l.insertLast(3)
            mp = midpoint(l)
            self.assertEqual(mp.data, 2)

            l.clear()

            l.insertLast(1)
            l.insertLast(2)
            l.insertLast(3)
            l.insertLast(4)
            l.insertLast(5)
            l.insertLast(6)
            l.insertLast(7)
            mp = midpoint(l)
            self.assertEqual(mp.data, 4)
        except:
            self.fail('midpoint doesn\'t work on odd lists')

    def test_even(self):
        try:
            l = LinkedList()
            l.insertLast(1)
            l.insertLast(2)
            l.insertLast(3)
            l.insertLast(4)
            mp = midpoint(l)
            self.assertEqual(mp.data, 2)

            l.clear()

            l.insertLast(1)
            l.insertLast(2)
            l.insertLast(3)
            l.insertLast(4)
            l.insertLast(5)
            l.insertLast(6)
            mp = midpoint(l)
            self.assertEqual(mp.data, 3)
        except:
            self.fail('midpoint doesn\'t work on even lists')

if __name__ == '__main__':
    main()