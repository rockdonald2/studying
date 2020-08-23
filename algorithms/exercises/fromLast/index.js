const L = require('./linkedlist')
const List = L.LinkedList
const Node = L.Node

/* 
* --- Directions
* Given a linked list, return the element n spaces
* from the last node in the list. Do not call the size method
* of the linked list. Assume that n will always be less
* than the length of the list.
*/

// 1. megoldás
/* function fromLast(list, n) {
    // if the list is empty return
    if (!list.head) return;

    let slow = list.getFirst();
    let fast = list.getFirst();
    let lengthCounter = 0;

    while (fast.next && fast.next.next) {
        fast = fast.next.next;
        lengthCounter += 2;
    }

    if (fast.next && !fast.next.next) {
        lengthCounter++;
    }

    let stepsToCount = lengthCounter - n;
    let counter = 0;

    while (counter < stepsToCount) {
        slow = slow.next;
        counter++;
    }

    return slow;
} */

// 2. megoldás
function fromLast(list, n) {
    if (!list.head) return;

    let slow = list.getFirst();
    let fast = list.getFirst();

    let counter = 0;
    while (counter < n) {
        fast = fast.next;
        counter++;
    }

    while (fast.next) {
        slow = slow.next;
        fast = fast.next;
    }

    return slow;
}

module.exports = fromLast;