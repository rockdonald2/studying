/*Probability homework*/

/* 
Auxiliary functions: permutation, variation and combination
*/

const factorial = (n) => {
    let val = 1;

    while (n >= 1) {
        val *= n;
        n--;
    }

    return val;
};


function add(str1, str2) {
    let sum = ""; // our result will be stored in a string.

    // we'll need these in the program many times.
    let str1Length = str1.length;
    let str2Length = str2.length;

    // if s2 is longer than s1, swap them.
    if (str2Length > str1Length) {
        let temp = str2;
        str2 = str1;
        str1 = temp;
    }

    let carry = 0; // number that is carried to next decimal place, initially zero.
    let a;
    let b;
    let temp;
    let digitSum;
    for (let i = 0; i < str1.length; i++) {
        a = parseInt(str1.charAt(str1.length - 1 - i)); // get ith digit of str1 from right, we store it in a
        b = parseInt(str2.charAt(str2.length - 1 - i)); // get ith digit of str2 from right, we store it in b
        b = b ? b : 0; // make sure b is a number, (this is useful in case, str2 is shorter than str1
        temp = (carry + a + b).toString(); // add a and b along with carry, store it in a temp string.
        digitSum = temp.charAt(temp.length - 1); //
        carry = parseInt(temp.substr(0, temp.length - 1)); // split the string into carry and digitSum ( least significant digit of abSum.
        carry = carry ? carry : 0; // if carry is not number, make it zero.

        sum = i === str1.length - 1 ? temp + sum : digitSum + sum; // append digitSum to 'sum'. If we reach leftmost digit, append abSum which includes carry too.
    }

    return sum; // return sum
}

// borrowed from @niinpatel
function extraLongFactorials(n) {
    let fact = 1;

    for (let i = 2; i <= n; i++) {

        if (Number.isSafeInteger(fact * i)) {
            fact = fact * i;
        } else {
            //fact = fact + fact + .. i times
            let factxi = "0"; // this is (fact * i) for us.
            for (let j = 0; j < i; j++) {
                factxi = add(factxi, fact.toString());
            }
            fact = factxi; // update value of fact before continuing the loop.
        }
    }

    return fact;
};

// I make use of the Arguments object because there will be in iterated cases multiple arguments, stating how many repeating elements will be in the set
const iteratedFactorial = (...args) => {
    if (args.length === 0) {
        return -1;
    }

    let numerator = factorial(args[0]);
    let denominator = 1;
    for (let i = 1; i < args.length; ++i) {
        denominator *= factorial(args[i]);
    }

    return (numerator / denominator);
};

// where n is the number elements in the set, and the k is the number of elements we want to have in the groups, in variation order matters, it counts as a new group
const variation = (n, k) => {
    return (factorial(n) / factorial(n - k));
};

// in cases where we put back the withdrawed element
const iteratedVariation = (n, k) => {
    return (Math.pow(n, k));
}

// where n is the number of elements in the set, and the k is the number of elements we want to have in the groups, order does not matter
const combination = (n, k) => {
    return (factorial(n) / (factorial(n - k) * factorial(k)));
}

// won't work with very big numbers
const extraLongCombinations = (n, k) => {
    return (extraLongFactorials(n) / (extraLongFactorials(n - k) * extraLongFactorials(k)));
}

const iteratedCombinatin = (n, k) => {
    return combination(n + k - 1, k);
}

/*
First model is hypergeometric distribution, where:
    n - the number of withdraws
    k - the number of withdraws from the preferred type
*/

// where a is the first type, b is the second, n is the total number of withdraws, k is the preferred number of withdraws from one type
const hypergeometric = (a, b, n, k) => {
    return ((combination(a, k) * combination(b, n - k)) / combination(a + b, n));
}

/* const testHyperGeometric = () => {
    // there are 10 girls and 20 boys, we want to choose from them 7, what is the probability that all 7 are girls?
    let val = hypergeometric(10, 20, 7, 7);
    // all 7 are boys?
    let val2 = hypergeometric(10, 20, 7, 0);
    // 4 girls and 3 boys 
    let val3 = hypergeometric(10, 20, 7, 4);
    // at least 2 of them are boys, it equals P(at least 2 of them are boys) = 1 - P(at most 1 of them are boys) = 1 - (P(none of them are boys) +  P(one of them are a boy));
    let val4 = 1 - hypergeometric(10, 20, 7, 7) - hypergeometric(10, 20, 7, 6);

    console.log(val);
    console.log(val2);
    console.log(val3);
    console.log(val4);
}

testHyperGeometric(); */


