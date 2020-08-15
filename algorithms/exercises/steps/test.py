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
        self.assertIsNone(steps(2), 'Steps should not return any value')

    def test_v1(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        try:
            with patch('sys.stdout', new = StringIO()) as fake_out:
                steps(2)

                printedMsg = fake_out.getvalue().split('\n')
                self.assertEqual(printedMsg[0], '# ', 'Steps for n = 2')
                self.assertEqual(printedMsg[1], '##', 'Steps for n = 2')

                logging.info('test_v1 returns: {}'.format(printedMsg))

        finally:
            logger.removeHandler(streamHandler)

    def test_v2(self):
        streamHandler = logging.StreamHandler(sys.stdout)
        logger.addHandler(streamHandler)

        try:
            with patch('sys.stdout', new = StringIO()) as fake_out:
                steps(4)

                printedMsg = fake_out.getvalue().split('\n')
                self.assertEqual(printedMsg[0], '#   ', 'Steps for n = 4')
                self.assertEqual(printedMsg[1], '##  ', 'Steps for n = 4')
                self.assertEqual(printedMsg[2], '### ', 'Steps for n = 4')
                self.assertEqual(printedMsg[3], '####', 'Steps for n = 4')

                logging.info('test_v2 returns: {}'.format(printedMsg))

        finally:
            logger.removeHandler(streamHandler)


if __name__ == '__main__':
    main()