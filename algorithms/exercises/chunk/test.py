from unittest import TestCase
from unittest.mock import patch
from unittest import main
import sys
import logging
from index import *
from io import StringIO

logger = logging.getLogger()
logger.level = logging.INFO

class Test(TestCase):
    def test_return_type(self):
        self.assertIsInstance(chunk([1, 2, 3], 1), list, 'Chunk returns a value of type list')

    def test_v1(self):
        stream_handler = logging.StreamHandler(sys.stdout)
        logger.addHandler(stream_handler)

        try:
            chunked = chunk([1, 2, 3], 1)
            logger.info('Test returns values: {}'.format(chunked))

            self.assertEqual(chunked, [[1], [2], [3]], 'Chunk successfully divides an array of length 3 into 1 sized chunkes')
        finally:
            logger.removeHandler(stream_handler)

    def test_v2(self):
        stream_handler = logging.StreamHandler(sys.stdout)
        logger.addHandler(stream_handler)

        try:
            chunked = chunk([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 2)
            logger.info('Test returns values: {}'.format(chunked))

            self.assertEqual(chunked, [[1, 2], [3, 4], [5, 6], [7, 8], [9, 10]], 'Chunk successfully divides an array of length 10 into 2 sized chunks')
        finally:
            logger.removeHandler(stream_handler)

    def test_v3(self):
        stream_handler = logging.StreamHandler(sys.stdout)
        logger.addHandler(stream_handler)

        try:
            chunked = chunk([1, 2, 3, 4, 5], 3)
            logger.info('Test returns values: {}'.format(chunked))
            
            self.assertEqual(chunked, [[1, 2, 3], [4, 5]], 'Chunk successfully divides an array of length 5 into 3 sized chunks')
        finally:
            logger.removeHandler(stream_handler)

    def test_v4(self):
        stream_handler = logging.StreamHandler(sys.stdout)
        logger.addHandler(stream_handler)

        try:
            chunked = chunk([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13], 5)
            logger.info('Test returns values: {}'.format(chunked))

            self.assertEqual(chunked, [[1, 2, 3, 4, 5], [6, 7, 8, 9, 10], [11, 12, 13]], 'Chunked successfully divides an array of length 13 into 5 sized chunks')
        finally:
            logger.removeHandler(stream_handler)

    def test_badinput(self):
        stream_handler = logging.StreamHandler(sys.stdout)
        logger.addHandler(stream_handler)

        try:
            with patch('sys.stdout', new = StringIO()) as fake_out:
                chunked = chunk([], 1)
                chunked = chunk(None, 1)
                chunked = chunk([1, 2, 3], -1)

                printedMsg = fake_out.getvalue().split('\n')
                logger.info('Test printed values: {}'.format(printedMsg))

                self.assertEqual(printedMsg[0], 'Bad input', 'Chunk should handle bad input')
                self.assertEqual(printedMsg[1], 'Bad input', 'Chunk should handle bad input')
                self.assertEqual(printedMsg[2], 'Bad input', 'Chunk should handle bad input')

        finally:
            logger.removeHandler(stream_handler)

if __name__ == "__main__":
    main()