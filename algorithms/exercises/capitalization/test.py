from unittest import main, TestCase
from unittest.mock import patch
from index import *
import sys
import logging
from io import StringIO

logger = logging.getLogger()
logger.level = logging.INFO

class Test(TestCase):
    def test_returnvalue(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        returnType = capitalize('hello there')
        logger.info('test_returnvalue returns: {}'.format(returnType))
        self.assertIsInstance(returnType, str, 'Capitalize returns a string')

        logger.removeHandler(streamHandler)

    def test_v1(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        returnValue = capitalize('hello there')
        logger.info('test_v1 returns: {}'.format(returnValue))
        self.assertEqual(returnValue, 'Hello There', 'Capitalizes the first letter of each word')

        logger.removeHandler(streamHandler)

    def test_v2(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        returnValue = capitalize('i love breakfast at bill miller bbq')
        logger.info('test_v2 returns: {}'.format(returnValue))
        self.assertEqual(returnValue, 'I Love Breakfast At Bill Miller Bbq', 'Capitalizes the first letter of each word')

        logger.removeHandler(streamHandler)

    def test_v3(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        returnValue = capitalize('a short sentence')
        logger.info('test_v3 returns: {}'.format(returnValue))
        self.assertEqual(returnValue, 'A Short Sentence', 'Capitalizes the first letter of each word')

        logger.removeHandler(streamHandler)

    def test_v4(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        returnValue = capitalize('the quick brown fox jumps over the lazy dog')
        logger.info('test_v4 returns: {}'.format(returnValue))
        self.assertEqual(returnValue, 'The Quick Brown Fox Jumps Over The Lazy Dog', 'Capitalizes the first letter of each word')

        logger.removeHandler(streamHandler)

    def test_v5(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        returnValue = capitalize('hurry up!')
        logger.info('test_v5 returns: {}'.format(returnValue))
        self.assertEqual(returnValue, 'Hurry Up!', 'Capitalizes the first letter of each word with symbols')

        logger.removeHandler(streamHandler)

if __name__ == '__main__':
    main()