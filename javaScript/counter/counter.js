function counter(string) {
    let sum = 0;

    for (let i = 0; i < string.length; i++) {
        sum += Number(string[i]);
    }

    return {
        zero: string.length - sum,
        one: sum
    }
}

const string = "010010";
console.log(counter(string));