def matrix(n):
    results = [[None for col in range(0, n)] for row in range(0, n)]

    counter = 1
    startRow = 0
    endRow = n - 1
    startCol = 0
    endCol = n - 1

    while startCol <= endCol and startRow <= endRow:
        for i in range(startCol, endCol + 1):
            results[startRow][i] = counter
            counter += 1
        startRow += 1

        for i in range(startRow, endRow + 1):
            results[i][endCol] = counter
            counter += 1
        endCol -= 1

        for i in range(endCol, startCol - 1, -1):
            results[endRow][i] = counter
            counter += 1
        endRow -= 1

        for i in range(endRow, startRow - 1, -1):
            results[i][startCol] = counter
            counter += 1
        startCol += 1

    return results