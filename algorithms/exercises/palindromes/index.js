/* 
 * --- Directions
 * Given a string, write a function that returns true if a string and its reverse
 * are equal
 * Do include spaces and punctuation in determining if the string is a palindrome
 *
 * --- Example
 * palindrome('abba') === true
 * palindrome(' abba') === false
 */

// 1. megoldás
/* function palindrome(str) {
    let temp = '';
    const len = str.length;

    for (let i = 0; i < (len / 2); i++) {
        temp += str.slice(-1);
        str = str.slice(0, str.length - 1);
    }

    return temp === str || temp.slice(0, temp.length - 1) === str;
} */

// 2. megoldás
/* function palindrome(str) {
    return str === (str.split('').reduce((rev, char) => char + rev, ''));
} */

// 3. megoldás
/* function palindrome(str) {
    return str === (str.split('').reverse().join(''));
} */

// 4. megoldás
function palindrome(str) {
    return str.split('').every((val, i, arr) => {
        if (i >= str.length / 2) return true;
        /* else return val === str.slice(str.length - 1 - i)[0]; */
        else return val === arr[arr.length - 1 - i];
    });
}

palindrome('pennep');

module.exports = palindrome;