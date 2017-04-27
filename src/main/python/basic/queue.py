# -*- coding: utf-8 -*-

class Queue:
    def __init__(self):
        self.items = []
        self._sizes = 0

    def enqueue(self, item):
        # None can be added to queue
        self.items.insert(0, item)
        self._sizes += 1

    def dequeue(self):
        if self.is_empty():
            raise Exception("queue is empty")
        item = self.items.pop()
        self._sizes -= 1
        return item

    def size(self):
        return self._sizes

    def is_empty(self):
        return self._sizes == 0

def test_queue():
    queue = Queue()
    queue.enqueue(1)
    queue.enqueue(4)
    queue.enqueue("adolph")

    assert queue.size() == 3
    assert queue.dequeue() == 1
    assert queue.size() == 2
