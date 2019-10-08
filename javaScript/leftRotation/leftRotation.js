/* const leftRotate = (array, numberOfRotates) => {
    while (numberOfRotates !== 0) {
        const temp = array[0];

        for (let i = 0; i < array.length - 1; i++) {
            array[i] = array[i + 1];
        }

        array[array.length - 1] = temp;
        numberOfRotates--;
    }

    return array;
} */

const leftRotate = (array, numberOfRotates) => {
    let temp = array.splice(0, numberOfRotates);
    array.splice(array.length, 0, ...temp);
    return array;
}

const a = [1, 2, 3, 4, 5];
const d = 4;
console.log(leftRotate(a, d).join(' '));