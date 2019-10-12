function lpf(value) {
    // 2től kezdve végigosztjuk az a-t a maradék nélküli osztóival, addig amíg csak az az érték marad ami prímszám
    let b = 2;
    let a = value;

    while (a > b) {
        if (a % b === 0) {
            a /= b;
            b = 2;
        } else {
            b++;
        }
    }

    return b;
}

console.log(lpf(600851475143));