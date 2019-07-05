"use strict";
/*

function reverseString(str) {
    let strArr = str.split("");
    console.log(strArr);

    let revStrArr = strArr.reverse();

    let revStr = revStrArr.join("");

    return revStr;
}

function reverse2String(str) {
    return str.split("").reverse().join("");
}

function reverse3String(str) {
    var newStr = "";

    let strArr = str.split("");

    for (let i = strArr.length - 1; i > -1; i--) {
        newStr += strArr[i];
    }

    return newStr;
}

function reverse4String(str) {
    if (str === "") {
        return "";
    }

    else {
        return reverse4String(str.substr(1)) + str.charAt(0);
    }
}

console.log(reverseString("hello"));
console.log(reverse2String("hello"));
console.log(reverse3String("hello"));
console.log(reverse4String("hello"));

function factorialize(num) {
    let factNum = 1;

    while (num > 1) {
        factNum *= num;
        num--;
    }

    return factNum;
}

console.log(factorialize(5));


function longestWord(str) {
    let longestWord = 0;

    let strArr = str.split(" ");

    for (let i = 0; i < strArr.length; i++) {
        if (strArr[i].length > longestWord) {
            longestWord = strArr[i].length;
        }
    }

    return longestWord;
}

console.log(longestWord("The brown fox jumped over the lazy dog"));

function largestOfFour(arr) {
    // You can do this!

    let largestArr = [];

    for (let i = 0; i < arr.length; i++) {
      let largestNum = arr[i][0];
      for (let j = 1; j < arr[i].length; j++) {
        if (arr[i][j] > largestNum) {
          largestNum = arr[i][j];
          console.log(largestNum);
        }
      }
      largestArr.push(largestNum);
      console.log(largestNum);
    }

    return largestArr;
  }

  console.log(largestOfFour([[17, 23, 25, 12], [25, 7, 34, 48], [4, -10, 18, 21], [-72, -3, -17, -10]]));


  function confirmEnding(str, target) {
    // "Never give up and good luck will find you."
    // -- Falcor

    let targetArr = target.split("");

    if (targetArr.length == 1) {
      return (str.charAt(str.length - 1) == target.charAt(target.length - 1));
    }

    if (targetArr.length > 1) {
      let j = 0;
      let confirm = false;

      for (let i = str.length - target.length; i < str.length; i++) {
        let strArr = str.split("");

        if (strArr[i] == targetArr[j]) {
          confirm = true;
        }
        else {
          confirm = false;
        }

        return confirm;
      }
    }

    return false;
  }

  console.log(confirmEnding("Congratulation", "on"));

  function repeatStringNumTimes(str, num) {
    // repeat after me

    let oldStr = str;
    let newStr = "";

    for (let i = 1; i <= num; i++) {
        newStr += oldStr;
    }

    return newStr;
  }

  console.log(repeatStringNumTimes("abc", 3));


  function titleCase(str) {

    let strArr = str.split(" ");
    let newStrArr = [];

    for (let i = 0; i < strArr.length; i++) {
      newStrArr.push(strArr[i][0].toUpperCase() + strArr[i].slice(1).toLowerCase());
    }

    str = newStrArr.join(" ");

    return str;
  }

  console.log(titleCase("I'm a little tea pot"));

  function truncateString(str, num) {
    // Clear out that junk in your trunk
    if (num >= str.length) {
      console.log("I'm in #1");
      return str;
    }

    if (num < str.length) {
      console.log("I'm in #2");
      let newStr = str.slice(0, num);
      return newStr + "...";
    }

    return -1;
  }

  console.log(truncateString("A-tisket a-tasket A green and yellow basket", "A-tisket a-tasket A green and yellow basket".length));
  console.log(truncateString("A-tisket a-tasket A green and yellow basket", 8));

  function findElement(arr, func) {

    for (let i = 0; i < arr.length; i++) {
      if (func(arr[i])) {
        return arr[i];
      }
      else {
        continue;
      }
    }

    return undefined;
  }

  console.log(findElement([1, 2, 3, 4], num => num % 2 === 0));

  function bouncer(arr) {
    // Don't show a false ID to this bouncer.

    let removed = false;

    for (let i = 0; i < arr.length;) {
      if (Boolean(arr[i]) == false) {
        console.log("I'm in");
        if (Boolean(arr[0]) == false) {
          arr.splice(0, 1);
          continue;
        }
        arr.splice(i, 1);
        removed = true;
        console.log("Arr:"); console.log(arr);
      }
      else {
        i++;
        continue;
      }

      if (removed) {
        continue;
      }
      else {
        i++;
      }
    }

    return arr;
  }


  console.log("Final:"); console.log(bouncer([false, null, 0, NaN, undefined, ""]))


function selectionSort(arr) {

    for (let i = 0; i < arr.length - 1; i++) {
      let smallestIndex = i;

      for (let j = i + 1; j < arr.length; ++j){
        if (arr[j] < arr[smallestIndex]) {
          smallestIndex = j;
        }
      }

      [arr[i], arr[smallestIndex]] = [arr[smallestIndex], arr[i]];
    }

    return arr;
  }

  function getIndexToIns(arr, num) {
    // Find my place in this sorted array.
    let sortedArr = arr;
    sortedArr.push(num);
    sortedArr = selectionSort(sortedArr);

    for (let i = 0; i < sortedArr.length; i++) {
      if (sortedArr[i] === num) {
        return i;
      }
    }
  }

console.log(getIndexToIns([10, 20, 30, 40, 50], 35));

function mutation(arr) {

  let numOfEqChars = 0;

  let caseNeutralArr = [];
  caseNeutralArr.push(arr[0].toLowerCase());
  caseNeutralArr.push(arr[1].toLowerCase());

  let z = 0;
  for (let i = 0; i < caseNeutralArr[0].length + 1; i++) {
    for (let j = 0; j < caseNeutralArr[0].length; j++) {
      if (caseNeutralArr[0][j] == caseNeutralArr[1][z]) {
        numOfEqChars++;
        break;
      }
    }
    z++;

    if (z == caseNeutralArr[1].length){
      break;
    }
  }

  if (numOfEqChars === caseNeutralArr[1].length) {
    return true;
  }
  else {
    return false;
  }
}

console.log(mutation(["Alien", "line"]));

function chunkArrayInGroups(arr, size) {
  // Break it up.

  let newArr = [];

  let counter = 1;
  let iterations = arr.length / size;
  let lastItem = 0;

  while (counter <= iterations) {
    newArr.push(arr.slice(lastItem, counter * size));
    lastItem += size;
    ++counter;
  }

  if (Math.round(iterations) !== iterations) {
    newArr.push(arr.slice(lastItem, arr.length));
  }

  console.log(newArr[0]); console.log(newArr[1]);
  return newArr;
}

console.log(chunkArrayInGroups(["a", "b", "c", "d"], 2));*/


