let reverseString = (str) => {
    let i = 0;
    let j = str.length - 1;
    let arr = str.split("");

    for (;i < str.length / 2;) {
        [arr[i], arr[j]] = [arr[j], arr[i]];
        i++;
        j--;
    }

    return arr.join("");
}

let str = "reverse this";
console.log(reverseString(str));