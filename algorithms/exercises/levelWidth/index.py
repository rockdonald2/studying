from node import *

def levelWidth(node):
    widths = [0]
    arr = [node, None]

    while len(arr) > 1:
        curr = arr.pop(0)

        if curr == None:
            arr.append(curr)
            widths.append(0)
        else:
            arr.extend(curr.children)
            widths[len(widths) - 1] += 1

    return widths