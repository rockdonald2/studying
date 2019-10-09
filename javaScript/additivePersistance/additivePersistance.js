const func = (value) => {
    let counter = 0;

    while (value > 9) {
        let sum = 0;

        while (value) {
            sum += value % 10;
            value = Math.floor(value / 10);
        }

        counter++;
        value = sum;
    }

    return counter;
}

console.log(func(199));