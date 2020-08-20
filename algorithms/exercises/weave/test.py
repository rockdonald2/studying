from unittest import main, TestCase
from index import *
from queue import *

class Test(TestCase):
    def test_peek(self):
        q = Queue()
        q.add(1)
        q.add(2)

        self.assertEqual(q.peek(), 1, 'Peek returns the last element of the queue, but doesn\'t remove it')
        self.assertEqual(q.remove(), 1, 'Peek returns the last element of the queue, but doesn\'t remove it')
        self.assertEqual(q.peek(), 2, 'Peek returns the last element of the queue, but doesn\'t remove it')
        self.assertEqual(q.remove(), 2, 'Peek returns the last element of the queue, but doesn\'t remove it')

    def test_returnvalue(self):
        one = Queue()
        one.add(1)
        one.add(2)

        two = Queue()
        two.add(1)
        two.add(2)

        result = weave(one, two)
        self.assertIsInstance(result, Queue, 'Weave returns a Queue')

    def test_v1(self):
        one = Queue()
        one.add(1)
        one.add(2)

        two = Queue()
        two.add('Hi')
        two.add('There')

        result = weave(one, two)
        self.assertEqual(result.remove(), 1, 'Weaves can combine two queues')
        self.assertEqual(result.remove(), 'Hi', 'Weaves can combine two queues')
        self.assertEqual(result.remove(), 2, 'Weaves can combine two queues')
        self.assertEqual(result.remove(), 'There', 'Weaves can combine two queues')
        self.assertEqual(result.remove(), None, 'Weaves can combine two queues')

    def test_v2(self):
        one = Queue()
        one.add(1)
        one.add(2)

        two = Queue()
        two.add('Hi')

        result = weave(one, two)
        self.assertEqual(result.remove(), 1, 'Weaves can combine two queues with different lengths')
        self.assertEqual(result.remove(), 'Hi', 'Weaves can combine two queues with different lengths')
        self.assertEqual(result.remove(), 2, 'Weaves can combine two queues with different lengths')
        self.assertEqual(result.remove(), None, 'Weaves can combine two queues with different lengths')

if __name__ == '__main__':
    main()
