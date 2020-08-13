from unittest import TestCase
from unittest.mock import patch
from unittest import main
from index import *
from io import StringIO
import sys
import logging

logger = logging.getLogger()
logger.level = logging.INFO

class Test(TestCase):
    def test_return_length(self):
        with patch('sys.stdout', new = StringIO()) as fake_out:
            n = 5
            fizzBuzz(n);
            assertLength = n
            self.assertEqual(len(fake_out.getvalue().split()), 5, 'Calling fizzbuzz with 5 prints out 5 statements')

    def test_return_values_with5(self):
        stream_handler = logging.StreamHandler(sys.stdout)
        logger.addHandler(stream_handler)

        with patch('sys.stdout', new = StringIO()) as fake_out:
            n = 5
            fizzBuzz(n)
            printedValues = fake_out.getvalue().split()
            self.assertEqual(printedValues[0], '1', 'Calling fizzbuzz with 5 return correct values')
            self.assertEqual(printedValues[1], '2', 'Calling fizzbuzz with 5 return correct values')
            self.assertEqual(printedValues[2], 'fizz', 'Calling fizzbuzz with 5 return correct values')
            self.assertEqual(printedValues[3], '4', 'Calling fizzbuzz with 5 return correct values')
            self.assertEqual(printedValues[4], 'buzz', 'Calling fizzbuzz with 5 return correct values')

            try:
                logger.info('Test 2 returned values: {}'.format(printedValues))
            finally:
                logger.removeHandler(stream_handler)

    def test_return_values_with15(self):
        stream_handler = logging.StreamHandler(sys.stdout)
        logger.addHandler(stream_handler)

        with patch('sys.stdout', new = StringIO()) as fake_out:
            n = 15
            fizzBuzz(n)
            printedValues = fake_out.getvalue().split()
            self.assertEqual(printedValues[0], '1', 'Calling fizzbuzz with 15 return correct values')
            self.assertEqual(printedValues[1], '2', 'Calling fizzbuzz with 15 return correct values')
            self.assertEqual(printedValues[2], 'fizz', 'Calling fizzbuzz with 15 return correct values')
            self.assertEqual(printedValues[3], '4', 'Calling fizzbuzz with 15 return correct values')
            self.assertEqual(printedValues[4], 'buzz', 'Calling fizzbuzz with 15 return correct values')
            self.assertEqual(printedValues[5], 'fizz', 'Calling fizzbuzz with 15 return correct values')
            self.assertEqual(printedValues[6], '7', 'Calling fizzbuzz with 15 return correct values')
            self.assertEqual(printedValues[7], '8', 'Calling fizzbuzz with 15 return correct values')
            self.assertEqual(printedValues[8], 'fizz', 'Calling fizzbuzz with 15 return correct values')
            self.assertEqual(printedValues[9], 'buzz', 'Calling fizzbuzz with 15 return correct values')
            self.assertEqual(printedValues[10], '11', 'Calling fizzbuzz with 15 return correct values')
            self.assertEqual(printedValues[11], 'fizz', 'Calling fizzbuzz with 15 return correct values')
            self.assertEqual(printedValues[12], '13', 'Calling fizzbuzz with 15 return correct values')
            self.assertEqual(printedValues[13], '14', 'Calling fizzbuzz with 15 return correct values')
            self.assertEqual(printedValues[14], 'fizzbuzz', 'Calling fizzbuzz with 15 return correct values')

            try:
                logger.info('Test 3 returned values: {}'.format(printedValues))
            finally:
                logger.removeHandler(stream_handler)

if __name__ == '__main__':
    main()