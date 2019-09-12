let pairwise = (arr, arg) => {
    let sumOfIndices = 0;

    if (arr.length == 0) {
        return 0;
    }

    let createPair = (a, b) => {
        let pair = [];
        pair.push(a);
        pair.push(b);
        return pair;
    }

    let pairs = [];

    for (let i = 0; i < arr.length; i++) {
        let j = i + 1;

        while (j < arr.length) {
            if (arr[i] + arr[j] == arg) {
                pairs.push(createPair(i, j));
                break;
            } else {
                j++;
            }
        }
    }

    // "make wiser pairs"
    for (let k = 0; k < pairs.length; k++) {
        let n = k + 1;

        while (n < pairs.length) {
            if ( (arr[(pairs[k][0])] == arr[(pairs[n][0])] || arr[(pairs[k][0])] == arr[(pairs[n][1])]) || (arr[(pairs[k][1])] == arr[(pairs[n][0])] || arr[(pairs[k][1])] == arr[(pairs[n][1])]) ) {
                pairs.splice(n, 1);
            }

            n++;
        }
    }

    for (let c = 0; c < pairs.length; c++) {
        for (let h = 0; h < pairs[c].length; h++) {
            sumOfIndices += pairs[c][h];
        }
    }

    return sumOfIndices;
}

console.log(pairwise([1, 4, 2, 3, 0, 5], 7));