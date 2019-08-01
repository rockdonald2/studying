function arrDiff(arr1, arr2) {
    function compare(a, b) {
        return a > b;
    }

    for (let i = 0; i < arr2.length;) {
        for (let j = 0; j < arr1.length;) {
            if (arr1[i] === arr2[j]) {
                arr1.splice(j, 1);
                arr2.splice(i, 1);
                continue;
            } else {
                j++;
            }
        }
        i++;
    }

    return arr1.concat(arr2).sort(compare);
}

console.log(arrDiff([6, 5, 2, 9, 11, 24, 44], [1, 4, 6, 7, 11, 22]));