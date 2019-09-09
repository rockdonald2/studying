let merge = (arr, l, m, r) => {
    let temp = [];
    for (let fill = 0; fill <= (r - l + 1); fill++) {
        temp.push(0);
    }

    let i = l;
    let j = m + 1;
    let k = 0;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            k++, i++;
        } else {
            temp[k] = arr[j];
            k++, j++;
        }
    }

    while (i <= m) {
        temp[k] = arr[i];
        k++, i++;
    }

    while (j <= r) {
        temp[k] = arr[j];
        k++, j++;
    }

    for (i = l; i <= r; ++i) {
        arr[i] = temp[i - l];
    }

    return arr;
}

let mergeSort = (arr, l, r) => {

    if (l < r) {
        let m = Math.floor((l + r) / 2);

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }

    return arr;
}

list = [1, 4, 2, 8, 345, 123, 43, 32, 5643, 63, 123, 43, 2, 55, 1, 234, 92]
console.log(mergeSort(list, 0, list.length - 1));