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
        this.queue = [];
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

    levelOrder(node = this.root) {
        if (!this.root) {
            return null;
        }

        this.queue.push(node);

        while (this.queue.length !== 0) {
            let current = this.queue.shift();
            this.result.push(current.value);

            if (current.left) {
                this.queue.push(current.left);
            }

            if (current.right) {
                this.queue.push(current.right);
            }
        }

        return this.result;
    }

    reverseLevelOrder(node = this.root) {
        if (!this.root) {
            return null;
        }

        this.queue.push(node);

        while (this.queue.length !== 0) {
            let current = this.queue.shift();
            this.result.push(current.value);

            if (current.right) {
                this.queue.push(current.right);
            }

            if (current.left) {
                this.queue.push(current.left);
            }
        }

        return this.result;
    }

    remove(value) {
        let found = false;
        let parent = null;
        let current = this.root;
        let childCount = 0;
        let replacement;
        let replacementParent;

        if (this.isPresent(value)) {
            while (!found && current) {
                if (value < current.value) {
                    parent = current;
                    current = current.left;
                } else if (value > current.value) {
                    parent = current;
                    current = current.right;
                } else {
                    found = true;
                }
            }

            if (found) {
                childCount = (current.left === null ? 0 : 1) + (current.right === null ? 0 : 1);

                if (current === this.root) {
                    switch (childCount) {
                        case 0: this.root = null; return null;

                        case 1: this.root = (current.right === null ? current.left : current.right); return null;

                        case 2: {
                            replacement = current.left;

                            if (this.inorder().length === 3) {
                                replacement.right = current.right;

                                this.root = replacement;
                                this.result.length = 0;
                                return null;
                            }

                            while (replacement.right !== null) {
                                replacementParent = replacement;
                                replacement = replacement.right;
                            }

                            if (replacementParent !== null) {
                                replacementParent.right = replacement.left;

                                replacement.right = this.root.right;
                                replacement.left = this.root.left;
                            } else {
                                replacement.right = this.root.right;
                            }

                            this.root = replacement;

                            return null;
                        }
                    }
                } else {
                    switch (childCount) {
                        case 0: {
                            if (current.value < parent.value) {
                                parent.left = null;
                            } else if (current.value > parent.value) {
                                parent.right = null;
                            }

                            return null;
                        }

                        case 1: { 
                            if (current.value < parent.value) {
                                parent.left = (current.left === null ? current.right : current.left);
                            } else if (current.value > parent.value) {
                                parent.right = (current.left === null ? current.right : current.left);
                            }

                            return null;
                        }

                        case 2: {
                            replacement = current.left;

                            while (replacement.right !== null) {
                                replacementParent = replacement;
                                replacement = replacement.right;
                            }

                            replacementParent.right = replacement.left;

                            replacement.right = current.right;
                            replacement.left = current.left;

                            if (current.value < parent.value) {
                                parent.left = replacement;
                            } else {
                                parent.right = replacement;
                            }


                            return null;
                        }
                    }
                }
            }
        } else {
            return null;
        }
    }

    invert(node = this.root) {
        if (!node) {
            return null;
        }

        var right = this.invert(node.right);
        var left = this.invert(node.left);

        node.left = right;
        node.right = left;

        return node;
    }
}

let test = new BinarySearchTree();
test.add(3); test.add(2); test.add(4); test.add(6); test.add(0); test.add(10);
test.invert();
console.log(test.inorder());