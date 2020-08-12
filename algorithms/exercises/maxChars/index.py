def maxChar(string):
    if len(string) == 1: return string

    chars = {}
    maxValue = {'index': -1, 'value': -1}

    for c in string:
        try:
            chars[c] += 1

        except KeyError:
            chars[c] = 1


    for c, v in chars.items():
        if v > maxValue['value']:
            maxValue['index'] = c
            maxValue['value'] = v

    return maxValue['index']