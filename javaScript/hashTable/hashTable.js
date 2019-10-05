var called = 0;
var hash = (string) => {
    called++;
    var hash = 0;
    for (var i = 0; i < string.length; i++) {
        hash += string.charCodeAt(i);
    }
    return hash;
};

class HashTable {
    constructor() {
        this.collection = {};
    }

    add(key, value) {
        let hashIndex = hash(key);

        if (!this.collection[hashIndex]) {
            this.collection[hashIndex] = {};
        }

        this.collection[hashIndex][key] = value;
    }

    remove(key) {
        let hashIndex = hash(key);

        if (!this.collection[hashIndex]) {
            return null;
        }

        let objKeys = Object.keys(this.collection[hashIndex]);

        for (let value of objKeys) {
            if (value === key) {
                delete this.collection[hashIndex][value];

                let temp = Object.keys(this.collection[hashIndex]);
                if (temp.length < 1) {
                    delete this.collection[hashIndex];
                }
            }
        }
    }

    lookup(key) {
        let hashIndex = hash(key);

        if (!this.collection[hashIndex]) {
            return null;
        }

        let objKeys = Object.keys(this.collection[hashIndex]);
        for (let value of objKeys) {
            if (value === key) {
                return this.collection[hashIndex][value];
            }
        }
    }
}