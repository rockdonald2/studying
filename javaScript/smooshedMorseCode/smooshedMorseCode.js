
// all the letters from a to z, stored in array
const letters = '.- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --..'.split(' ');

function smorse(string) {
    let workingArr = string.split('');

    for (let i = 0; i < workingArr.length; i++) {
        workingArr[i] = letters[workingArr[i].charCodeAt(0) - 97];
    }

    return workingArr.join('');
}

console.log(smorse('sos'));
console.log(smorse('three'));