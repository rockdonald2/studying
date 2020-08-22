from unittest import main, TestCase
from index import *

class Test(TestCase):
    def test_class_defined(self):
        l = LinkedList()
        n = Node('a', None)

        self.assertIsInstance(l, LinkedList, 'LinkedList is a class')
        self.assertIsInstance(n, Node, 'Node is a class')

    def test_node_properties(self):
        n = Node('a', None)
        
        self.assertEqual(n.data, 'a', 'Node has a property called data')
        self.assertIsNone(n.next, 'Node has a property called next')

    def test_insert_first(self):
        l = LinkedList()

        try:
            l.insertFirst(1)
            self.assertEqual(l.head.data, 1, '1: insertFirst sets head to node with data 1')
            l.insertFirst(2)
            self.assertEqual(l.head.data, 2, '2: insertFirst sets head to node with data 2')
            l.insertFirst(3)
            self.assertEqual(l.head.data, 3, '3: insertFirst sets head to node with data 3')
        except:
            self.fail('An error occurred, insertFirst isn\'t defined')

    def test_size(self):
        l = LinkedList()

        try: 
            l.insertFirst(1)
            self.assertEqual(l.head.data, 1, '1: insertFirst sets head to node with data 1')
            l.insertFirst(2)
            self.assertEqual(l.head.data, 2, '2: insertFirst sets head to node with data 2')
            l.insertFirst(3)
            self.assertEqual(l.head.data, 3, '3: insertFirst sets head to node with data 3')
            l.insertFirst(4)
            self.assertEqual(l.head.data, 4, '4: insertFirst sets head to node with data 4')
            self.assertEqual(l.head.next.data, 3, '5: after inserting the previous node with data 4, the next node has data of 3' )
            self.assertEqual(l.size(), 4, '6: size correctly returns 4 after inserting 4 nodes')
        except:
            self.fail('An error occurred, insertFirst/size isn\'t defined')

    def test_get_first(self):
        l = LinkedList()

        try:
            l.insertFirst(1)
            self.assertEqual(l.getFirst().data, 1, '1: returns the correct head with data 1')
            l.insertFirst(2)
            self.assertEqual(l.getFirst().data, 2, '2: return the correct head with data 2')
        except:
            self.fail('An error occurred, insertFirst\'/getFirst isn\'t defined')

    def test_get_last(self):
        l = LinkedList()

        try:
            l.insertFirst(2)
            self.assertEqual(l.getLast().data, 2, '1: returns the correct tail with data 2')
            l.insertFirst(1)
            self.assertEqual(l.getLast().data, 2, '2: return the correct tail with data 2')
        except:
            self.fail('An error occurred, insertFirst\'/getLast isn\'t defined')

    def test_clear(self):
        l = LinkedList()

        try:
            self.assertEqual(l.size(), 0, '1: Before adding any Nodes to the list, the size is 0')
            l.insertFirst(1)
            self.assertEqual(l.getFirst().data, 1, '2: returns the correct head with data 1')
            l.insertFirst(2)
            self.assertEqual(l.getFirst().data, 2, '3: return the correct head with data 2')
            self.assertEqual(l.size(), 2, '4: Size returns the correct size')
            l.clear()
            self.assertEqual(l.head, None, '5: Clear successfully clears the list')
            self.assertEqual(l.size(), 0, '6: After the clearing the size is 0')
        except:
            self.fail('An error occurred, insertFirst\'/clear/size isn\'t defined')

    def test_remove_first(self):
        try:
            l = LinkedList()
            
            l.insertFirst('a')
            l.removeFirst()
            self.assertEqual(l.size(), 0)
            self.assertEqual(l.getFirst(), None)
        except:
            self.fail('removeFirst cannot remove the first node when the size is 1')

        try:
            l = LinkedList()

            l.insertFirst('c')
            l.insertFirst('b')
            l.insertFirst('a')
            l.removeFirst()
            self.assertEqual(l.size(), 2)
            self.assertEqual(l.getFirst().data, 'b')
            l.removeFirst()
            self.assertEqual(l.size(), 1)
            self.assertEqual(l.getFirst().data, 'c')
        except:
            self.fail('removeFirst cannot remove the first node when there\'re multiple nodes in the list')

        try:
            l = LinkedList()

            l.removeFirst()
        except:
            self.fail('removeFirst crashes when the list is empty')

    def test_remove_last(self):
        try:
            l = LinkedList()

            l.removeLast()
        except:
            self.fail('An error occurred, removeLast failed when list is empty')

        try:
            l = LinkedList()

            l.insertFirst('a')
            l.removeLast()
            self.assertEqual(l.getFirst(), None)
        except:
            self.fail('An error occurred, removeLast failed when size is 1')

        try:
            l = LinkedList()

            l.insertFirst('b')
            l.insertFirst('a')
            self.assertEqual(l.getLast().data, 'b')
            l.removeLast()
            self.assertEqual(l.getLast().data, 'a')
        except:
            self.fail('An error occurred, removeLast failed when size is 2')

        try:
            l = LinkedList()

            l.insertFirst('c')
            l.insertFirst('b')
            l.insertFirst('a')
            l.removeLast()
            self.assertEqual(l.size(), 2)
            self.assertEqual(l.getLast().data, 'b')
        except:
            self.fail('An error occurred, removeLast failed when size is 3')

    def test_insert_last(self):
        l = LinkedList()

        try:
            l.insertFirst('a')
            l.insertLast('b')

            self.assertEqual(l.size(), 2)
            self.assertEqual(l.getLast().data, 'b')
        except:
            self.fail('InsertLast didn\'t add the new node at the end')

    def test_get_at(self):
        l = LinkedList()

        try:
            l.insertLast(1)
            l.insertLast(2)
            l.insertLast(3)
            l.insertLast(4)

            self.assertEqual(l.getAt(0).data, 1)
            self.assertEqual(l.getAt(1).data, 2)
            self.assertEqual(l.getAt(2).data, 3)
            self.assertEqual(l.getAt(3).data, 4)
        except:
            self.fail('getAt didn\' returned the correct node')

    def test_remove_at(self):
        try:
            l = LinkedList()
            l.removeAt(0)
            l.removeAt(1)
        except:
            self.fail('removeAt crashed when list is empty')

        try:
            l = LinkedList()
            l.insertFirst('a')
            l.removeAt(1)
        except:
            self.fail('removeAt crashed on an index out of bounds')

        try:
            l = LinkedList()
            l.insertLast(1)
            l.insertLast(2)
            l.insertLast(3)
            l.insertLast(4)
            self.assertEqual(l.getAt(0).data, 1)
            l.removeAt(0)
            self.assertEqual(l.getAt(0).data, 2)
        except:
            self.fail('removeAt didn\'t delete correctly the first node')

        try:
            l = LinkedList()
            l.insertLast(1)
            l.insertLast(2)
            l.insertLast(3)
            l.insertLast(4)
            self.assertEqual(l.size(), 4)
            self.assertEqual(l.getAt(2).data, 3)
            l.removeAt(2)
            self.assertEqual(l.getAt(2).data, 4)
        except:
            self.fail('removeAt didn\'t delete correctly the node at a given index')

        try:
            l = LinkedList()
            l.insertLast(1)
            l.insertLast(2)
            l.insertLast(3)
            l.insertLast(4)
            self.assertEqual(l.getAt(3).data, 4)
            l.removeLast()
            self.assertEqual(l.getAt(3), None)

        except:
            self.fail('removeAt didn\'t delete correctly the last node')

    def test_insert_at(self):
        try:
            l = LinkedList()
            l.insertAt('hi', 0)
            self.assertEqual(l.getFirst().data, 'hi')
        except:
            self.fail('insertAt didn\'t insert a new node with data at the 0 index when the list was empty')

        try:
            l = LinkedList()
            l.insertLast('a')
            l.insertLast('b')
            l.insertLast('c')
            l.insertAt('hi', 0)
            self.assertEqual(l.getAt(0).data, 'hi')
            self.assertEqual(l.getAt(1).data, 'a')
            self.assertEqual(l.getAt(2).data, 'b')
            self.assertEqual(l.getAt(3).data, 'c')
        except:
            self.fail('insertAt didn\'t insert a new node at the 0 index when the list had elements')

        try:
            l = LinkedList()
            l.insertLast('a')
            l.insertLast('b')
            l.insertLast('c')
            l.insertLast('d')
            l.insertAt('hi', 2)
            self.assertEqual(l.getAt(0).data, 'a')
            self.assertEqual(l.getAt(1).data, 'b')
            self.assertEqual(l.getAt(2).data, 'hi')
            self.assertEqual(l.getAt(3).data, 'c')
            self.assertEqual(l.getAt(4).data, 'd')
        except:
            self.fail('insertAt didn\'t insert correctly a new node at a specified index')

        try:
            l = LinkedList()
            l.insertLast('a')
            l.insertLast('b')
            l.insertAt('hi', 2)
            self.assertEqual(l.getAt(0).data, 'a')
            self.assertEqual(l.getAt(1).data, 'b')
            self.assertEqual(l.getAt(2).data, 'hi')
        except:
            self.fail('insertAt didn\'t insert correctly a new node at the tail')

        try:
            l = LinkedList()
            l.insertLast('a')
            l.insertLast('b')
            l.insertAt('hi', 30)
            self.assertEqual(l.getAt(0).data, 'a')
            self.assertEqual(l.getAt(1).data, 'b')
            self.assertEqual(l.getAt(2).data, 'hi')
        except:
            self.fail('insertAt didn\'t insert correctly a new node when the given index is out of bounds')

    def test_for_each(self):
        def incrementEachNodeBy10(node):
            node.data += 10

        try:
            l = LinkedList()
            l.insertLast(1)
            l.insertLast(2)
            l.insertLast(3)
            l.insertLast(4)
            l.forEach(incrementEachNodeBy10)
            self.assertEqual(l.getAt(0).data, 11)
            self.assertEqual(l.getAt(1).data, 12)
            self.assertEqual(l.getAt(2).data, 13)
            self.assertEqual(l.getAt(3).data, 14)
        except:
            self.fail('forEach didn\'t applied a transform to each node')

    def test_iterable(self):
        try:
            l = LinkedList()
            l.insertLast(1)
            l.insertLast(2)
            l.insertLast(3)
            l.insertLast(4)

            for n in l:
                n.data += 10

            self.assertEqual(l.getAt(0).data, 11)
            self.assertEqual(l.getAt(1).data, 12)
            self.assertEqual(l.getAt(2).data, 13)
            self.assertEqual(l.getAt(3).data, 14)
        except:
            self.fail('For in operator doesn\'t work with linked lists')
        

if __name__ == '__main__':
    main()