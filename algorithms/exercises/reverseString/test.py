import unittest
from index import *

class Test(unittest.TestCase):
    def test_equal(self):
        self.assertEqual(reverseString('aba'), 'aba', 'Should be equal \'aba\'')
        self.assertEqual(reverseString('abcd'), 'dcba', 'Should be equal \'dcba\'')
        self.assertEqual(reverseString('apple'), 'elppa', 'Should be equal \'elppa\'')

    def test_type(self):
        self.assertIsInstance(reverseString('apple'), str, 'Returned value should be of type string')

if __name__ == '__main__':
    unittest.main()