/* 
 * --- Directions
 * Create a stack data structure. The stack should be a class with methods 'push', 'pop', and 'peek'.
 * Adding an element to the stack should store it until it is removed.
 * --- Examples
 * const s = new Stack();
 * s.push(1);
 * s.push(2);
 * s.pop(); --> 2
 * s.pop(); --> 1
 */

class Stack {
    // private member variables
    #container = [];

    // constructor
    // creates an empty Stack
    constructor() {
        this.#container = [];
    }

    push(record) {
        this.#container.push(record);
    }

    pop() {
        return this.#container.pop();
    }

    peek() {
        return this.#container[this.#container.length - 1];
    }
};

module.exports = Stack;