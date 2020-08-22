/* 
* --- Directions
* Given a linked list, return true if the list
* is circular, false otherwise.
* Circular is a linked list in which the tail points to an another node in the list
*/

function circular(list) {
    // if list is empty return false
    if (!list.head) return false;

    let slow = list.getFirst();
    let fast = list.getFirst();

    while (fast.next) {
        slow = slow.next;
        fast = fast.next.next;

        if (fast === slow) return true;
    }

    return false;
}

module.exports = circular;