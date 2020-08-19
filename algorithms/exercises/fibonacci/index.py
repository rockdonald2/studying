# 1. megoldás
""" def fib(n):
    a = 0
    b = 1
    temp = None
    index = 1

    while (index <= n):
        temp = a + b
        a = b
        b = temp
        index += 1

    return a """

# 2. megoldás
""" def fib(n):
    if (n < 2):
        return n

    return fib(n - 1) + fib(n - 2) """

# 3. megoldás - MEMOIZATION
fib_cache = {}

def fib(n):
    if n in fib_cache:
        return fib_cache[n]
    else:
        if n < 2:
            result = n
        else:
            result = fib(n - 1) + fib(n - 2)

        fib_cache[n] = result
        return result
