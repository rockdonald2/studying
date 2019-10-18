/* const bubbleSort = (array) => {
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
} */

function bubbleSort(a) {
    let swap = false;

    for (let i = 0; i < a.length - 1; i++) {
        swap = false;

        for (let j = 0; j < a.length - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap = true;
                [a[j], a[j + 1]] = [a[j + 1], a[j]];
            }
        }

        if (!swap) {
            break;
        }
    }

    return a;
}

let list = [1, 4, 2, 8, 345, 123, 43, 32, 5643, 63, 123, 43, 2, 55, 1, 234, 92];
console.log(bubbleSort(list));
