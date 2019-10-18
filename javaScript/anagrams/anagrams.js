function makeAnagram(a, b) {
    let aObj = {};
    let bObj = {};

    let deletions = 0;

    for (let aC = 0; aC < a.length; aC++) {
        if (a[aC] in aObj) {
            aObj[a[aC]] += 1;
        } else {
            aObj[a[aC]] = 1;
        }
    }

    for (let bC = 0; bC < b.length; bC++) {
        if (b[bC] in bObj) {
            bObj[b[bC]] += 1;
        } else {
            bObj[b[bC]] = 1;
        }
    }

    let keysA = Object.keys(aObj);
    let keysB = Object.keys(bObj);

    for (let i = 0; i < keysA.length; i++) {
        if (keysA[i] in bObj) {
            if (bObj[keysA[i]] !== aObj[keysA[i]]) {
                deletions += (Math.abs(bObj[keysA[i]] - aObj[keysA[i]]));
            }
        } else {
            deletions += aObj[keysA[i]];
        }
    }

    for (let j = 0; j < keysB.length; j++) {
        if (!(keysB[j] in aObj)) {
            deletions += bObj[keysB[j]];
        }
    }

    return deletions;
}

console.log(makeAnagram('cde', 'dcf'));