import unittest # testing
from index import * # algorithm import

class Test(unittest.TestCase):
    def test_equal(self):
        self.assertEqual(palindrome('aba'), True, 'palindrome(\'aba\') should be True')
        self.assertEqual(palindrome(' aba'), False, 'palindrome(\' aba\') should be False')
        self.assertEqual(palindrome('pennep'), True, 'palindrome(\'pennep\') should be True')
        self.assertEqual(palindrome('1000000001'), True, 'palindrome(\'1000000001\') should be True')

if __name__ == '__main__':
    unittest.main()