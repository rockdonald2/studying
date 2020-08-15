# 1. megoldás
""" def steps(n):
    for r in range(1, n + 1):
        print(r * '#' + (n - r) * ' ') """

# 2. megoldás
""" def steps(n):
    for row in range(0, n):
        stair = ''
        for col in range(0, n):
            if (col <= row):
                stair += '#'
            else:
                stair += ' ';
        print(stair) """

# 3. megoldás
def steps(n, row = 0, stair = ''):
    if (row == n):
        return

    if (len(stair) == n):
        print(stair)
        return steps(n, row + 1)

    if (len(stair) <= row):
        stair += '#'
    else:
        stair += ' '

    return steps(n, row, stair)