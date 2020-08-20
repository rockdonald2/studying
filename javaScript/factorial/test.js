const factorial = require('./index');

test('factorial is a function', () => {
    expect(typeof factorial).toEqual('function'); 
});

test('factorial returns the factorial of an n number', () => {
    expect(factorial(2)).toEqual(2);
});

test('factorial returns the factorial of an n number', () => {
    expect(factorial(3)).toEqual(6);
});

test('factorial returns the factorial of an n number', () => {
    expect(factorial(10)).toEqual(3628800);
});

test('factorial returns the factorial of an n number', () => {
    expect(factorial(5)).toEqual(120);
});

test('factorial returns the factorial of an n number', () => {
    expect(factorial(15)).toEqual(1307674368000);
});

test('factorial returns the factorial of an n number', () => {
    expect(factorial(16)).toEqual(20922789888000);
});

test('factorial returns the factorial of an n number', () => {
    expect(factorial(20)).toEqual(2432902008176640000);
});

test('factorial returns the factorial of an n number', () => {
    expect(factorial(22)).toEqual(1124000727777607680000);
});

test('factorial returns the factorial of an n number', () => {
    expect(factorial(17)).toEqual(355687428096000);
});