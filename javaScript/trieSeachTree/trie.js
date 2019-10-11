/* var Node = function () {
    this.keys = new Map();
    this.end = false;
    this.setEnd = function () {
        this.end = true;
    };
    this.isEnd = function () {
        return this.end;
    };
};

var Trie = function () {
    // change code below this line
    this.head = new Node();

    this.add = function (word, node = this.head) {
        if (word.length === 0) {
            node.setEnd();
            return this.head;
        }

        if (!node.keys.get(word[0])) {
            node.keys.set(word[0], new Node());
            return this.add(word.substr(1), node.keys.get(word[0]));
        } else {
            return this.add(word.substr(1), node.keys.get(word[0]));
        }
    }

    this.isWord = function(word, node = this.head) {
        if (word.length === 0) {
            return node.end;
        }
        if (node.keys.get(word[0])) {
            return this.isWord(word.substr(1), node.keys.get(word[0]));
        }

        return false;
    }

    this.print = function() {
        let words = [];

        function traverse(node = this.head, word = '') {
            if (node.keys.size === 0) {
                return node.isEnd() ? words.push(word) : undefined;
            }

            if (node.keys.size) {
                for (let letter of node.keys.keys()) {
                    traverse(node.keys.get(letter), word.concat(letter));
                }
    
                if (node.isEnd()) words.push(word);
            }
        }

        traverse(this.head);
        return words;
    }
};

let test = new Trie();
test.add('cod');
test.add('code');
test.add('coder');
console.log(test.isWord('code'));
console.log(test.print()); */


class Node {
    constructor() {
        this.keys = new Map();
        this.end = false;
    }

    setEnd() {
        this.end = true;
    }

    isEnd() {
        return this.end;
    }
}

class Trie {
    constructor() {
        this.root = new Node();
    }

    add(word, node = this.root) {
        if (word.length === 0) {
            node.setEnd();
            return;
        }

        if (node.keys.has(word[0])) {
            this.add(word.substr(1), node.keys.get(word[0]));
        } else {
            node.keys.set(word[0], new Node());
            this.add(word.substr(1), node.keys.get(word[0]));
        }
    }

    isWord(word, node = this.root) {
        if (word.length === 0) {
            return node.isEnd();
        }

        if (node.keys.has(word[0])) {
            return this.isWord(word.substr(1), node.keys.get(word[0]));
        }

        return false;
    }

    print() {
        let words = [];

        const traverse = (node = this.root, word = '') => {
            if (node.keys.size === 0) {
                return node.isEnd() ? words.push(word) : undefined;
            }

            if (node.keys.size) {
                for (let letter of node.keys.keys()) {
                    traverse(node.keys.get(letter), word.concat(letter));
                }

                if (node.isEnd()) {
                    words.push(word);
                }
            }
        }

        traverse(this.root);
        return words;
    }
}

let test = new Trie();
test.add('cod');
test.add('code');
test.add('coder');
console.log(test.isWord('code'));
console.log(test.print());