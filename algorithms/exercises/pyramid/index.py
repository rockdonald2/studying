""" def pyramid(n):
    for l in range(1, n + 1):
        print(' ' * (n - l) + '#' * (l - 1) + '#' + '#' * (l - 1) + ' ' * (n - l)) """

def pyramid(n):
    for row in range(0, n):
        level = ''

        for col in range(0, 2 * n - 1):
            if (col >= n - 1 - row and col <= n - 1 + row):
                level += '#'
            else:
                level += ' '

        print(level)