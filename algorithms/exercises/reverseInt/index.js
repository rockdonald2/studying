/* 
* --- Directions
* Given an integer, return an integer that is the reverse ordering of numbers.
*
* --- Examples
* reverseInt(15) === 51
* reverseInt(981) === 189
* reverseInt(500) === 5
*/

// 1. megoldás
/* function reverseInt(n) {
    if (n == 0) return 0;

    let reversed = 0;

    while (Math.abs(n) > 0) {
        reversed = reversed * 10 + n % 10;
        n = parseInt(n / 10);
    }

    return reversed
} */

// 2. megoldás
/* function reverseInt(n) {
    if (n == 0) return 0;

    const reversed = parseInt(n.toString().split('').reverse().join(''));

    return Math.sign(n) == 1 ? reversed : -reversed;
} */

// 3. megoldás
function reverseInt(n) {
    if (n == 0) return 0;

    const reversed = parseInt(n.toString().split('').reduce((prev, curr) => curr + prev, ''));

    return Math.sign(n) == 1 ? reversed : -reversed;
}

module.exports = reverseInt;