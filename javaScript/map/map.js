class Map {
    constructor() {
        this.collection = {};
    }

    add(key, value) {
        this.collection[key] = value;
    }

    remove(key) {
        delete this.collection[key];
    }

    get(key) {
        return this.collection[key];
    }

    has(key) {
        return (this.collection[key] ? true : false);
    }

    values() {
        return Object.keys(this.collection).map((key) => {
            return `${this.collection[key]}`
        });
    }

    size() {
        return Object.keys(this.collection).length;
    }

    clear() {
        Object.keys(this.collection).forEach((key) => delete this.collection[key]);
    }
}

let data = new Map();

data.add(1, 'a');
data.add(2, 'b');
data.add(3, 'c');
console.log(data.values());
data.remove(2);
console.log(data.values());
console.log(data.get(3));
console.log(data.has(1));
data.clear();
console.log(data.size(), data.values());