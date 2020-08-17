/* 
* --- Directions
* Write a function that accepts an integer N 
* and returns an NxN spiral matrix.
* --- Examples
* matrix(2)
*       [[1, 2],
*        [4, 3]]
*/

function matrix(n) {
    let results = [];
    for (let row = 0; row < n; row++) {
        results.push([]);
    }

    let counter = 1;
    let startRow = 0;
    let startCol = 0;
    let endRow = n - 1;
    let endCol = n - 1;

    while ((startCol <= endCol) && (startRow <= endRow)) {
        for (let i = startCol; i <= endCol; i++) {
            results[startRow][i] = counter;
            counter++;
        }
        startRow++;

        for (let i = startRow; i <= endRow; i++) {
            results[i][endCol] = counter;
            counter++;
        }
        endCol--;

        for (let i = endCol; i >= startCol; i--) {
            results[endRow][i] = counter;
            counter++;
        }
        endRow--;

        for (let i = endRow; i >= startRow; i--) {
            results[i][startCol] = counter;
            counter++;
        }
        startCol++;
    }

    return results;
}

module.exports = matrix;