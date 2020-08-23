from linkedlist import *

def fromLast(list, n):
    if not list.head:
        return

    slow = list.getFirst()
    fast = list.getFirst()

    counter = 0
    while counter < n:
        fast = fast.next
        counter += 1

    while fast.next:
        slow = slow.next
        fast = fast.next

    return slow