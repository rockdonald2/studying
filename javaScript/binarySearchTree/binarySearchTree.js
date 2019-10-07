class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class BinarySearchTree {
    constructor() {
        this.root = null;
        this.result = [];
    }

    findMin() {
        if (!this.root) {
            return null;
        }

        let node = this.root;

        while (node.left !== null) {
            node = node.left;
        }

        return node.value;
    }

    findMax() {
        if (!this.root) {
            return null;
        }

        let node = this.root;

        while (node.right !== null) {
            node = node.right;
        }

        return node.value;
    }

    add(value) {
        if (!this.root) {
            this.root = new Node(value);
            return;
        }

        let node = this.root;

        const searchTree = function (current) {
            if (current.value > value) {
                if (current.left) {
                    return searchTree(current.left);
                } else {
                    current.left = new Node(value);
                    return;
                }
            } else if (current.value < value) {
                if (current.right) {
                    return searchTree(current.right);
                } else {
                    current.right = new Node(value);
                    return;
                }
            } else {
                return null;
            }
        }

        return searchTree(node);
    }

    isPresent(value) {
        let node = this.root;

        if (!node) {
            return false;
        }

        if (node.value === value) {
            return true;
        }

        const searchTree = function (current) {
            if (current.value === value) {
                return true;
            } else if (current.value > value) {
                if (current.left !== null) {
                    return searchTree(current.left);
                } else {
                    return false;
                }
            } else if (current.value < value) {
                if (current.right !== null) {
                    return searchTree(current.right);
                } else {
                    return false;
                }
            }
        }

        return searchTree(node);
    }

    findMinHeight(node = this.root) {

        if (!node) {
            return -1;
        }

        if (node.left === null && node.right === null) {
            return 0;
        }

        if (node.left === null) {
            return this.findMinHeight(node.right) + 1;
        }

        if (node.right === null) {
            return this.findMinHeight(node.left) + 1;
        }

        const lHeight = this.findMinHeight(node.left);
        const rHeight = this.findMinHeight(node.right);

        return Math.min(lHeight, rHeight) + 1;
    }

    findMaxHeight(node = this.root) {

        if (node === null) {
            return -1;
        }

        if (node.left === null && node.right === null) {
            return 0;
        }

        if (node.left === null) {
            return this.findMaxHeight(node.right) + 1;
        }

        if (node.right === null) {
            return this.findMaxHeight(node.left) + 1;
        }

        const lHeight = this.findMaxHeight(node.left);
        const rHeight = this.findMaxHeight(node.right);

        return Math.max(lHeight, rHeight) + 1;
    }

    isBalanced(node = this.root) {
        if (node === null) {
            return false;
        }

        return this.maxDepth(node) - this.minDepth(node) <= 1;
    }

    minDepth(node) {
        if (node === null) {
            return 0;
        }

        return 1 + Math.min(this.minDepth(node.left), this.minDepth(node.right));
    }

    maxDepth(node) {
        if (node === null) {
            return 0;
        }

        return 1 + Math.max(this.maxDepth(node.left), this.maxDepth(node.right));
    }

    inorder(node = this.root) {
        if (node === null) {
            return null;
        }

        if (node.left) {
            this.inorder(node.left);
        }
        this.result.push(node.value);
        if (node.right) {
            this.inorder(node.right);
        }

        return this.result;
    }

    preorder() {
        if (node === null) {
            return null;
        }

        this.result.push(node.value);
        if (node.left) {
            this.preorder(node.left);
        }
        if (node.right) {
            this.preorder(node.right);
        }

        return this.result;
    }

    postorder() {
        if (node === null) {
            return null;
        }

        if (node.left) {
            this.postorder(node.left);
        }
        if (node.right) {
            this.postorder(node.right);
        }
        this.result.push(node.value);

        return this.result;
    }
}

let test = new BinarySearchTree();

test.add(7); test.add(1); test.add(9); test.add(0); test.add(3); test.add(8); test.add(10); test.add(2); test.add(5); test.add(4); test.add(6);
console.log(test.inorder());