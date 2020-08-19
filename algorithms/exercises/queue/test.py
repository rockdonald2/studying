from unittest import main, TestCase
from index import *

class Test(TestCase):
    def test_class(self):
        temp = Queue()
        self.assertIsInstance(temp, Queue, 'Queue is a class')

    def test_add(self):
        temp = Queue()
        
        try:
            temp.add(1)
            temp.remove()
        except:
            self.fail('Queue methods raised an exception')

    def test_remove(self):
        temp = Queue()

        try:
            temp.add(1)
            self.assertEqual(temp.remove(), 1, 'Queue method remove removes the first element in the queue and returns it')
            self.assertEqual(temp.remove(), None, 'Queue method remove returns None if removing from an empty Queue')
        except:
            self.fail('Queue methods raised an exception')

    def test_first(self):
        temp = Queue()

        try:
            temp.add(1)
            temp.add(2)
            temp.add(3)
            self.assertEqual(temp.first(), 1, 'Queue getter first correctly returns the first element in the Queue')
            temp.remove()
            temp.remove()
            temp.remove()
            self.assertEqual(temp.first(), None, 'Queue getter first returns None if the Queue is empty')
        except:
            self.fail('Queue methods raised an exception')

if __name__ == '__main__':
    main()