class Node {
    constructor(data, next = null) {
        this.data = data;
        this.next = next;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    insertFirst(data) {
        this.head = new Node(data, this.head);
    }

    size() {
        let size_counter = 0;

        let node = this.head;

        if (!node) {
            return 0;
        }

        while (node) {
            node = node.next;
            size_counter++;
        }

        return size_counter;
    }

    getFirst() {
        return this.head;
    }

    getLast() {
        let node = this.head;

        if (!node) return null;

        while (node.next) {
            node = node.next;
        }

        return node;
    }

    clear() {
        this.head = null;
    }

    removeFirst() {
        if (!this.head) return;

        this.head = this.head.next;
    }

    removeLast() {
        if (!this.head) return;

        if (!this.head.next) {
            this.head = null;
            return;
        }

        let node = this.head;

        while (node.next.next) {
            node = node.next;
        }

        node.next = null;
    }

    insertLast(data) {
        let node = this.head;

        if (!this.head) return this.insertFirst(data);

        while (node.next) {
            node = node.next;
        }

        node.next = new Node(data);
    }

    getAt(index) {
        if (!this.head) return null;

        let index_counter = 0;
        let node = this.head;

        while (node) {
            if (index_counter === index) return node;
            node = node.next;
            ++index_counter;
        }

        return null;
    }

    removeAt(index) {
        if (!this.head) return;

        if (index == 0) return this.removeFirst();

        let index_counter = 0;
        let node = this.head;

        while (node.next) {
            if ((index_counter + 1) === index) {
                node.next = node.next.next;
                return;
            } 
            node = node.next;
            ++index_counter;
        }

        return;
    }

    insertAt(data, index) {
        if (!this.head) return this.insertFirst(data);
        if (index === 0) return this.insertFirst(data);

        let index_counter = 0;
        let node = this.head;

        while (node.next) {
            if ((index_counter + 1) === index) {
                node.next = new Node(data, node.next);
                return;
            }
            node = node.next;
            ++index_counter;
        }

        return this.insertLast(data);
    }

    forEach(fn) {
        if (!this.head) return;

        let index_counter = 0;
        let node = this.head;

        while (node) {
            fn(node, index_counter);
            node = node.next;
            ++index_counter;
        }
    }

    *[Symbol.iterator] () {
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
}