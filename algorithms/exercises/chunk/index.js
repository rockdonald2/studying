/* 
* --- Directions
* Given an array and chunk size, divide the array into many subarrays
* where each subarray is of length size
* If the caller gives bad input, console log 'Bad input'
* --- Examples
* chunk([1, 2, 3, 4], 2) --> [[1, 2], [3, 4]]
* chunk([1, 2, 3, 4, 5], 2) --> [[1, 2], [3, 4], [5]]
* chunk([1, 2, 3, 4, 5], 10)  --> [[1, 2, 3, 4, 5]]
*/

// 1. megoldás
/* function chunk(array, size) {
    if (array == null || array.length == 0 || size <= 0) return console.log('Bad input');

    let returnArr = [];
    let tempArr = [];

    for (let i = 1; i <= array.length; i++) {
        tempArr.push(array[i - 1]);

        if (!(i % size)) {
            returnArr.push(tempArr);
            tempArr = [];
        }
    }

    // if elements remain in tempArr, that means the length of the input array isn't divisible by size
    if (tempArr.length > 0) {
        returnArr.push(tempArr);
    }

    return returnArr;
} */

// 2. megoldás
/* function chunk(array, size) {
    if (array == null || array.length == 0 || size <= 0) return console.log('Bad input');

    let returnArr = [];

    let j = 0;
    for (let i = 0; i < array.length; i++) {
        if (!(i % size)) {
            returnArr.push([]);
            j++;
        }

        returnArr[j - 1].push(array[i]);
    }

    return returnArr;
} */

// 3. megoldás
/* function chunk(array, size) {
    if (array == null || array.length == 0 || size <= 0) return console.log('Bad input');

    let chunked = [];

    for (const e of array) {
        if (!chunked[chunked.length - 1] || chunked[chunked.length - 1].length === size) {
            chunked.push([e]);
        } else {
            chunked[chunked.length - 1].push(e);
        }
    }

    return chunked;
} */

// 4. megoldás
function chunk(array, size) {
    if (array == null || array.length == 0 || size <= 0) return console.log('Bad input');

    let chunked = [];

    for (let i = 0; i < array.length; i += size) {
        chunked.push(array.slice(i, i + size));
    }

    return chunked;
}

module.exports = chunk;