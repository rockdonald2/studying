from inspect import signature
import types

class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

class LinkedListIterator:
    def __init__(self, LinkedListInstance):
        self._node = LinkedListInstance.head

    def __next__(self):
        if self._node:
            prev = self._node
            self._node = self._node.next
            return prev
        else:
            raise StopIteration

class LinkedList:
    def __init__(self):
        self.head = None

    """ 
    Making linked lists iterable
    """
    
    def __iter__(self):
        return LinkedListIterator(self)

    """ 
    Inserts a node as head
    @param any - data to be inserted
    @return none
    """

    def insertFirst(self, data):
        self.head = Node(data, self.head)

    """ 
    Returns the size of a list
    @param none
    @return int
    """

    def size(self):
        counter = 0
        node = self.head

        while node:
            counter += 1
            node = node.next

        return counter

    """ 
    Returns the head
    @param none
    @return Node
    """

    def getFirst(self):
        return self.head

    """
    Returns the tail
    @param none
    @return Node
    """

    def getLast(self):
        node = self.head

        if not node:
            return None

        while node.next:
            node = node.next

        return node

    """ 
    Clears the list
    @param none
    @return none
    """

    def clear(self):
        self.head = None

    """ 
    Removes the first node
    @param none
    @return none
    """

    def removeFirst(self):
        if not self.head:
            return

        self.head = self.head.next

    """ 
    Removes the last node
    @param none
    @return none
    """

    def removeLast(self):
        if not self.head:
            return

        if not self.head.next:
            self.head = None
            return

        node = self.getAt(self.size() - 2)
        node.next = None

    """ 
    Inserts a node at the tail
    @param data
    @return none
    """

    def insertLast(self, data):
        node = self.getLast()

        if not node:
            self.insertFirst(data)
        else:
            node.next = Node(data)

    """ 
    Gets the node at a specified index
    @param int index
    @return Node
    """

    def getAt(self, index):
        counter = 0
        node = self.head

        if not node:
            return None

        while node:
            if counter == index:
                return node

            node = node.next
            counter += 1

        return None

    """ 
    Removes a node at a specified index
    @param int index
    @return none
    """

    def removeAt(self, index):
        if not self.head:
            return

        if index == 0:
            self.head = self.head.next
            return

        node = self.getAt(index - 1)
        if node and node.next:
            node.next = node.next.next

    """ 
    Inserts a new node at a specified index
    @param data, int index
    @return none
    """

    def insertAt(self, data, index):
        if not self.head or index == 0:
            self.insertFirst(data)

        node = self.getAt(index - 1)
        if node and node.next:
            node.next = Node(data, node.next)
        else:
            self.insertLast(data)

    """ 
    calls the provided function with each node
    @param function 
    @return none
    """

    def forEach(self, callback):
        node = self.head
        counter = 0

        if not isinstance(callback, types.FunctionType):
            raise Exception('Provided argument is not a callable function')

        params = len(signature(callback).parameters)
        if 0 >= params >= 3:
            raise Exception('Only two arguments can be used, node and index')

        while node:
            if params == 1:
                callback(node)
            elif params == 2:
                callback(node, counter)
            node = node.next
            counter += 1