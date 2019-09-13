let insertionSort = (array) => {

    for (let i = 1; i < array.length; i++) {
        for (let j = 0; j <= i - 1; j++) {
            if (array[j] > array[i]) {
                array.splice(j, 0, array[i]);
                array.splice(i + 1, 1);
                break;
            }
        }
    }
    
    return array;
}

let list = [12, 11, 13, 5, 6];
console.log(insertionSort(list));