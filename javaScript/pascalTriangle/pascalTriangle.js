/*
    @param n // represents the number to factoralise
    @description // simple factorial function
    @return int
*/

const factorial = (n) => {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

/* console.log(factorial(-1));
console.log(factorial(5)); */


/*
    @param n // nth row to return of Pascal Triangle
    @description a function which returns the nth row of Pascal Triangle
    @return array@int
*/

const pascalTriangle = (n) => {
    // any row starts with 1 in Pascal Triangle
    let a = [[1]];

    //let aSize = n + 1;

    let t = 1;
    let tSize = t + 1;
    for (;t <= n; t++) {
        tSize = t + 1;
        a.push([1]);

        for (let i = 1; i < tSize; i++) {
            a[t][i] = a[t][i - 1] * (t - i + 1) / i;
        }
    }

    /* for (let i = 1; i < aSize; i++) {
        a[i] = factorial(n) / (factorial(i) * factorial(n - i));
    } */

    return a;
}

console.log(pascalTriangle(5));