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
console.log(translatePigLatin("ghhhh"));*/

function myReplace(str, before, after) {
  let orgStr = str;
  let srcStr = before;
  let chnStr = after;
  //console.log("orgStr" + " " + orgStr, "\nsrcStr" + " " + srcStr, "\nchnStr" + " " + chnStr);

  let preserveCase = "";
  if (srcStr.toLowerCase() == orgStr.match(srcStr)) {
    preserveCase = "lowercase";
  }
  else {
    preserveCase = "uppercase";
  }
  //console.log("\npreserveCase" + " " + preserveCase);

  let newStr = str.replace(orgStr.match(srcStr), chnStr);
  /*console.log("\nnewStr" + " " + newStr);
  console.log(newStr.match(chnStr).join());
  console.log((newStr.match(chnStr)).join().charAt(0));
  console.log(chnStr.split(""));
  console.log(newStr.split(""));

  console.log(chnStr.split("")[0] == newStr.split("")[newStr.search(chnStr) - 2]);*/

  if (preserveCase === "uppercase") {
    /*let nStrArr = newStr.split("");
    console.log(newStr.search(chnStr));
    console.log(nStrArr[6]);
    
    if (chnStr.split("")[0] == newStr.split("")[newStr.search(chnStr) - 2]) {
      //return newStr.replace((newStr.match(chnStr)).join().charAt(0), (newStr.match(chnStr)).join().charAt(0).toUpperCase());

      console.log(newStr.match(chnStr));
      console.log(newStr.substr(newStr.search(chnStr), newStr.match(chnStr)[0].length));
      //return newStr.replace(newStr.substr(newStr.search(chnStr), newStr.match(chnStr)[0].length), newStr.substr(newStr.search(chnStr), newStr.match(chnStr)[0].length).toUpperCase()).slice(0, newStr.split("")[newStr.search(chnStr)]).concat(newStr.split("")[newStr.search(chnStr) + 1].toLowerCase());

      return newStr.replace(newStr.substr(newStr.search(chnStr), newStr.match(chnStr)[0].length), newStr.substr(newStr.search(chnStr), newStr.match(chnStr)[0].length).toUpperCase()).replace(chnStr.toUpperCase(), function() {
        let change = chnStr.split("");
        change[0] = change[0].toUpperCase();
        console.log(change);

        return change.join("");
      });
    }*/


    //return newStr.replace((newStr.match(chnStr)).join().charAt(0), (newStr.match(chnStr)).join().charAt(0).toUpperCase());

    return newStr.replace(chnStr, () => {
      let change = chnStr.split("");
      change[0] = change[0].toUpperCase();
      //console.log(change);

      return change.join("");
    })
  }

  return newStr;
}

console.log(myReplace("A quick brown fox Jumped over the lazy dog", "Jumped", "leaped"));
console.log(myReplace("A quick brown fox jumped over the lazy dog", "jumped", "leaped"));
console.log(myReplace("He is Sleeping on the couch", "Sleeping", "sitting"));
console.log(myReplace("This has a spellngi error", "spellngi", "spelling"));
console.log(myReplace("Let us get back to more Coding", "Coding", "algorithms"));
