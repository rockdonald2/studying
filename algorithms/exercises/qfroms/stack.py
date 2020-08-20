class Stack():
    def __init__(self):
        self._container = []

    def push(self, record):
        self._container.append(record)

    def pop(self):
        try:
            return self._container.pop()
        except IndexError:
            return None

    def peek(self):
        try:
            return self._container[len(self._container) - 1]
        except:
            return None