# 1. megoldás
def capitalize(str):
    str = str.split(' ')

    str = list(map(lambda word : word[0].upper() + word[1:], str))

    return ' '.join(str)