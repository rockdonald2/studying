from node import *

def validate(node, min = None, max = None):
    if (min != None and node.data < min):
        return False
    if (max != None and node.data > max):
        return False

    if (node.left and not validate(node.left, min, node.data)):
        return False

    if (node.right and not validate(node.right, node.data, max)):
        return False

    return True