from stack import *

class Queue():
    def __init__(self):
        self.stackStorage = Stack()
        self.stackQueue = Stack()

    def add(self, record):
        while self.stackQueue.peek():
            self.stackStorage.push(self.stackQueue.pop())

        self.stackStorage.push(record)

        while self.stackStorage.peek():
            self.stackQueue.push(self.stackStorage.pop())

    def remove(self):
        return self.stackQueue.pop()

    def peek(self):
        return self.stackQueue.peek()