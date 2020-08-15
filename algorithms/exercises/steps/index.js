// --- Directions
// Write a function that accepts a positive number N.
// The function should console log a step shape
// with N levels using the # character.  Make sure the
// step has spaces on the right hand side!
// --- Examples
//   steps(2)
//       '# '
//       '##'
//   steps(3)
//       '#  '
//       '## '
//       '###'
//   steps(4)
//       '#   '
//       '##  '
//       '### '
//       '####'

// 1. megoldás
/* function steps(n) {
    if (n <= 0) {
        return console.log('Bad input');
    }

    let stair = '';

    for (let i = 1; i <= n; i++) {
        stair = '';

        for (let j = 1; j <= i; j++) {
            stair += '#';
        }

        for (let z = 1; z <= (n - i); z++) {
            stair += ' ';
        }

        console.log(stair);
    }
} */

// 2. megoldás
/* function steps(n) {
    if (n <= 0) {
        return console.log('Bad input');
    }

    let stair = '';

    for (let i = 1; i <= n; i++) {
        stair = '#'.repeat(i) + ' '.repeat(n - i);

        console.log(stair);
    }
} */

// 3. megoldás
/* function steps(n) {
    if (n <= 0) {
        return console.log('Bad input');
    }

    let stair = '';

    for (let row = 0; row < n; row++) {
        stair = '';

        for (let col = 0; col < n; col++) {
            if (col <= row) {
                stair += '#';
            } else {
                stair += ' ';
            }
        }

        console.log(stair);
    } 
} */

// 4. megoldás
function steps(n, row = 0, stair = '') {
    if (n <= 0) {
        return console.log('Bad input');
    } 

    if (row === n) {
        return;
    }

    if (stair.length === n) {
        console.log(stair);
        return steps(n, row + 1);
    } 
    
    if (stair.length <= row) {
        stair += '#';
    } else {
        stair += ' ';
    }

    return steps(n, row, stair);
}

module.exports = steps;