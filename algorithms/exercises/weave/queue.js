/* 
 * --- Directions
 * Queue is a container of sort, it represents a FIFO scheme, where the first entered
 * element will be the first that leaves the container.
 * The order in which the element entered the container, will be the order in which it leaves.
 * --- Examples
 * const q = new Queue();
 * q.add(1);
 * q.remove(); // returns 1
*/

class Queue {
    // private declaration, cannot be accessed from outside the class
    #container = []
    // creates the empty container
    constructor() {
        this.#container = [];
    }

    // peek method
    // returns the last element from the queue *without* removing it
    peek() {
        return this.#container[this.#container.length - 1];
    }

    // adds a new element to the start of the container
    // @ returns the new length
    add(elem) {
        this.#container.unshift(elem);
    }

    // removes the last element of the container
    // @ returns the removed element
    // if there're no elements in the container, returns undefined
    remove() {
        return this.#container.pop();
    }
}

module.exports = Queue;