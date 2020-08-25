// --- Directions
// Implement bubbleSort, selectionSort, and mergeSort

// 1. megoldás
/* function bubbleSort(arr) {
    let swap = false;

    do {
        swap = false;

        for (let i = 0; i < arr.length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                let temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);

    return arr;
} */

// 2. megoldás
function bubbleSort(arr) {
    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < (arr.length - i - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                const temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return arr;
}

function selectionSort(arr) {
    for (let startIndex = 0; startIndex < arr.length; startIndex++) {
        let minIndex = startIndex;

        for (let currIndex = startIndex + 1; currIndex < arr.length; currIndex++) {
            if (arr[minIndex] > arr[currIndex]) {
                minIndex = currIndex;
            }
        }

        if (startIndex !== minIndex) {
            let temp = arr[startIndex];
            arr[startIndex] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    return arr;
}

function mergeSort(arr) {
    if (arr.length === 1) return arr;

    const midpoint = Math.floor(arr.length / 2);
    const left = arr.slice(0, midpoint);
    const right = arr.slice(midpoint);

    return merge(mergeSort(left), mergeSort(right));
}

function merge(left, right) {
    let result = [];

    while (left.length && right.length) {
        if (left[0] < right[0]) result.push(left.shift());
        else result.push(right.shift());
    }

    /* if (left.length) result.push(...left);
    if (right.length) result.push(...right); */

    return [...result, ...left, ...right];
}

module.exports = {
    bubbleSort,
    selectionSort,
    mergeSort,
    merge
};