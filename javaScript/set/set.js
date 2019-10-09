class Set {
    constructor() {
        this.collection = [];
    }

    has(elem) {
        return (this.collection.indexOf(elem) !== -1);
    }

    values() {
        return this.collection;
    }

    add(elem) {
        if (!this.has(elem)) {
            this.collection.push(elem);
            return true;
        } else {
            return false;
        }
    }

    remove(elem) {
        if (this.has(elem)) {
            this.collection.splice(this.collection.indexOf(elem), 1);
            return true;
        } else {
            return false;
        }
    }

    size() {
        return this.collection.length;
    }

    union(unionMember) {
        let setA = this.values();
        let setB = unionMember.values();

        let unionSet = new Set();

        setA.forEach((item) => {
            unionSet.add(item);
        });
        setB.forEach((item) => {
            unionSet.add(item);
        });

        return unionSet;
    }

    intersection(member) {
        let intersection = new Set();
        let setA = this.values();

        setA.forEach((item) => {
            if (member.has(item)) {
                intersection.add(item);
            }
        });

        return intersection;
    }

    difference(member) {
        let difference = new Set();
        let setA = this.values();

        setA.forEach((item) => {
            if (!member.has(item)) {
                difference.add(item);
            }
        });

        return difference;
    }

    subset(member) {
        let hash = new Set();

        this.values().forEach((item) => {
            if (member.has(item)) {
                hash.add(item);
            }
        });

        if (hash.size() === this.size()) {
            return true;
        } else {
            return false;
        }
    }
}

let test = new Set();
test.add('a');
test.add('b');
test.add('c');
let test2 = new Set();
test2.add('a');
test2.add('b');
test2.add('d');
test2.add('e');
console.log(test.union(test2));
console.log(test.difference(test2));