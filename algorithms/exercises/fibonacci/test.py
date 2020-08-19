from unittest import main, TestCase
import sys
import logging
from index import *

logger = logging.getLogger()
logger.level = logging.INFO

class Test(TestCase):
    def test_returnvalue(self):
        self.assertIsInstance(fib(1), int, 'Fib returns an int')

    def test_v1(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        temp = fib(0)
        self.assertEqual(temp, 0, 'Fib returns correct value')
        logger.info('test_v1 returns: {}'.format(temp))

        logger.removeHandler(streamHandler)

    def test_v2(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        temp = fib(3)
        self.assertEqual(temp, 2, 'Fib returns correct value')
        logger.info('test_v2 returns: {}'.format(temp))

        logger.removeHandler(streamHandler)

    def test_v3(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        temp = fib(39)
        self.assertEqual(temp, 63245986, 'Fib returns correct value')
        logger.info('test_v3 returns: {}'.format(temp))

        logger.removeHandler(streamHandler)

    def test_v4(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        temp = fib(10)
        self.assertEqual(temp, 55, 'Fib returns correct value')
        logger.info('test_v4 returns: {}'.format(temp))

        logger.removeHandler(streamHandler)

    def test_v5(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        temp = fib(20)
        self.assertEqual(temp, 6765, 'Fib returns correct value')
        logger.info('test_v5 returns: {}'.format(temp))

        logger.removeHandler(streamHandler)

    def test_v6(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        temp = fib(13)
        self.assertEqual(temp, 233, 'Fib returns correct value')
        logger.info('test_v6 returns: {}'.format(temp))

        logger.removeHandler(streamHandler)

if __name__ == '__main__':
    main()