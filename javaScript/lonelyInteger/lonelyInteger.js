function lonelyinteger(a) {
    if (a.length == 1) {
        return a[0];
    }

    let dict = {};
    for (let i = 0; i < a.length; i++) {
        if (a[i] in dict) {
            dict[a[i]] += 1;
        } else {
            dict[a[i]] = 1;
        }
    }

    for (let i in dict) {
        if (dict[i] != 1) {
            delete dict[i];
        }
    }

    return Object.keys(dict)[0];
}

console.log(lonelyinteger([0, 0, 1, 2, 1]));
console.log(lonelyinteger([1, 4, 3, 1, 1, 3]));
