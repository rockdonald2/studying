from queue import *

def weave(sourceOne, sourceTwo):
    q = Queue()

    while sourceOne.peek() != None or sourceTwo.peek() != None:
        if sourceOne.peek():
            q.add(sourceOne.remove())
        if sourceTwo.peek():
            q.add(sourceTwo.remove())

    return q