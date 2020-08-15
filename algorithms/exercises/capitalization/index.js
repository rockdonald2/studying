/* 
* --- Directions
* Write a function that accepts a string, the function should
* capitalize the first letter of each word in the string then
* return the capitalized string.
* --- Examples
* capitalize('a short sentence') --> 'A Short Sentence'
* capitalize('a lazy fox') --> 'A Lazy Fox'
* capitalize('look, it is working') --> 'Look, It Is Working'
*/

// 1. megoldás
function capitalize(str) {
    str = str.split(' ');

    str = str.map(function (w) {
        return w[0].toUpperCase() + w.slice(1);
    });

    return str.join(' ');
}

// 2. megoldás
/* function capitalize(str) {
    str = str.split('');

    let prev = null;
    for (let c = 0; c < str.length; c++) {
        if ( (str[c].match(/\w/) !== null && prev == ' ') || (c === 0 && str[c].match(/\w/))) {
            str[c] = str[c].toUpperCase();
        }

        prev = str[c];
    }

    return str.join('');
} */

module.exports = capitalize;