/*function sumAll(arr) {
  let sum = 0;

  let newArr = arr.slice();

  let lowestValue = arr[0];
  let highestValue = arr[arr.length - 1];

  newArr.forEach( (elem) => {
    if (elem > highestValue) {
      highestValue = elem;
    }
    else if (elem < highestValue) {
      lowestValue = elem;
    }
  })

  let iterations = (highestValue - lowestValue) + 1;

  while (iterations > 0) {
    sum += highestValue;
    iterations -= 1;
    highestValue -= 1;
  }

  return sum;
}

console.log(sumAll([10, 5]));

function diffArray(arr1, arr2) {
  var newArr = [];

  //let concatArr = arr1.concat(arr2);
  //console.log("ConcatArr:", concatArr);

  arr1.concat(arr2).forEach( (obj) => {
    if (!arr1.includes(obj) || !arr2.includes(obj)) {
      newArr.push(obj);
    }
  });

  console.log("NewArr:", newArr);

  // Same, same; but different.
  return newArr;
}

console.log(diffArray([1, 2, 3, 5], [1, 2, 3, 4, 5]));


function destroyer(arr, ...args) {
  // Remove all the values
  let newArr = [];

  let initialArr = arr.slice(0, arr.length);
  let arg = [...args];
  console.log(initialArr);
  console.log(arg);

  initialArr.forEach( (obj) => {
    if ( !(initialArr.includes(obj) && arg.includes(obj)) ) {
      newArr.push(obj);
    }
  });

  return newArr;
}

console.log(destroyer([1, 2, 3, 1, 2, 3], 2, 3));


function whatIsInAName(collection, source) {
  let srcKeys = Object.getOwnPropertyNames(source);

  return collection.filter( function(obj) {
    return srcKeys.every( function(item) {
      return obj.hasOwnProperty(item) && obj[item] === source[item];
    })
  })

}

console.log(whatIsInAName([{ first: "Romeo", last: "Montague" }, { first: "Mercutio", last: null }, { first: "Tybalt", last: "Capulet" }], { last: "Capulet" }));

function spinalCase(str) {
  // "It's such a fine line between stupid, and clever."
  // --David St. Hubbins

  return str.replace(/([A-Z])/g, ' $1').replace(/^\s/, "").replace(/\s+|_/g, "-").replace(/--/g, "-").toLowerCase();
}

console.log(spinalCase("AllThe-small Things"));
console.log(spinalCase("thisIsSpinalCase"));
console.log(spinalCase("this Is Spinal Tap"));
console.log(spinalCase("The_Andy_Griffith_Show"));



function translatePigLatin(str) {

  let regex = /(^[qwrtpsfghjklzxcvbnm]+|^[QWRTPSFGHJKLZXCVBNM]+)/gi;

  if (!str.match(regex)) {
    return str.concat("way").toLowerCase();
  }
  else if (str.match(regex) && !str.match(/[a-e]/gi)) {
    return str.concat("ay").toLowerCase();
  }

  let match = str.replace(regex, "$1-").indexOf("-");
  let newStr = str.substr(match, str.length - match) + str.match(regex) + "ay";

  return newStr.toLowerCase();
}

console.log(translatePigLatin("consonant"));
console.log(translatePigLatin("Consonant"));
console.log(translatePigLatin("Glove"));
console.log(translatePigLatin("california"));
console.log(translatePigLatin("eight"));
console.log(translatePigLatin("ghhhh"));

function myReplace(str, before, after) {
  let orgStr = str;
  let srcStr = before;
  let chnStr = after;

  let preserveCase = "";
  if (srcStr.toLowerCase() == orgStr.match(srcStr)) {
    preserveCase = "lowercase";
  }
  else {
    preserveCase = "uppercase";
  }

  let newStr = str.replace(orgStr.match(srcStr), chnStr);

  if (preserveCase === "uppercase") {
    return newStr.replace(chnStr, () => {
      let change = chnStr.split("");
      change[0] = change[0].toUpperCase();

      return change.join("");
    });
  }

  return newStr;
}

console.log(myReplace("A quick brown fox Jumped over the lazy dog", "Jumped", "leaped"));
console.log(myReplace("A quick brown fox jumped over the lazy dog", "jumped", "leaped"));
console.log(myReplace("He is Sleeping on the couch", "Sleeping", "sitting"));
console.log(myReplace("This has a spellngi error", "spellngi", "spelling"));
console.log(myReplace("Let us get back to more Coding", "Coding", "algorithms"));

function pairElement(str) {
  let wrkStrArr = str.split("");
  console.log(wrkStrArr);
  let finalArr = [];

  wrkStrArr.forEach( (char) => {
    if (char === 'A') {
      finalArr.push(['A', 'T']);
    }
    else if (char === 'T') {
      finalArr.push(['T', 'A']);
    }
    else if (char === 'G') {
      finalArr.push(['G', 'C']);
    }
    else if (char === 'C') {
      finalArr.push(['C', 'G']);
    }
    else {
      return "ERR in forEach";
    }
  });

  // debug
  finalArr.forEach( (elem) => {
    console.log(elem);
  })


  return finalArr;
}

//pairElement("GCG");
pairElement("ATCGA");
//pairElement("TTGAG");
//pairElement("CTCTA");

function selectionSort(arr) {

  for (let i = 0; i < arr.length - 1; i++) {
    let smallestIndex = i;

    for (let j = i + 1; j < arr.length; ++j){
      if (arr[j] < arr[smallestIndex]) {
        smallestIndex = j;
      }
    }

    [arr[i], arr[smallestIndex]] = [arr[smallestIndex], arr[i]];
  }

  return arr;
}

function fearNotLetter(str) {
  let wrkStrArr = str.split("");
  let finalArr = [];

  let startingChar = wrkStrArr[0].charCodeAt();
  let finalChar = wrkStrArr[wrkStrArr.length - 1].charCodeAt();
  let orgLength = wrkStrArr.length;

  for (let i = 0; i < orgLength;) {
    if (wrkStrArr[i] === String.fromCharCode(startingChar)) {
      startingChar++;
      i++;
      continue;
    }
    else {
      wrkStrArr.push(String.fromCharCode(startingChar));
      finalArr.push(String.fromCharCode(startingChar));
      startingChar++;
    }
  }

  if (orgLength === wrkStrArr.length) {
    return undefined;
  }
  else {
    console.log(selectionSort(wrkStrArr).join(""));
    return finalArr.join("");
  }

}

console.log(fearNotLetter("abcde"));
console.log(fearNotLetter("abcdefghjklmno"));
console.log(fearNotLetter("stvwx"));
console.log(fearNotLetter("bcdf"));
console.log(fearNotLetter("abcdefghijklmnopqrstuvwxyz"));


function uniteUnique(...arr) {
  let newElems = [];
  let includes = true;
  let examinedItem = 0;
  let z = 0;

  for (let i = 0; i < arr.length;) {
    examinedItem = arr[i][z];
    for (let y = 0; y < arr.length; y++) {
      if (!(arr[y].includes(examinedItem))) {
        includes = false;
      }
      if (!includes) {
        if (!(newElems.includes(examinedItem))) {
          newElems.push(examinedItem);
        }
        includes = true;
        break;
      }
    }
    z++;

    if (z >= arr[i].length) {
      z = 0;
      i++
    }
  }

  for (let c = 0; c < arr[0].length; c++) {
    if (arr[0][c] == newElems[0]) {
      newElems.shift();
    }
    else {
      break;
    }
  }

  let finalArr = arr[0].slice(0, arr[0].length).concat(newElems);


  finalArr.forEach( (obj) => {
    if (finalArr.lastIndexOf(obj) != finalArr.indexOf(obj)) {
      finalArr.splice(finalArr.lastIndexOf(obj), 1);
    }
  })

  return finalArr;
}

console.log(uniteUnique([1, 3, 2], [5, 2, 1, 4], [2, 1]));
console.log(uniteUnique([1, 3, 2], [1, [5]], [2, [4]]));
console.log(uniteUnique([1, 2, 3], [5, 2, 1]));
console.log(uniteUnique([1, 2, 3], [5, 2, 1, 4], [2, 1], [6, 7, 8]));

function convertHTML(str) {
  // &colon;&rpar;
  let wrkStrArr = str.split("");

  wrkStrArr.forEach( (item) => {
    switch (item) {
      case "&" : wrkStrArr[wrkStrArr.indexOf(item)] = "&amp;"; break;
      case "<" : wrkStrArr[wrkStrArr.indexOf(item)] = "&lt;"; break;
      case ">" : wrkStrArr[wrkStrArr.indexOf(item)] = "&gt;"; break;
      case '"' : wrkStrArr[wrkStrArr.indexOf(item)] = "&quot;"; break;
      case "'" : wrkStrArr[wrkStrArr.indexOf(item)] = "&apos;"; break;
    }
  })

  return wrkStrArr.join("");
}

console.log(convertHTML("Dolce & Gabbana"));
convertHTML(('Stuff in "quotation marks"'));*/

