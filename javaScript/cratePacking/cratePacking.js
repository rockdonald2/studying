function fit(X, Y, x, y) {
    return Math.floor((X / x)) * Math.floor((Y / y));
}

function fitRotate(X, Y, x, y) {
    let first = fit(X, Y, x, y);
    let second = fit(X, Y, y, x)

    return first > second ? first : second;
}

const permutator = (inputArr) => {
    let result = [];

    const permute = (arr, m = []) => {
        if (arr.length === 0) {
            result.push(m)
        } else {
            for (let i = 0; i < arr.length; i++) {
                let curr = arr.slice();
                let next = curr.splice(i, 1);
                permute(curr.slice(), m.concat(next))
            }
        }
    }

    permute(inputArr)

    return result;
}

function fit3(X, Y, Z, x, y, z) {
    const permutations = permutator([x, y, z]);
    
    let highest = 0;
    for (let i = 0; i < permutations.length; i++) {
        let val = Math.floor(X / permutations[i][0]) * Math.floor(Y / permutations[i][1]) * Math.floor(Z / permutations[i][2]);
        if (val > highest) {
            highest = val;
        }
    }

    return highest;
}

function fitN(arrAxis, arrBox) {
    const permutations = permutator(arrBox);
    
    let highest = 0;
    for (let i = 0; i < permutations.length; i++) {
        let curr = 1;
        for (let j = 0; j < arrAxis.length; j++) {
            curr *= Math.floor((arrAxis[j] / permutations[i][j]));
        }

        if (curr > highest) {
            highest = curr;
        }
    }

    return highest;
}

console.log(fitN([180598, 125683, 146932, 158296, 171997, 204683, 193694, 216231, 177673, 169317], [1984, 2122, 1760, 2059, 1278, 2017, 1443, 2223, 2169, 1502]));