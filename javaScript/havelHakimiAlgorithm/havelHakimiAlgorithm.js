function eliminateZeros(arr) {
    return arr.filter((item) => item !== 0);
}

function descendingSort(arr) {
    return arr.sort((a, b) => a > b ? -1 : 1);
}

function lengthCheck(N, arr) {
    return N > arr.length;
}

function frontElimination(N, arr) {
    if (N > 0 && N <= arr.length) {
        for (let i = 0; i < N; i++) {
            arr[i] -= 1;
        }
    }

    return arr;
}

function havelHakimi(sequence) {
    sequence = eliminateZeros(sequence);

    if (sequence.length === 0) {
        return true;
    }

    sequence = descendingSort(sequence);

    const N = sequence.shift();
    
    if (lengthCheck(N, sequence)) {
        return false;
    }

    sequence = frontElimination(N, sequence);

    return havelHakimi(sequence);
}

console.log(havelHakimi([5, 3, 0, 2, 6, 2, 0, 7, 2, 5]));