# -*- coding: utf-8 -*-

class Deque(object):
    def __init__(self):
        self.items = []
        self._size = 0

    def add_first(self, item):
        self.items.insert(0, item)
        self._size += 1

    def add_last(self, item):
        self.items.append(item)
        self._size += 1

    def remove_first(self):
        if self.is_empty():
            raise Exception('deque is empty')
        item = self.items.pop(0)
        self._size -= 1
        return item

    def remove_last(self):
        if self.is_empty():
            raise Exception('deque is empty')
        item = self.items.pop()
        self._size -= 1
        return item

    def is_empty(self):
        return self._size == 0

    def size(self):
        return self._size

def test_deque():
    d = Deque()
    d.add_first(1)
    d.add_first(2)
    d.add_last("a")
    d.add_first("b") # ["b", 2,1,"a"]

    assert d.size() == 4
    assert d.remove_first() == "b"
    assert d.remove_last() == "a"
