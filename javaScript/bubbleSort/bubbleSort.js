let bubbleSort = (array) => {
    while (true) {
        let swap = false;
        for (let i = 0; i < array.length - 1; i++) {
            if (array[i] > array[i + 1]) {
                [array[i], array[i + 1]] = [array[i + 1], array[i]];
                swap = true;
            }
        }

        if (!swap) {
            break;
        }
    }


    return array;
}

let list = [1, 4, 2, 8, 345, 123, 43, 32, 5643, 63, 123, 43, 2, 55, 1, 234, 92];
console.log(bubbleSort(list));