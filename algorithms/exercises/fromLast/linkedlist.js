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
    /* constructor
     * @param none
     * @return LinkedList instance
     */
    constructor(values = []) {
        this.head = null;

        for (const v of values) {
            this.insertLast(v);
        }
    }

    /* inserts the first node, assigns it to the head property
    if there're already Nodes inside the LinkedList, handles correctly, updating the next properties
    * @param - the data to store
    * @return - none 
    */
    insertFirst(data) {
        this.head = new Node(data, this.head);
    }

    /* returns the size of a linked list
     * @param - none
     * @return - int counter 
     */
    size() {
        let counter = 0;
        let node = this.head;

        while (node) {
            counter++;
            node = node.next;
        }

        return counter;
    }

    /* returns the head
     * @param - none
     * @return Node 
     */
    getFirst() {
        return this.head;
    }

    /* returns the tail
     * @param - none 
     * @return Node
     */
    getLast() {
        let node = this.head;

        // there are no nodes
        if (!node) return null;

        while (node.next) {
            node = node.next;
        }

        return node;
    }

    /* empties the linked list of any nodes
     * @param - none
     * @return - none 
     */
    clear() {
        this.head = null;
    }

    /* removes the head element, assigns the second Node as the new head
     * @param - none
     * @return - none
     */
    removeFirst() {
        this.head = this.head.next;
    }

    /* removes the last Node from a linked list
     * @param - none
     * @return - none
     */
    removeLast() {
        let node = this.head;

        // there are no nodes
        if (!node) return;
        // there are only one node
        if (!node.next) {
            this.head = null;
            return;
        }

        while (node.next.next) {
            node = node.next;
        }

        node.next = null;
    }

    /* insert a new node at the end of a linked list
     * @param - data to be inserted
     * @return - none
     */
    insertLast(data) {
        let node = this.getLast();

        if (!node) {
            this.insertFirst(data);
            return;
        }

        node.next = new Node(data);
    }

    /* returns the node at a provided index
     * @param - integer index
     * @return - Node 
     */
    getAt(index) {
        let counter = 0;
        let node = this.head;

        // search for the index
        while (node) {
            if (counter === index) return node;

            node = node.next;
            counter++;
        }

        // if there's no such index, return null
        return null;
    }

    /* removes a node at a provided index
     * @param - integer index
     * @return - none 
     */
    removeAt(index) {
        if (!this.head) return;

        if (index === 0) {
            this.head = this.head.next;
            return;
        }

        let node = this.getAt(index - 1);
        if (node && node.next) {
            node.next = node.next.next;
            return;
        }
    }

    /* creates a new node with the provided data, at the specified index
    if index is out of bounds appends it to the end
    * @param - data to be inserted and integer index
    * @return - none 
    */
    insertAt(data, index) {
        // if the list is empty make it the head
        // if the provided index is 0
        // then make it the head with a next property set to the previous head
        if (!this.head || index === 0) {
            this.insertFirst(data);
            return;
        }

        // search for the provided index
        // if we're one position back than the specified index to be inserted at
        // make a new Node with a next property of the previous Node's next, 
        // then append it to the previous Node's next property
        let node = this.getAt(index - 1);
        if (node) {
            node.next = new Node(data, node.next);
            return;
        }

        // if index isn't found, than append it to the end
        this.insertLast(data);
    }

    /* calls the provided function with every node of the list
     * @param - function to be called
     * @return - none 
     */
    forEach(callback) {
        let node = this.head;
        let counter = 0;

        if (!node) return;

        while (node) {
            callback(node, counter);
            node = node.next;
            counter++;
        }
    }

    *[Symbol.iterator]() {
        let node = this.head;

        while (node) {
            yield node;
            node = node.next;
        }
    }
}

module.exports = {
    Node,
    LinkedList
};