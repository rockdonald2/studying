def fizzBuzz(n):
    for i in range(1, n + 1):
        str = ''

        if not i % 3:
            str += 'fizz'
        if not i % 5:
            str += 'buzz'

        if len(str) > 0:
            print(str)
        else:
            print(i)