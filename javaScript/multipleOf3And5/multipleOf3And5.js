function multiplesOf3and5(number) {
    // Good luck!

    let sum = 0;
    let iter = 3;

    while (iter < number) {
        if (iter % 3 == 0 || iter % 5 == 0) {
            sum += iter;
        }

        iter++;
    }

    return sum;
}

console.log(multiplesOf3and5(1000));