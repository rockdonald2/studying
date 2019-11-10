function destroyer(arr) {
    // Remove all the values
    let args = [...arguments];
    args.shift();

    const destroy = (num) => {
        if (args.includes(num)) {
            return false;
        } else {
            return true;
        }
    };

    arr = arr.filter(destroy);

    return arr;
}

destroyer([1, 2, 3, 1, 2, 3], 2, 3);