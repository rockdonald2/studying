function memoize(fn) {
    const cache = {};

    return function (...args) {
        if (cache[args]) {
            return cache[args];
        } else {
            const result = fn.apply(this, args);
            cache[args] = result;

            return result;
        }
    }
}

function factorial(n) {
    if (n < 1) return 1;

    return n * factorial(n - 1);
}

factorial = memoize(factorial);

module.exports = factorial;