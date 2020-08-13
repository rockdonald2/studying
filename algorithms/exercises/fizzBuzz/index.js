/* 
* --- Directions
* Write a program that console logs the numbers from 1 to n.
* But for multiples of 3 print 'fizz' instead of the number and for the multiples of 5 print 'buzz'.
* For numbers which are multiples of both numbers print 'fizzbuzz'.
* If the caller calls fizzbuzz with bad input, console log out 'Bad input'.
* --- Examples
* fizzBuzz(5);
* 1
* 2
* fizz
* 4 
* buzz
*/

function fizzBuzz(n) {
    if (n <= 0) {
        return console.log('Bad input');
    }

    let i = 1;
    while (i <= n) {
        let str = '';

        if (!(i % 3)) {
            str += 'fizz';
        }

        if (!(i % 5)) {
            str += 'buzz';
        }

        if (str.length > 0) console.log(str);
        else console.log(i);

        i++;
    }
}

module.exports = fizzBuzz;