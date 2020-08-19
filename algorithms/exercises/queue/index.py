class Queue():
    def __init__(self):
        self._container = []

    def add(self, elem):
        return self._container.insert(0, elem)

    def remove(self):
        try:
            return self._container.pop()
        except IndexError:
            return None

    def first(self):
        try:
            return self._container[len(self._container) - 1]
        except:
            return None