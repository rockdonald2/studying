import unittest
from index import *

class Test(unittest.TestCase):
    def test_returnvalue(self):
        self.assertEqual(type(maxChar('aaaa')), str, 'MaxChar returns a string')
        self.assertEqual(len(maxChar('aaaa')), 1, 'MaxChar returns a value of length 1')

    def test_string(self):
        self.assertEqual(maxChar('abcdefghijklmnaaaaa'), 'a', 'Finds the most frequently used char')
        self.assertEqual(maxChar('a'), 'a', 'Finds the most frequently used char')
        self.assertEqual(maxChar('apple'), 'p', 'Finds the most frequently used char')

    def test_number(self):
        self.assertEqual(maxChar('ab1c1d1e1f1g1'), '1', 'Works with numbers in the string')

if __name__ == '__main__':
    unittest.main()