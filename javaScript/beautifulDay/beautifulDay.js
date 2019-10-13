function reverseNumber(n) {
    let arr = Array.from(String(n).split(''));

    for (let i = 0, j = arr.length - 1; i < arr.length / 2; i++, j--) {
        let temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    return Number.parseInt(arr.join(''));
}

// Complete the beautifulDays function below.
function beautifulDays(i, j, k) {
    let counter = 0;

    for (; i <= j; i++) {
        if (Math.abs(i - reverseNumber(i)) % k === 0) {
            counter++;
        }
    }

    return counter;
}

console.log(beautifulDays(20, 23, 6));