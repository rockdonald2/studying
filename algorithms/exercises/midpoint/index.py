from linkedlist import *

def midpoint(list):
    slow = list.head
    fast = list.head

    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next

    return slow