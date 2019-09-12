let updateInventory = (curInv, newInv) => {
    let updatedInv = [];

    // early exit if any of the inventories is empty
    if (curInv.length == 0) {
        return newInv.sort((a, b) => {
            if (a[1] < b[1]) {
                return -1;
            }
            if (a[1] > b[1]) {
                return 1;
            }
            return 0;
        });
    } else if (newInv.length == 0) {
        return curInv.sort((a, b) => {
            if (a[1] < b[1]) {
                return -1;
            }
            if (a[1] > b[1]) {
                return 1;
            }
            return 0;
        });
    }

    // looping from the bigger array
    let invLength;
    if (curInv.length >= newInv.length) {
        invLength = curInv.length;
    } else {
        invLength = newInv.length;
    }

    // checking the items
    for (let it = 0; it < invLength; it++) {
        let item = curInv[it][1];
        let itemCount = curInv[it][0];

        for (let i = 0; i < newInv.length; i++) {
            if (newInv[i][1] == item) {
                itemCount += newInv[i][0];
                newInv.splice(i, 1);
                break;
            } else {
                continue;
            }
        }

        curInv[it][0] = itemCount;
    }

    // pushing the remaining items to the current inventory
    for (let it = 0; it < newInv.length; it++) {
        curInv.push(newInv[it]);
    }

    updatedInv = curInv.sort((a, b) => {
        if (a[1] < b[1]) {
            return -1;
        }
        if (a[1] > b[1]) {
            return 1;
        }
        return 0;
    });

    return updatedInv;
}

console.log(updateInventory([[0, "Bowling Ball"], [0, "Dirty Sock"], [0, "Hair Pin"], [0, "Microphone"]], [[1, "Hair Pin"], [1, "Half-Eaten Apple"], [1, "Bowling Ball"], [1, "Toothpaste"]]));