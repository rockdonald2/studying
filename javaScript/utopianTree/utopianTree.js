function utopianTree(n) {
    if (n === 0) {
        return 1;
    } else {
        let tree = 1;
        for (let i = 1; i <= n; i++) {
            if (i % 2 === 1) {
                i *= 2;
            } else {
                i += 1;
            }
        }

        return tree;
    }
}

console.log(utopianTree(1));