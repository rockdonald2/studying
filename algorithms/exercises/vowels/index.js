/* 
* --- Directions
* Write a function that returns the number of vowels
* used in a string. Vowels are the characters 'a', 'e',
* 'i', 'o', 'u'.
* --- Examples
* vowels('Hi there!') --> 3
* vowels('Why?') --> 0
*/

// 1. megoldás
function vowels(str) {
    const vowels = str.match(/[aeiou]/gi);
    return vowels ? vowels.length : 0;
}

// 2. megoldás
/* function isVowel(char) {
    if (char === 'a' || char === 'e' || char === 'i' || char === 'o' || char === 'u') return true;
    return false;
}

function vowels(str) {
    let counter = 0;

    for (const c of str) {
        if (isVowel(c.toLowerCase())) counter++;
    }

    return counter;
} */

// 3. megoldás
/* function vowels(str) {
    let counter = 0;
    let letters = 'aeiou';

    for (const c of str.toLowerCase()) {
        if (letters.includes(c)) counter++;
    }

    return counter;
} */

module.exports = vowels;