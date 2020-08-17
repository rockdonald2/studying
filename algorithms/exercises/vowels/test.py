from unittest import main, TestCase
from unittest.mock import patch
import sys
import logging
from io import StringIO
from index import *

logger = logging.getLogger()
logger.level = logging.INFO

class Test(TestCase):
    def test_returnvalue(self):
        self.assertIsInstance(vowels('Why?'), int, 'Vowels returns an int')

    def test_v1(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        self.assertEqual(vowels('Why?'), 0, 'Vowels("Why") --> 0')
        logger.info('\tv1: {}'.format(vowels('Why?')))

        logger.removeHandler(streamHandler)

    def test_v2(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        self.assertEqual(vowels('Hi there!'), 3, 'Vowels("Hi there!") --> 3')
        logger.info('\tv2: {}'.format(vowels('Hi there!')))

        logger.removeHandler(streamHandler)

    def test_v3(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        self.assertEqual(vowels('aeiou'), 5, 'Vowels("aeiou") --> 5')
        logger.info('\tv3: {}'.format(vowels('aeiou')))

        logger.removeHandler(streamHandler)

    def test_v4(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        self.assertEqual(vowels('AEIOU'), 5, 'Vowels("AEIOU") --> 5')
        logger.info('\tv4: {}'.format(vowels('AEIOU')))

        logger.removeHandler(streamHandler)

    def test_v5(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        self.assertEqual(vowels('Hey, Thomas check this out!'), 7, 'Vowels("Hey, Thomas check this out!") --> 7')
        logger.info('\tv5: {}'.format(vowels('Hey, Thomas check this out!')))

        logger.removeHandler(streamHandler)

    def test_v6(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        self.assertEqual(vowels('abcdefghijklmnopqrstuvwxyz'), 5, 'Vowels("abcdefghijklmnopqrstuvwxyz") --> 5')
        logger.info('\tv6: {}'.format(vowels('abcdefghijklmnopqrstuvwxyz')))

        logger.removeHandler(streamHandler)

    def test_v7(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        self.assertEqual(vowels('bcdfghjkl'), 0, 'Vowels("bcdfghjkl") --> 0')
        logger.info('\tv7: {}'.format(vowels('bcdfghjkl')))

        logger.removeHandler(streamHandler)

if __name__ == '__main__':
    main()