/* 
* --- Utasítások
* Adva egy sztring, térítsük vissza annak fordítottját
*
*
* --- Példák
* reverse('apple') === 'elppa'
* reverse('hello') === 'olleh'
*/

// 1. megoldás, nem változtatja meg a paramétert
/* function reverse(str) {
    let reversed = '';

    for (let i = str.length - 1; i >= 0; i--) {
        reversed += str[i];
    }

    return reversed;
} */

// 2. megoldás
/* function reverse (str) {
    return str.split('').reverse().join('');
} */

// 3. megoldás
/* function reverse (str) {
    let i = 0;
    let j = str.length - 1;
    str = str.split('');

    while (i < j) {
        let temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    return str.join('');
} */

// 4. megoldás
/* function reverse(str) {
    let reversed = '';

    for (const c of str) {
        reversed = c + reversed;
    }

    return reversed;
} */

// 5. megoldás
function reverse(str) {
    /* node debugger mód, $ node inspect index.js */
    debugger;

    return str.split('').reduce((rev, c) => c + rev, '');
}

/* debughoz kell */
reverse('asdf');

module.exports = reverse;