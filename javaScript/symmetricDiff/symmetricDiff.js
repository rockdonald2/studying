let sym = (...args) => {
    let h = [];

    while (args.length >= 2) {
        // remove args over the index of 1;
        let removedArgs = args.splice(2, args.length);

        // search algorithm
        let search = (n, i, args) => {
            let temp = [...args];
            temp.splice(i, 1);

            for (let w = 0; w < temp.length; w++) {
                for (let y = 0; y < temp[w].length; y++) {
                    if (n == temp[w][y]) {
                        return true;
                    }
                }
            }

            return false;
        }

        let n = 0;
        for (let i = 0; i < args.length; i++) {
            for (let j = 0; j < args[i].length; j++) {
                n = args[i][j];
                if (search(n, i, args)) {
                    continue;
                } else {
                    h.push(n);
                }
            }
        }

        let checkDuplicate = (arr, k) => {
            for (let j = 0; j < arr.length; j++) {
                if (arr[j] == k) {
                    return true;
                }
            }

            return false;
        }

        let temp = [];
        let k = 0;
        for (let i = 0; i < h.length; i++) {
            k = h[i];

            if (checkDuplicate(temp, k)) {
                h.splice(i, 1);
            } else {
                temp.push(k);
            }
        }

        h.sort((a, b) => {
            if (a < b) {
                return -1;
            }
            if (a > b) {
                return 1;
            }
            return 0;
        });

        let newArgs = []; 
        newArgs.push(h);
        // push the removedArgs back to the args obj
        for (let i = 0; i < removedArgs.length; i++) {
            newArgs.push(removedArgs[i]);
        }

        return sym(...newArgs);
    }

    return args[0];
}

console.log(sym([3, 3, 3, 2, 5], [2, 1, 5, 7], [3, 4, 6, 6], [1, 2, 3], [5, 3, 9, 8], [1]));