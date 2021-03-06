/* 
 * --- Directions
 * Print out the n-th entry in the fibonacci series
 * The fibonacci series is an ordering of numbers where each number is the sum of the preceeding two
 * --- Examples
 * The sequence [0, 1, 1, 2, 3, 5, 8, 13, 21, 34] forms the first ten entries of the fibonacci series.
 * fib(4) === 3 
 * fib(0) === 0
 */

// 1. megoldás
/* function fib(n) {
    let temp = null;
    let a = 0;
    let b = 1;
    let index = 1;

    while (index <= n) {
        temp = a + b;
        a = b;
        b = temp;
        index++;
    }

    return a;
} */

// 2. megoldás
/* function fib(n) {
    // for every n > 2 fib(n) = fib(n - 1) + fib(n - 2)

    if (n < 2) return n;

    // wikipédia
    return fib(n - 1) + fib(n - 2);
} */

// 3. megoldás - MEMOIZATION
function memoize(fn) {
    const cache = {};

    return function (...args) {
        /* if the function was ever called with the same set of args return the value */
        if (cache[args]) {
            return cache[args];
        }
        /* else do the work */
        else {
            const result = fn.apply(this, args);
            cache[args] = result;

            return result;
        }
    }
}

function slowFib(n) {
    if (n < 2) return n;

    return fib(n - 1) + fib(n - 2);
}

const fib = memoize(slowFib);

module.exports = fib;