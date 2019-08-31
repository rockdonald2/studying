let firstRecurringCharacter = (str) => {
    let h = [];

    let search = (arr, ch) => {
        for (let j = 0; j < arr.length; j++) {
            if (arr[j] == ch) {
                return true;
            }
        }

        return false;
    }

    let c = "";
    for (let i = 0; i < str.length; i++) {
        if (str[i] === " ") {
            continue;
        }

        c = str[i];

        if (search(h, c)) {
            return c;
        }
        else {
            h.push(c);
        }
    }

    return str[0];
}

console.log(firstRecurringCharacter("first recurring character"));