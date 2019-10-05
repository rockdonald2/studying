class CircularQueue {
  constructor(size) {

    this.queue = [];
    this.read = 0;
    this.write = 0;
    this.max = size - 1;

    while (size > 0) {
      this.queue.push(null);
      size--;
    }

  }

  print() {
    return this.queue;
  }


  enqueue(item) {
    // Only change code below this line
    if (this.queue[this.write] === null) {
      this.queue[this.write] = item;
      this.write++;
      this.write %= this.size();
      return item;
    } else {
      return null;
    }
    // Only change code above this line
  }

  dequeue() {
    // Only change code below this line
    if (this.queue[this.read] !== null) {
      let item = this.queue[this.read];
      this.queue[this.read] = null;
      this.read++;
      this.read %= this.size();
      return item;
    } else {
      return null;
    }
    // Only change code above this line
  }

  size() {
    return this.queue.length;
  }
}

let data = new CircularQueue(5);
data.enqueue(1);
data.enqueue(2);
data.enqueue(3);
data.enqueue(4);
data.enqueue(5);
data.dequeue();
data.dequeue();
data.dequeue();
data.enqueue('a');
data.enqueue('b');
data.enqueue('c');
console.log(data.print());
data.dequeue();
data.dequeue();
data.dequeue();
data.dequeue();
data.dequeue();
data.enqueue('d');
data.enqueue('e');
data.enqueue('f');
console.log(data.print());