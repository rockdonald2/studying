var MaxHeap = function () {
    // change code below this line
    this.heap = [null];

    this.insert = function (value) {
        let a = [...this.heap];
        a.push(value);
        let index = a.length - 1;

        while (a[Math.floor(index / 2)] < value && a[Math.floor(index / 2)] !== null) {
            let temp = a[Math.floor(index / 2)];
            a[Math.floor(index / 2)] = a[index];
            a[index] = temp;

            index = Math.floor(index / 2);
        }

        this.heap = a;
        return this.heap;
    }

    this.remove = function () {
        if (this.heap.length === 1) {
            return null;
        }

        let a = [...this.heap];
        let lastElement = a.pop();
        let greatestValue = a.splice(1, 1)[0];
        a.splice(1, 0, lastElement);

        let index = a.indexOf(lastElement, 0);
        while ((a[index * 2] > lastElement || a[index * 2 + 1] > lastElement) && a.length > 3) {
            if (a[index * 2] !== undefined && a[index * 2 + 1] !== undefined) {
                if (a[index * 2] > lastElement && lastElement > a[index * 2 + 1]) {
                    let temp = a[index * 2];
                    a[index * 2] = a[index];
                    a[index] = temp;
    
                    index = index * 2;
                } else if (a[index * 2] < lastElement && lastElement < a[index * 2 + 1]) {
                    let temp = a[index * 2 + 1];
                    a[index * 2 + 1] = a[index];
                    a[index] = temp;
    
                    index = index * 2 + 1;
                } else if (a[index * 2] > lastElement && lastElement < a[index * 2 + 1]) {
                    let temp = ((a[index * 2] > a[index * 2 + 1]) ? a[index * 2] : a[index * 2 + 1]);
    
                    let swap = ((a[index * 2] > a[index * 2 + 1]) ? index * 2 : index * 2 + 1);
    
                    a[swap] = a[index];
                    a[index] = temp;
    
                    index = swap;
                }
            } else if (a[index * 2] === undefined || a[index * 2 + 1] === undefined) {
                let swap = (a[index * 2] === undefined) ? index * 2 + 1 : index * 2;

                if (a[swap] > lastElement) {
                    let temp = a[swap];
                    a[swap] = a[index];
                    a[index] = temp;

                    index = swap;
                }
            }
        }

        if (a.length === 3) {
            if (a[index] < a[index * 2]) {
                let temp = a[index * 2];
                a[index * 2] = a[index];
                a[index] = temp;
            }
        }

        this.heap = a;
        return greatestValue === undefined ? lastElement : greatestValue;
    }

    this.print = function () {
        return this.heap;
    }

    this.sort = function () {
        let sortedArray = [];
        let length = this.size();

        for (let i = 1; i < length; i++) {
            sortedArray.push(this.remove());
        }

        return sortedArray;
    }
    
    this.size = function () {
        return this.heap.length;
    }

    // change code above this line
};

let test = new MaxHeap();
test.insert(3);
test.insert(12);
test.insert(5);
test.insert(10);
test.insert(1);
test.insert(27);
test.insert(42);
test.insert(57);
test.insert(5);
console.log(test.print());
console.log(test.sort());