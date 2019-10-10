const doors = () => {
    // doors open after a hundred pass

    let finalState = [];

    for (let i = 1; i * i <= 100; i++) {
        finalState.push(i * i);
    }

    console.log(finalState);
    return finalState;
}

doors();