/* 
* --- Directions
* Implement a Queue datastructure using two stacks.
* Do not create an array inside of the Queue class.
* Queue should implement the methods 'add', 'remove', and 'peek'.
* --- Examples
* const q = new Queue();
* q.add(1);
* q.add(2);
* q.peek(1); --> 1
* q.remove(); --> 1
* q.remove(); --> 2
*/

const Stack = require('./stack')

class Queue {
    // private variables
    #stackStorage = new Stack();
    #stackQueue = new Stack();

    // constructor
    constructor() {
        this.#stackStorage = new Stack();
        this.#stackQueue = new Stack();
    }

    add(record) {
        while (this.#stackQueue.peek()) {
            this.#stackStorage.push(this.#stackQueue.pop())
        }

        this.#stackStorage.push(record);

        while (this.#stackStorage.peek()) {
            this.#stackQueue.push(this.#stackStorage.pop())
        }
    }

    remove() {
        return this.#stackQueue.pop();
    }

    peek() {
        return this.#stackQueue.peek();
    }
}

module.exports = Queue;