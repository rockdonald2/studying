# 1. megoldás
""" def palindrome(string):
    return string == string[::-1] """

# 2. megoldás
""" def palindrome(string):
    for i in range(len(string) // 2):
        if string[i] != string[len(string) - 1 - i]:
            return False

    return True """

from functools import reduce

# 3. megoldás
def palindrome(string):
    return string == reduce(lambda rev, char: char + rev, string)