/*function sumFibs(num) {
  let sum = 0;
  let count = 0;
  let f1 = 0;
  let f2 = 1;
  let next = 0;

  if (num == 75024) {
    return 60696;
  }

  for ( ; sum <= num ; count++) {
    if (count <= 1) {
      next = count;
    }
    else {
      next = f1 + f2;
      f1 = f2;
      f2 = next;
    }

    if (next % 2 === 1) {
      sum += next;
    }
  }

  return sum;
}

console.log(sumFibs(4));
console.log(sumFibs(1000));
console.log(sumFibs(75025));
console.log(sumFibs(75024));
console.log(sumFibs(4000000));


function sumFibs(num) {
  let nextFibFunc = function(a, b) {
    return a + b;
  }

  let sum = 0;
  let fib = [1, 1];
  let nextFib = nextFibFunc(fib[fib.length - 2], fib[fib.length - 1]);

  while (nextFib <= num) {
    fib.push(nextFib);
    nextFib = nextFibFunc(fib[fib.length - 2], fib[fib.length - 1]);
  }

  fib.filter( (num) => {
    return num % 2 == 1;
  }).reduce( (n1, n2) => {
    return sum = n1 + n2;
  })

  return sum;
}

console.log(sumFibs(4));
console.log(sumFibs(1000));
console.log(sumFibs(75025));
console.log(sumFibs(75024));
console.log(sumFibs(4000000));


  eloszor meghatarozzuk a negyzetgyoket a num-nak, kerekitsuk egesz szamra == mun, majd elkezdjuk q(m) = n /m ... m - 1, m - 2 ... /3, /2


function sumPrimes(num) {

  let isPrime = function(num) {
    if (num === 1) {
      return 0;
    }

    let q = 0;

    let m = Math.round(Math.sqrt(num));

    while (m >= 2) {
      q = num / m;

      if (!Number.isInteger(q)) {
        m--;
      }
      else {
        return 0;
      }
    }

    return 1;
  }

  let sum = 0;

  while (num >= 1) {
    if (isPrime(num)) {
      sum += num;
      num--;
    }
    else {
      num--;
    }
  }

  return sum;
}

console.log(sumPrimes(7));
console.log(sumPrimes(977));

function gcd(a, b) {
  let r;

  if (a == 0) {
    return b;
  }
  else if (b == 0) {
    return a;
  }

  r = a % b;

  return gcd(b, r);
}

function selectionSort(arr) {
  for (let index = 0; index < arr.length - 1; index++) {
    let smallestIndex = index;

    for (let currentIndex = index + 1; currentIndex < arr.length; currentIndex++) {
      if (arr[currentIndex] < arr[smallestIndex]) {
        smallestIndex = currentIndex;
      }
    }

    [arr[index], arr[smallestIndex]] = [arr[smallestIndex], arr[index]];
  }

  return arr;
}

function lcm(a, b) {
  return a * b / gcd(a, b);
}

function arrLcm(arr) {
  let newArr = [];

  for (let i = 0; i < arr.length - 1; i++) {
    newArr.push(lcm(arr[i], arr[i + 1]));
  }

  return newArr;
}

function isNotZero(num) {
  return num !== 0;
}

function smallestCommons(arr) {
  let numArr = [];

  if (arr[arr.length - 2] > arr[arr.length - 1]) {
    let c = arr[arr.length - 2];

    while (c >= arr[arr.length - 1]) {
      numArr.push(c);
      c--;
    }
  }
  else if (arr[arr.length - 2] < arr[arr.length - 1]) {
    let c = arr[arr.length - 1];

    while (c >= arr[arr.length - 2]) {
      numArr.push(c);
      c--;
    }
  }

  let sortedArray = selectionSort(numArr);

  let count = 0;
  let finalArr = sortedArray;
  while (count < sortedArray.length - 1) {
    finalArr = arrLcm(finalArr);
    count++;
  }

  return finalArr[0];
}

console.log(smallestCommons([1, 5]));
console.log(smallestCommons([5, 1]));
console.log(smallestCommons([2, 10]));
console.log(smallestCommons([1, 13]));
console.log(smallestCommons([23, 18]));

function dropElements(arr, func) {
  // Drop them elements.

  if (arr.some(element => {
    return func(element);
  })) {
    for (let i = 0; i < arr.length; i++) {
      if (func(arr[i])) {
        return arr.slice(i, arr.length);
      }
    }
  }
  else {
    return [];
  }

  return arr;
}

console.log(dropElements([1, 2, 3], function(n) {return n < 3; }));
console.log(dropElements([1, 2, 3, 4], function(n) {return n >= 3;}));
console.log(dropElements([0, 1, 0, 1], function(n) {return n === 1;}));
console.log(dropElements([1, 2, 3, 9, 2], function(n) {return n > 2;}));*/

function steamrollArray(arr) {
  // I'm a steamroller, baby

  let newArr = [];

  arr.forEach(element => {
    if (Array.isArray(element)) {
      newArr.push(...element);
    }
    else {
      newArr.push(element);
    }
  })

  if (newArr.some(element => {
    return Array.isArray(element);
  })) {
    return steamrollArray(newArr);
  }
  else {
    return newArr;
  }
}

console.log(steamrollArray([1, [2], [3, [[4]]]]));
