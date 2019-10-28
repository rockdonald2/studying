function romanCalculator(romanNumber) {
    const parseRoman = (romanNumber) => {
        const dict = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        };

        let number = 0;

        for (let letter = 0; letter < romanNumber.length; letter++) {

            if (romanNumber[letter] == 'I') {
                if (romanNumber[letter + 1] == 'V' || romanNumber[letter + 1] == 'X') {
                    number += (dict[romanNumber[letter + 1]] - dict[romanNumber[letter]]);
                    letter++;
                } else {
                    number += dict[romanNumber[letter]];
                }
            } else if (romanNumber[letter] == 'X') {
                if (romanNumber[letter + 1] == 'L' || romanNumber[letter + 1] == 'C') {
                    number += (dict[romanNumber[letter + 1]] - dict[romanNumber[letter]]);
                    letter++;
                } else {
                    number += dict[romanNumber[letter]];
                }
            } else if (romanNumber[letter] == 'C') {
                if (romanNumber[letter + 1] == 'D' || romanNumber[letter + 1] == 'M') {
                    number += (dict[romanNumber[letter + 1]] - dict[romanNumber[letter]]);
                    letter++;
                } else {
                    number += dict[romanNumber[letter]];
                }
            } else {
                number += dict[romanNumber[letter]];
            }
        };

        return number;
    };

    const operator = {
        "+": function (a, b) {
            return a + b;
        },
        "-": function (a, b) {
            return a - b;
        },
        "*": function (a, b) {
            return a * b;
        },
        "/": function (a, b) {
            return a / b;
        }
    }

    romanNumber = romanNumber.split(' ');

    let evaluatedValue = 0;

    const checkMultiplication = (operator) => {
        return operator == '*';
    }

    const checkDivision = (operator) => {
        return operator == '/';
    }

    const checkAddition = (operator) => {
        return operator == '+';
    }

    const checkSubtraction = (operator) => {
        return operator == '-';
    }

    const parseNumbers = (num) => {
        if (num != '+' && num != '-' && num != '*' && num != '/') {
            return parseRoman(num);
        } else {
            return num;
        }
    };

    romanNumber = romanNumber.map(parseNumbers);

    while (romanNumber.findIndex(checkMultiplication) !== -1) {
        let index = romanNumber.findIndex(checkMultiplication);
        romanNumber.splice(index - 1, 3, operator['*'](romanNumber[index - 1], romanNumber[index + 1]));
    }

    while (romanNumber.findIndex(checkDivision) !== -1) {
        let index = romanNumber.findIndex(checkDivision);
        romanNumber.splice(index - 1, 3, operator['/'](romanNumber[index - 1], romanNumber[index + 1]));
    }

    while (romanNumber.findIndex(checkAddition) !== -1) {
        let index = romanNumber.findIndex(checkAddition);
        romanNumber.splice(index - 1, 3, operator['+'](romanNumber[index - 1], romanNumber[index + 1]));
    }

    while (romanNumber.findIndex(checkSubtraction) !== -1) {
        let index = romanNumber.findIndex(checkSubtraction);
        romanNumber.splice(index - 1, 3, operator['-'](romanNumber[index - 1], romanNumber[index + 1]));
    }

    evaluatedValue = romanNumber[0];

    return evaluatedValue;
}

console.log(romanCalculator("D - C * II"));