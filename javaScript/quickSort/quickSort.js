let partition = (array, low, high) => {

    let pivot = array[high];

    let i = low - 1;

    for (let j = low; j <= high - 1; ++j) {
        if (array[j] < pivot) {
            ++i;
            [array[j], array[i]] = [array[i], array[j]];
        }
    }

    [array[i + 1], array[high]] = [array[high], array[i + 1]];

    return i + 1;
}

let quickSort = (arr, low, high) => {

    if (low < high) {
        let pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }

    return arr;
}

let array = [1, 4, 2, 8, 345, 123, 43, 32, 5643, 63, 123, 43, 2, 55, 1, 234, 92];
console.log(quickSort(array, 0, array.length - 1));