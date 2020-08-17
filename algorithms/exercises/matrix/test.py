from unittest import main, TestCase
from index import *

class Test(TestCase):
    def test_returnvalue(self):
        self.assertIsInstance(matrix(2), list, 'Matrix returns a list')

    def test_v1(self):
        lists = matrix(2)

        self.assertEqual(lists[0], [1, 2], 'matrix(2)[0] --> [1, 2]')
        self.assertEqual(lists[1], [4, 3], 'matrix(2)[1] --> [4, 3]')

    def test_v2(self):
        lists = matrix(3)

        self.assertEqual(lists[0], [1, 2, 3], 'matrix(3)[0] --> [1, 2, 3]')
        self.assertEqual(lists[1], [8, 9, 4], 'matrix(3)[1] --> [8, 9, 4]')
        self.assertEqual(lists[2], [7, 6, 5], 'matrix(3)[2] --> [7, 6, 5]')

    def test_v3(self):
        lists = matrix(4)

        self.assertEqual(lists[0], [1, 2, 3, 4], 'matrix(4)[0] --> [1, 2, 3, 4]')
        self.assertEqual(lists[1], [12, 13, 14, 5], 'matrix(4)[1] --> [12, 13, 14, 5]')
        self.assertEqual(lists[2], [11, 16, 15, 6], 'matrix(4)[2] --> [11, 16, 15, 6]')
        self.assertEqual(lists[3], [10, 9, 8, 7], 'matrix(4)[3] --> [10, 9, 8, 7]')

if __name__ == '__main__':
    main()