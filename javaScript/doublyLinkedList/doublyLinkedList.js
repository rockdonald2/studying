function DoublyLinkedList() {
    let length = 0;
    let head = null;
    let tail = null;

    let Node = function (data, prev = null) {
        this.data = data;
        this.prev = prev;
        this.next = null;
    }

    this.add = function (data) {
        let node = head;

        if (!node) {
            head = new Node(data);
            length++;
            return;
        }

        while (node.next !== null) {
            node = node.next;
        }

        tail = node.next = new Node(data, node);
        length++;

        return;
    }

    this.remove = function (data) {
        let node = head;
        let previous;

        if (!node) {
            return null;
        }

        if (node.data === data) {
            head = head.next;
            head.prev = null;
            length--;
            return null;
        }

        while (node.next !== null) {
            if (node.data === data) {
                previous.next = node.next;
                node.next.prev = previous;

                length--;
                return null;
            }

            previous = node;
            node = node.next;
        }

        if (node.data === data) {
            node.prev.next = null;
            tail = node.prev;

            length--;
            return null;
        }

        return null;
    }

    this.head = function () {
        return head;
    }

    this.tail = function () {
        return tail;
    }

    this.size = function () {
        return length;
    }

    this.isEmpty = function () {
        return length === 0;
    }
}

let test = new DoublyLinkedList();
test.add(5);
test.add(6);
test.add(723);
console.log(test.head());
console.log(test.tail());