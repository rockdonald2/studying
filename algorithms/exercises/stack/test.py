from unittest import main, TestCase
from index import *

class Test(TestCase):
    def test_returnvalue(self):
        s = Stack()
        self.assertIsInstance(s, Stack, 'Stack is a class')

    def test_v1(self):
        s = Stack()

        try:
            s.push(1)
            s.push(2)
            s.push(3)
        except:
            self.fail('Stack doesn\'t have a push method')

        self.assertEqual(s.peek(), 3, 'Stack has a peek method')
        self.assertEqual(s.pop(), 3, 'Stack has a pop method')
        self.assertEqual(s.pop(), 2, 'Stack has a pop method')
        self.assertEqual(s.pop(), 1, 'Stack has a pop method')
        self.assertEqual(s.pop(), None, 'Stack has a pop method')

    def test_v2(self):
        s = Stack()

        try:
            s.push(1)
        except:
            self.fail('Stack doesn\'t have a push method')

        self.assertEqual(s.peek(), 1, 'Stack has a peek method')
        
        try:
            s.push(2)
        except:
            self.fail('Stack doesn\'t have a push method')

        self.assertEqual(s.peek(), 2, 'Stack has a peek method')
    
    def test_v3(self):
        s = Stack()

        try:
            s.push(1)
            s.push(2)
            s.push(3)
        except:
            self.fail('Stack doesn\'t have a push method')

        self.assertEqual(s.peek(), 3, 'Stack has a peek method')
        self.assertEqual(s.pop(), 3, 'Stack has a pop method')
        self.assertEqual(s.peek(), 2, 'Stack has a peek method')
        self.assertEqual(s.pop(), 2, 'Stack has a pop method')
        self.assertEqual(s.peek(), 1, 'Stack has a peek method')
        self.assertEqual(s.pop(), 1, 'Stack has a pop method')


if __name__ == '__main__':
    main()