const reverse = require('./index');

test('Reverse function exists', () => {
    expect(reverse).toBeDefined();
});

test('Reverse returns a string', () => {
    expect(typeof reverse('abcd')).toBe('string');
});

test('Reverse reverses a string', () => {
    expect(reverse('abcd')).toEqual('dcba');
});

test('Reverse reverses a string', () => {
    expect(reverse('  abcd')).toEqual('dcba  ');
});

test('Reverse reverses a string', () => {
    expect(reverse('apple')).toEqual('elppa');
});

test('Reverse reverses a string', () => {
    expect(reverse('Greetings!')).toEqual('!sgniteerG');
});