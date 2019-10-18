function primality(n) {
    if (n === 1) {
        return "Not prime";
    } else if (n <= 3) {
        return "Prime";
    } else if (n % 2 === 0 || n % 3 === 0) {
        return "Not prime";
    }

    let i = 5;
    while (Math.pow(i, 2) <= n) {
        if (n % i === 0 || n % (i + 2) === 0) {
            return "Not prime";
        }

        i += 6;
    }

    return "Prime";
}

console.log(primality(31));