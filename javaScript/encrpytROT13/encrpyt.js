let encrpyt = (string) => {
    let stringArr = string.split("");

    for (let i = 0; i < string.length; i++) {
        if (stringArr[i] !== " ") {
            if ((string.charCodeAt(i) + 13 >= 65 && string.charCodeAt(i) + 13 <= 90) || (string.charCodeAt(i) + 13 >= 97 && string.charCodeAt(i) + 13 <= 122)) {
                stringArr[i] = String.fromCharCode(string.charCodeAt(i) + 13);
                continue;
            }

            if (string.charCodeAt(i) + 13 > 90 && string.charCodeAt(i) + 13 < 97) {
                stringArr[i] = String.fromCharCode(string.charCodeAt(i) + 13 + 6);
                continue;
            }

            if (string.charCodeAt(i) + 13 > 122) {
                stringArr[i] = String.fromCharCode(string.charCodeAt(i) + 13 - 58);
                continue;
            }
        }
        else {
            continue;
        }
    }

    string = stringArr.join("");
    return string;
}

let decrpyt = (string) => {
    let stringArr = string.split("");

    for (let i = 0; i < string.length; i++) {
        if (stringArr[i] !== " ") {
            if (string.charCodeAt(i) >= 97 && string.charCodeAt(i) <= 102) {
                stringArr[i] = String.fromCharCode(string.charCodeAt(i) - 13 - 6);
                continue;
            }

            if ((string.charCodeAt(i) - 13 >= 65 && string.charCodeAt(i) - 13 <= 90) || (string.charCodeAt(i) - 13 >= 97 && string.charCodeAt(i) - 13 <= 122)) {
                stringArr[i] = String.fromCharCode(string.charCodeAt(i) - 13);
                continue;
            }

            if (string.charCodeAt(i) - 13 > 90 && string.charCodeAt(i) - 13 < 97) {
                stringArr[i] = String.fromCharCode(string.charCodeAt(i) - 13 - 6);
                continue;
            }

            if (string.charCodeAt(i) - 13 < 65) {
                stringArr[i] = String.fromCharCode(string.charCodeAt(i) - 13 + 58);
                continue;
            }
        }
        else {
            continue;
        }
    }

    string = stringArr.join("");
    return string;
}

const string = "encrpyt this";
console.log(decrpyt(encrpyt(string)));