function diagonalDifference(arr) {
    // Write your code here
    let diff = 0;

    let firstDiagonal = 0;
    let secondDiagonal = 0;

    let k = 0;
    for (let u = 0; u < arr.length; u++) {
        firstDiagonal += arr[u][k];
        k++;
    }

    console.log(firstDiagonal);

    let j = arr[0].length - 1;
    for (let i = 0; i < arr.length; i++) {
        secondDiagonal += arr[i][j];
        j--;
    }

    console.log(secondDiagonal);

    diff = firstDiagonal - secondDiagonal;

    return diff;
}

let matrix = [[11, 2, 4], [4, 5, 6], [10, 8, -12]];
console.log(diagonalDifference(matrix));