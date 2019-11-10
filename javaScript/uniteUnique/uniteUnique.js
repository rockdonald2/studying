function uniteUnique() {
    const args = [...arguments];

    let finalSet = new Set();

    for (let i = 0; i < args.length; i++) {
        for (let j = 0; j < args[i].length; j++) {
            finalSet.add(args[i][j]);
        }
    }

    return Array.from(finalSet);
}

console.log(uniteUnique([1, 3, 2], [5, 2, 1, 4], [2, 1]));