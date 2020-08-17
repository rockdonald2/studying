import re

def vowels(str):
    regExp = re.compile('[aeiou]', (re.IGNORECASE))
    counter = re.findall(regExp, str)

    return len(counter)