let selectionSort = (array) => {
    for (let startIndex = 0; startIndex < array.length - 1; startIndex++) {
        let smallestIndex = startIndex;

        for (let currentIndex = startIndex + 1; currentIndex < array.length; currentIndex++) {
            if (array[smallestIndex] > array[currentIndex]) {
                smallestIndex = currentIndex;
            }
        }

        [array[startIndex], array[smallestIndex]] = [array[smallestIndex], array[startIndex]];
    }

    return array;
}

let array = [1, 4, 2, 8, 345, 123, 43, 32, 5643, 63, 123, 43, 2, 55, 1, 234, 92];
console.log(selectionSort(array));