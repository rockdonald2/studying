function viralAdvertising(n) {
    let day = 1;
    let shared = 5;
    let liked = Math.floor(shared / 2);
    let cumulative = liked;

    for (; day < n ;) {
        day++;
        shared = liked * 3;
        liked = Math.floor(shared / 2);
        cumulative += liked;
    }

    return cumulative;
}

console.log(viralAdvertising(5));