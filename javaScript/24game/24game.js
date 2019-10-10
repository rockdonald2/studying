const game = (stringInput, numbers) => {
    const invalidChars = /[^\d\+\*\/\s-\(\)]/;

    function validateNumberInput(stringInput) {
        let generatedNumbers = numbers.slice();
        generatedNumbers.sort();

        return stringInput.replace(/[^\d\s]/g, ' ')
            .trim()
            .split(/\s+/)
            .map((n) => parseInt(n, 10))
            .sort()
            .every((v, i) => v === generatedNumbers[i]);
    }

    function validateStringInput(stringInput) {
        return stringInput.match(invalidChars)
    }

    function validateEval(stringInput) {
        try {
            return eval(stringInput);
        } catch (e) {
            return {
                error: e.toString()
            };
        }
    }

    if (stringInput.trim() === '') return "You must enter some value.";
    if (validateStringInput(stringInput)) return "Invalid characters used. Enter another value without those characters.";
    if (!validateNumberInput(stringInput)) return "Wrong numbers used not present in the original generated 4 digit number. Try again!";
    let calculatedValue = validateEval(stringInput);
    if (typeof calculatedValue !== 'number') return "Invalid input. Try again!";
    if (calculatedValue !== 24) return "Wrong answer: " + stringInput + " is not equal to 24. Please try again!";
    return stringInput + " equals to 24. Congratulations!";
}


while (true) {
    const numbers = [1, 2, 3, 4].map((n) => Math.floor(Math.random() * 8 + 1));

    const input = prompt(`Your numbers are ${numbers.join('')}; Please enter a valid expression that evaluates to 24 using only addition, subtraction, division and multiplication. Or 'x' to exit.`, "");

    if (input === 'x') {
        break;
    }

    alert(game(input, numbers));
}