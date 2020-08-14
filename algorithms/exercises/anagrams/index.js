/* 
 * --- Directions
 * Check to see if two provided strings are anagrams of eachother.
 * One string is an anagram of another if it uses the same characters in the same quantity.
 * Only consider characters, not spaces or punctuation.
 * Consider capital letters to be the same as lowercase letters.
 * --- Examples
 * anagrams('rail safety', 'fairy tales') --> true
 * anagrams('RAIL SAFETY!', 'fairy tales') --> true
 * anagrams('Hi there', 'Bye there') --> false
*/

function createMap(string) {
    const map = {};

    for (const c of string) {
        map[c] = map[c] + 1 || 1;
    } 

    return map;
} 

function anagrams(stringA, stringB) {
    stringA = stringA.replace(/[^\w]/g, '').toLowerCase();
    stringB = stringB.replace(/[^\w]/g, '').toLowerCase();

    /* we separate the characters into charmaps */
    const charMapA = createMap(stringA);
    const charMapB = createMap(stringB);

    if (Object.keys(charMapA).length !== Object.keys(charMapB).length) return false;

    /* we compare the charmaps */
    for (const c in charMapA) {
        if (charMapA[c] !== charMapB[c]) return false;
    }

    return true;
}

module.exports = anagrams;