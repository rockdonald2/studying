function fiboEvenSum(n) {
    let prev = 1;
    let next = 2;
    let temp;

    if (n <= 1) {
        return 0;
    }

    let sum = 2;
    for (let i = 2; i <= n; i++) {
        temp = next + prev;
        prev = next;
        next = temp;
        
        if (temp % 2 === 0) {
            sum += temp;
        }
    }

    return sum;
}

console.log(fiboEvenSum(10));