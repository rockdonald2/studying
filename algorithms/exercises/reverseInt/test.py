import unittest
from index import *

class Test(unittest.TestCase):
    def test_returnvalue(self):
        self.assertIsInstance(reverseInt(1), int, 'Returns an int type')

    def test_nullcase(self):
        self.assertEqual(reverseInt(0), 0, 'Handles zero input.')

    def test_positive(self):
        self.assertEqual(reverseInt(555), 555, 'Reverses a positive integer.')
        self.assertEqual(reverseInt(15), 51, 'Reverses a positive integer.')
        self.assertEqual(reverseInt(500), 5, 'Reverses a positive integer.')
        self.assertEqual(reverseInt(85), 58, 'Reverses a positive integer.')

    def test_negative(self):
        self.assertEqual(reverseInt(-15), -51, 'Reverses a negative integer.')
        self.assertEqual(reverseInt(-85), -58, 'Reverses a negative integer.')
        self.assertEqual(reverseInt(-800), -8, 'Reverses a negative integer.')

if __name__ == '__main__':
    unittest.main()