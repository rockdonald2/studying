function LinkedList() {
    let length = 0;
    let head = null;

    var Node = function(element) {
        this.element = element;
        this.next = null;
    }

    this.head = function() {
        return head;
    }

    this.size = function() {
        return length;
    }

    this.add = function(element) {
        let newNode = new Node(element);

        if (!head) {
            head = newNode;
        } else {
            let tail = head;
            while (tail.next !== null) {
                tail = tail.next;
            }

            tail.next = newNode;
        }

        length++;
    }

    this.remove = function(element) {
        if (!this.head) {
            return;
        }

        let previous;
        let tail = head;

        if (tail.element == element) {
            head = head.next;
            length--;
            return;
        }

        while(tail) {
            if (tail.element == element) {
                previous.next = tail.next;
                length--;
                return;
            }

            previous = tail;
            tail = tail.next;
        }
    }

    this.isEmpty = function() {
        return length === 0;
    }

    this.indexOf = function(element) {
        if (!this.head) {
            return -1;
        }

        let tail = head;
        let counter = 0;

        while (tail) {
            if (tail.element === element) {
                return counter;
            }

            counter++;
            tail = tail.next;
        }

        return -1;
    }

    this.elementAt = function(index) {
        if (!this.head) {
            return undefined;
        }

        let tail = head;
        let counter = 0;
        while (tail) {
            if (counter === index) {
                return tail.element;
            }

            counter++;
            tail = tail.next;
        }

        return undefined;
    }

    this.removeAt = function(index) {
        if (!this.head) {
            return null;
        }

        if (index < 0 || index >= length) {
            return null;
        }

        let previous;
        let tail = head;
        let counter = 0;

        while (tail) {
            if (counter === index) {
                previous.next = tail.next;
                length--;
                return tail.element;
            }

            previous = tail;
            tail = tail.next;
            counter++;
        }

        return null;
    }

    this.addAt = function(index, element) {
        if (index < 0 || index >= length) {
            return false;
        }

        let newNode = new Node(element);

        let previous;
        let tail = head;
        let counter = 0;

        while (tail) {
            if (counter === index) {
                if (counter > 0) {
                    previous.next = newNode;
                } else {
                    head = newNode;
                }
                newNode.next = tail;
                length++;
                return true;
            }

            previous = tail;
            tail = tail.next;
            counter++;
        }

        return false;
    }
}