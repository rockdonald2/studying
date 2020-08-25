// --- Directions
// 1) Create a node class.  The constructor
// should accept an argument that gets assigned
// to the data property and initialize an
// empty array for storing children. The node
// class should have methods 'add' and 'remove'.
// 2) Create a tree class. The tree constructor
// should initialize a 'root' property to null.
// 3) Implement 'traverseBF' and 'traverseDF'
// on the tree class.  Each method should accept a
// function that gets called with each element in the tree

class Node {
    constructor(data) {
        this.data = data;
        this.children = [];
    }

    add(data) {
        this.children.push(new Node(data));
    }

    remove(data) {
        // 1. megoldás
        /* for (let i = 0; i < this.children.length; i++) {
            if (this.children[i].data === data) {
                this.children = this.children.slice(0, i).concat(this.children.slice(i + 1));
            }
        } */ 

        // 2. megoldás
        this.children = this.children.filter((n) => n.data !== data);
    }
}

class Tree {
    constructor() {
        this.root = null;
    }

    /* breadth-first */
    traverseBF(fn) {
        let arr = [this.root];

        while (arr.length) {
            const curr = arr.shift();

            arr.push(...curr.children);

            fn(curr);
        }
    }

    /* depth-first */
    traverseDF(fn) {
        let arr = [this.root];

        while (arr.length) {
            const curr = arr.shift();

            arr.unshift(...curr.children);

            fn(curr);
        }
    }
}

module.exports = {Node, Tree};