const L = require('./linkedlist');
const Node = L.Node;
const LinkedList = L.LinkedList;

/* 
* --- Directions
* Return the middle node of a linked list,
* if the list has an even number of elements, return the node
* at the end of the first half of the list
* do not use a counter variable, do not retrieve the size of a list,
* and only iterate through the list one time 
*/

function midpoint(list) {
    let slow = list.getFirst();
    let fast = list.getFirst();

    while (fast.next && fast.next.next) {
        slow = slow.next;
        fast = fast.next.next;
    }

    return slow;
}

module.exports = midpoint;