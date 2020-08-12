const maxChar = require('./index');

test('maxChar function exists', () => {
    expect(maxChar).toBeDefined();
});

test('maxChar returns a string', () => {
    expect(typeof maxChar('apple')).toBe('string');
});

test('maxChar returns a string of length 1', () => {
    expect(maxChar('apple').length).toEqual(1);
});

test('Finds the most frequently used char', () => {
    expect(maxChar('a')).toEqual('a');
    expect(maxChar('abcdefghijklmnaaaaa')).toEqual('a');
    expect(maxChar('greetings')).toEqual('g');
    expect(maxChar('apple')).toEqual('p');
});

test('Works with numbers in the string', () => {
    expect(maxChar('ab1c1d1e1f1g1')).toEqual('1');
});