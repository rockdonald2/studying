from linkedlist import *

def circular(list):
    # if list is empty return false
    if not list.head:
        return False

    slow = list.getFirst()
    fast = list.getFirst()

    while fast.next:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:
            return True

    return False