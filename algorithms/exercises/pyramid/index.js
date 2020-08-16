/* 
* --- Directions
* Write a function that accepts a positive number N.
* The function should console log a pyramid shape
* with N levels using the# character.Make sure the
* pyramid has spaces on both the left * and * right hand sides
* --- Examples
* pyramid(1)
*     '#'
* pyramid(2)
*     ' # '
*     '###'
*/

// 1. megoldás
/* function pyramid(n) {
    // egy adott piramis utolsó sorában 2 * n - 1 rácsjel van
    // egy adott oldalt mindig n - 1 rács/whitespace van
    let pyramid = '';

    for (let row = 1; row <= n; row++) {
        pyramid = ' '.repeat(n - row) + '#'.repeat(row - 1) + '#' + '#'.repeat(row - 1) + ' '.repeat(n - row);
        console.log(pyramid);
    }
} */

// 2. megoldás
/* function pyramid(n) {
    let pyramid = '';

    for (let row = 0; row < n; row++) {
        pyramid = '';
        
        for (let col = 0; col < (2 * n - 1); col++) {
            if (col >= n - 1 - row && col <= n - 1 + row) pyramid += '#';
            else pyramid += ' ';
        }

        console.log(pyramid);
    }
} */

// 3. megoldás
function pyramid(n, row = 0, level = '') {
    if (row === n) return;

    if (level.length === 2 * n - 1) {
        console.log(level);
        return pyramid(n, row + 1);
    }

    if (level.length >= n - 1 - row && level.length <= n - 1 + row) level += '#';
    else level += ' ';

    return pyramid(n, row, level);
}

module.exports = pyramid;