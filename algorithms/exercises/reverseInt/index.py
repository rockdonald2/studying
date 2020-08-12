# 1. megoldás
""" def reverseInt(n):
    if 0 <= n < 10:
        return n

    reversed = int(str(abs(n))[::-1])

    return reversed if n > 0 else -reversed """

# 2. megoldás
def reverseInt(n):
    if 0 <= n < 10:
        return n

    reversed = 0
    temp = abs(n)

    while abs(temp) > 0:
        reversed = reversed * 10 + temp % 10
        temp //= 10

    return reversed if n > 0 else -reversed