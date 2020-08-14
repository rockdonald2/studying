import re

def createMap(string):
    charMap = {}

    for c in string:
        if c in charMap:
            charMap[c] += 1
        else:
            charMap[c] = 1

    return charMap

def anagrams(stringA, stringB):
    regexp = re.compile('[^\w]')

    stringA = re.sub(regexp, '', stringA).lower()
    stringB = re.sub(regexp, '', stringB).lower()

    charMapA = createMap(stringA)
    charMapB = createMap(stringB)

    if len(charMapA) != len(charMapB):
        return False

    for k in charMapA:
        if k not in charMapB or charMapA[k] != charMapB[k]:
            return False

    return True