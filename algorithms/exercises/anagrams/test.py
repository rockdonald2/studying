from unittest import main, TestCase
from index import *

class Test(TestCase):
    def test_returnvalue(self):
        self.assertIsInstance(anagrams('hello', 'olleeeh'), bool, 'Anagrams returns a boolean value')

    def test_v1(self):
        self.assertTrue(anagrams('hello', 'olleh'), '"hello" is an anagram of "olleh"')

    def test_v2(self):
        self.assertFalse(anagrams('One one', 'One one c'), '"One one" is not an anagram of "One one c"')

    def test_v3(self):
        self.assertTrue(anagrams('Whoa! Hi!', 'Hi! Whoa!'), '"Whoa! Hi!" is an anagram of "Hi! Whoa!"')

    def test_v4(self):
        self.assertFalse(anagrams('One One', 'Two two two'), '"One One" is not an anagram of "Two two two"')

    def test_v5(self):
        self.assertFalse(anagrams('A tree, a life, a bench', 'A tree, a fence, a yard'), '"A tree, a life, a bench" is not an anagram of "A tree, a fence, a yard"')

    def test_v6(self):
        self.assertTrue(anagrams('RAIL SAFETY!', 'fairy tales'), '"RAIL SAFETY!" is an anagram of "fairy tales"')
    
    def test_v7(self):
        self.assertFalse(anagrams('Hi there!', 'Bye there!'), '"Hi there!" is not an anagram of "Bye there!"')

if __name__ == '__main__':
    main()