function alternatingCharacters(s) {
    let deletions = 0;
    s = Array.from(s);

    for (let i = 0; i < s.length - 1; i++) {
        if (s[i] === s[i + 1]) {
            let counter = i + 1;
            while (s[counter + 1] === s[i] && s[counter + 1] !== undefined) {
                counter++;
            }
            s.splice(i, counter - i);
            deletions += (counter - i);
        }
    }

    return deletions;
}

console.log(alternatingCharacters('AAABBB'));