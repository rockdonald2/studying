const factorial = (a) => {
    if (a <= 1) {
        return 1;
    } else {
        return a * factorial(a - 1);
    }
};

console.log(factorial(5));

const pascalTriangle = (nOfRows) => {
    let currentLine = [1];

    let currentLineSize = nOfRows + 1;

    for (let c = 1; c < currentLineSize; c++) {
        currentLine[c] = currentLine[c - 1] * (nOfRows - c + 1) / c;
    }

    return currentLine;
};

console.log(pascalTriangle(4));