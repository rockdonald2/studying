/*
* --- Directions
* Make up a Linked List structure.
* See directions.
*/

class Node {
    constructor(d, n = null) {
        this.data = d;
        this.next = n;
    }
}

class LinkedList {
    // constructor
    // @param none
    // @return LinkedList instance
    constructor() {
        this.head = null;
    }

    // inserts the first node, assigns it to the head property
    // if there're already Nodes inside the LinkedList, handles correctly, updating the next properties
    // @param - the data to store
    // @return - none
    insertFirst(data) {
        this.head = new Node(data, this.head);
    }

    // returns the size of a linked list
    // @param - none
    // @return - int counter
    size() {
        let counter = 0;
        let node = this.head;

        while (node) {
            counter++;
            node = node.next;
        }

        return counter;
    }

    // returns the head
    // @param - none
    // @return - Node
    getFirst() {
        return this.head;
    }

    // returns the tail
    // @param - none
    // @return - Node
    getLast() {
        let node = this.head;

        if (!node) return null;

        while (node.next) {
            node = node.next;
        }

        return node;
    }

    // empties the linked list of any nodes
    // @param - none
    // @return - none
    clear() {
        this.head = null;
    }

    // removes the head element, assigns the second Node as the new head
    // @param - none
    // @return - none
    removeFirst() {
        this.head = this.head.next;
    }
}

module.exports = {Node, LinkedList};
