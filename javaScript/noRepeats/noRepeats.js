let factorial = (num) => {
    if (num > 1) {
        return num * factorial(num - 1);
    } else {
        return 1;
    }
}

let permute = (str, l, r, temp) => {
    let array = str.split('');

    if (l == r) {
        temp.push(array.join(''));
    } else {
        for (let i = l; i <= r; ++i) {
            [array[l], array[i]] = [array[i], array[l]];

            permute(array.join(''), l + 1, r, temp);

            [array[l], array[i]] = [array[i], array[l]];
        }
    }
}

let noRepeats = (str) => {

    if (str.length == 1) {
        return 1;
    }

    let count = 0;
    for (let i = 0; i < str.length - 1; ++i) {
        if (str[i] == str[i + 1]) {
            count++;
        }
    }

    if (count == str.length - 1) {
        return 0;
    }

    let temp = [];
    permute(str, 0, str.length - 1, temp);

    let noRepeats = 0;
    for (let j = 0; j < temp.length; ++j) {
        let repeat = false;

        for (let k = 0; k < temp[j].length; ++k) {
            let c = temp[j][k];

            if (temp[j][k + 1] == c) {
                repeat = true;
            }

            if (repeat) {
                break;
            }
        }

        if (!repeat) {
            noRepeats++;
        }
    }

    return noRepeats;
}

let str = "abcdefa";
console.log(noRepeats(str));