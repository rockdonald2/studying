// this is an in-line comment

/*"use strict";

let ourName;

let myName = "Lukacs Zsolt";

console.log(myName.length);


const arr = [1, 2.3, 3.1, -4, 5];

const arrInt = arr.filter(num => Math.round(num) === num);
const [a, b, ...arr1] = arr;

console.log(arr1);

console.log(arrInt);

let str = "The brown fox jumps over the bridge";
let strRegex = /brown|fox/g;
let result = str.match(strRegex);

console.log(result);*/

let obj = { name: "Zsolt", age: 19, adult: true};

let strObj = JSON.stringify(obj);

console.log(strObj);

// Open your browser console
let outputTwo = "This will print to the browser console 2 times";
// Use console.log() to print the outputTwo variable
console.log(outputTwo);

let outputOne = "Try to get this to log only once to the browser console";
// Use console.clear() in the next line to print the outputOne only once
console.clear();


// Use console.log() to print the outputOne variable
console.log(outputOne);