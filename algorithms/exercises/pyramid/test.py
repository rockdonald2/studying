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
        self.assertIsNone(pyramid(2), 'Pyramid should not return anything')

    def test_v1(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        try:
            with patch('sys.stdout', new = StringIO()) as fake_out:
                pyramid(1)

                printedMsg = fake_out.getvalue().split('\n')
                self.assertEqual(printedMsg[0], '#', 'Pyramid n = 1')
                self.assertEqual(len(printedMsg) - 1, 1, 'Pyramid n = 1')

                logging.info('\ttest_v1 returns: {}'.format(printedMsg[:-1]));

        finally:
            logger.removeHandler(streamHandler)

    def test_v2(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        try:
            with patch('sys.stdout', new = StringIO()) as fake_out:
                pyramid(2)

                printedMsg = fake_out.getvalue().split('\n')
                self.assertEqual(printedMsg[0], ' # ', 'Pyramid n = 2')
                self.assertEqual(printedMsg[1], '###', 'Pyramid n = 2')
                self.assertEqual(len(printedMsg) - 1, 2, 'Pyramid n = 2')

                logging.info('\ttest_v2 returns: {}'.format(printedMsg[:-1]));

        finally:
            logger.removeHandler(streamHandler)

    def test_v3(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        try:
            with patch('sys.stdout', new = StringIO()) as fake_out:
                pyramid(3)

                printedMsg = fake_out.getvalue().split('\n')
                self.assertEqual(printedMsg[0], '  #  ', 'Pyramid n = 3')
                self.assertEqual(printedMsg[1], ' ### ', 'Pyramid n = 3')
                self.assertEqual(printedMsg[2], '#####', 'Pyramid n = 3')
                self.assertEqual(len(printedMsg) - 1, 3, 'Pyramid n = 3')

                logging.info('\ttest_v3 returns: {}'.format(printedMsg[:-1]));

        finally:
            logger.removeHandler(streamHandler)

if __name__ == '__main__':
    main()
