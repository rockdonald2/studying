let steps = 0;

function replacement(arr) {
    steps++;

    let largestValue = {
        value: 0,
        index: 0
    };

    let secondLargestValue = {
        value: 0,
        index: 0
    };

    
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] > largestValue.value) {
            largestValue.value = arr[i];
            largestValue.index = i;
        }
    }

    for (let j = 0; j < arr.length; j++) {
        if (arr[j] > secondLargestValue.value && j !== largestValue.index) {
            secondLargestValue.value = arr[j];
            secondLargestValue.index = j;
        }
    }

    let diff = Math.abs(largestValue.value - secondLargestValue.value);
    arr.splice(largestValue.index, 1, diff);
    arr.splice(secondLargestValue.index, 1, diff);

    if (arr.every(v => v === 0)) {
        return arr;
    }

    console.log(arr);

    return replacement(arr);
}

console.log(replacement([5, 8, 9, 50, 51, 4, 5, 4, 12, 8789, 646, 564, 464, 65465, 0]), steps);