const capitalize = require('./index');

test('Capitalize is a function', () => {
    expect(typeof capitalize).toEqual('function');
});

test('capitalizes the first letter of every word in a sentence', () => {
    expect(capitalize('hi there, how is it going?')).toEqual(
        'Hi There, How Is It Going?'
    );
});

test('capitalizes the first letter', () => {
    expect(capitalize('i love breakfast at bill miller bbq')).toEqual(
        'I Love Breakfast At Bill Miller Bbq'
    );
});

test('capitalizes the first letter', () => {
    expect(capitalize('a short sentence')).toEqual('A Short Sentence');
});

test('capitalizes the first letter', () => {
    expect(capitalize('the quick brown fox jumps over the lazy dog')).toEqual('The Quick Brown Fox Jumps Over The Lazy Dog');
});

test('capitalizes the first letter with symbols', () => {
    expect(capitalize('hurry up!')).toEqual('Hurry Up!');
});