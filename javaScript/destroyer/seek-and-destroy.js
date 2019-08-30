function destroyer(arr) {
    // Remove all the values
    var args = [...arguments];
    args.shift();

    // j for the args
    // i for the arr
    let j = 0;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] == args[j]) {
            arr.splice(i, 1);
            i--;
        }

        if (i == arr.length - 1 && j < args.length - 1) {
            i = -1;
            j++;
        }
    }

    return arr;
}

console.log(destroyer([3, 5, 1, 2, 2], 2, 3, 5));