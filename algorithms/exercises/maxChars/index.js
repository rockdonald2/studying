/* 
 * --- Directions
 * Given a string, 
 * return the character that is most commonly used in the string.
 * --- Examples
 * maxChar('abcccccccd') === 'c'
 * maxChar('apple 1231111') === '1'
 */

function maxChar(str) {
    if (str.length <= 1) return str[0];

    let dict = {};
    let maxValue = {
        'index': -1,
        'value': -1
    };

    for (const c of str) {
        dict[c] = dict[c] + 1 || 1;
    }

    for (const k in dict) {
        if (dict[k] > maxValue.value) {
            maxValue.value = dict[k];
            maxValue.index = k;
        }
    }

    return maxValue.index;
}

module.exports = maxChar;