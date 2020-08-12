# 1. megoldás
""" def reverseString(string):
    return string[::-1] """

# 2. megoldás
""" def reverseString(string):
    reversed = ''

    for c in string:
        reversed = c + reversed

    return reversed """

# 3. megoldás
from functools import reduce

def reverseString(string):
    return reduce(lambda rev, char: char + rev, string)

