def chunk(array, size):
    if (not array) or (size <= 0):
        return print('Bad input')

    chunked = []

    for i in range(0, len(array), size):
        chunked.append(array[i:i + size])

    return chunked

""" def chunk(array, size):
    if (not array) or (size <= 0):
        return print('Bad input')

    chunked = []

    for e in array:
        if (not chunked) or (len(chunked[len(chunked) - 1]) == size):
            chunked.append([e])
        else:
            chunked[len(chunked) - 1].append(e)

    return chunked """

""" def chunk(array, size):
    if (not array) or (size <= 0):
        return print('Bad input')

    chunked = []
    i = 0

    for e in range(0, len(array)):
        if not (e % size):
            chunked.append([])
            i += 1

        chunked[i - 1].append(array[e])

    return chunked """