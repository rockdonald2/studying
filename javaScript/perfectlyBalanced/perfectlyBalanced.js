function perfectlyBalanced(string) {
    if (string.length === 0) {
        return true;
    }

    return (string.match(/x/gi) === null ? string.match(/y/gi).length : string.match(/x/gi).length) == (string.match(/y/gi) === null ? string.match(/x/gi).length : string.match(/y/gi).length);
}

console.log(perfectlyBalanced('yyxyxxyxxyyyyxxxyxyx'));

function perfectlyBalanced_bonus(string) {
    if (string.length === 0) {
        return true;
    }

    let letters = {};
    let arr = string.split('');
    for (let letter = 0; letter < arr.length; letter++) {
        if (arr[letter] in letters) {
            letters[arr[letter]] += 1;
        } else {
            letters[arr[letter]] = 1;
        }
    }

    const values = Object.values(letters);
    if (Math.pow(values[0], values.length) === values.reduce((num, total) => total *= num)) {
        return true;
    } else {
        return false;
    }
}

console.log(perfectlyBalanced_bonus('abccbaabccba'));