// again, we make use of the arguments object, because multiple unknown arguments are present
// s is the number of different elements
const hyperGeometricMultipleStates = (s, ...arguments) => {
    let args = arguments;

    let numerator = 1;
    let a = 0;
    let k = 0;
    for (let i = 0; i < s; i++) {
        numerator *= extraLongCombinations(args[i], args[i + s]);

        a += args[i];
        k += args[i + s];
    }
    let denominator = extraLongCombinations(a, k);


    return (numerator / denominator);
};

/* const testHyperGeometricMultipleStates = () => {
    // in a shop they sell 25 ties, what is the probability that 10 of the ties are blue, 5 are white, 10 are colorful, when they have on stock 50 blue, 70 white and 110 colorful.

    let val = hyperGeometricMultipleStates(3, 10, 12, 16, 1, 1, 1);

    console.log(val);
}

testHyperGeometricMultipleStates(); */

// where p is the number of the first elements present in the set, q is the number of the second elements present, we want to withdraw n elements with replacement, probability of withdrawing k elements of the first type
const binomialDistribution = (p, q, n, k) => {
    return (combination(n, k) * Math.pow((p / (p + q)), k) * Math.pow((q / (p + q)), n - k));
};

/* const testBinomialDistribution = () => {
    // the probability of newborn girls are 129 / 250, we have 6 children in the family, what is the probability of having at most 2 boys?
    // = 1 - P(at least 2 boys) or = P(0 boys) + P(1 boy) + P(2 boys)
    let val = binomialDistribution(121, 129, 6, 0) + binomialDistribution(121, 129, 6, 1) + binomialDistribution(121, 129, 6, 2);

    console.log(val);
}

testBinomialDistribution(); */

// probability of having the situation where we have withdrawn n - k of the q type, before withdrawing the k-th of p
const pascalDistribution = (p, q, n, k) => {
    return (combination(n - 1, k - 1) * Math.pow((p / (p + q)), k) * Math.pow((q / (p + q)), n - k));
}

/* const testPascalDistribution = () => {
    // 50 people visit a bank, the probability of opening an invoice is 0,02%, what is the probability that the 50th visitor will be 5th who opens an invoice?
    let val = pascalDistribution(1, 49, 50, 5);

    console.log(val);
}

testPascalDistribution(); */

// probability that the n-th withdraw will be the first k
const geometricDistribution = (p, q, n, k) => {
    return (Math.pow((p / (p + q)), 1) * Math.pow((q / (p + q)), n - 1));
};

// where s is the number of different elements, n is the number of withdraws, args are the differenet elements, after that the preferred number of withdraws
const polinomialDistribution = (s, n, ...args) => {
    let probabilities = [];

    let totalNumberOfElements = 0;
    for (let i = 0; i < s; i++) {
        totalNumberOfElements += args[i];
    }

    for (let i = 0; i < s; ++i) {
        probabilities.push(args[i] / totalNumberOfElements);
    };

    let numberOfPossibleIterations = iteratedFactorial(n, ...args.slice(s));

    let rValue = 1;
    for (let i = 0; i < probabilities.length; i++) {
        rValue *= (Math.pow(probabilities[i], args[i + s]));
    }

    return rValue * numberOfPossibleIterations;
};

/* const testPolinomialDistribution = () => {
    // a bank offers 3 types of depost facilities, what is the probability that out of 30 clients 6 chooses first, 15 chooses second, 9 chooses third, while the probability of choosing these are 2 / 10, 3 / 10, 5 / 10
    let val = polinomialDistribution(3, 30, 2, 3, 5, 6, 15, 9);

    console.log(val);
};

testPolinomialDistribution(); */


const exercises = () => {
    /* let val = binomialDistribution(2, 3, 6, 4);*/

    /* let val = pascalDistribution(7, 3, 100, 20); */

    /* let val = polinomialDistribution(3, 7, 2, 3, 4, 1, 2, 4); */

    /* let val = polinomialDistribution(3, 100, 55, 30, 15, 70, 20, 10); */

    /* let val = binomialDistribution(1, 1, 4, 3); */
    let val = binomialDistribution(1, 1, 3, 2);
    console.log(val);
};

exercises();