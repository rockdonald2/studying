function merger(w1, w2, target) {
    if (target.length < (w1.length + w2.length)) {
        return false;
    }

    if (target.length === 0) {
        return w1.length === 0 && w2.length === 0 ? true : false;
    }

    for (let c = 0; c < target.length; c++) {
        if (w1[0] === target[c] && w1.length) {
            let re = merger(w1.substr(1), w2, target.replace(w1[0], ''));
            if (re) return re;
        } else if (w2[0] === target[c] && w2.length) {
            let re = merger(w1, w2.substr(1), target.replace(w2[0], ''));
            if (re) return re;
        }
    }
    return false;
}

console.log(merger("one", "rags", "oranges"));