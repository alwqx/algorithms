# -*- coding: utf-8 -*-

class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next

    def set_data(self, new_data):
        self.data = new_data

    def set_next(self, new_next):
        self.next = new_next

class LinkedList(object):
    def __init__(self):
        self.head = None

    def is_empty(self):
        return self.head == None

    def add(self, data):
        node = Node(data)
        node.set_next(self.head)
        self.head = node

    def size(self):
        count = 0
        cur = self.head
        while cur:
            count += 1
            cur = cur.get_next()

        return count

    def search(self, data):
        cur = self.head
        found = False

        while cur and not found:
            if cur.get_data() == data:
                found = True
            else:
                cur = cur.get_next()

        return found

    def remove(self, data):
        cur = self.head
        pre = None
        found = False

        while not found:
            if cur.get_data() == data:
                found = True
            else:
                pre = cur
                cur = cur.get_next()
        if pre is None:
            self.head = head.get_next()
        else:
            pre.set_next(cur.get_next())

    def append(self, data):
        node = Node(data)
        if self.size() == 0:
           self.head = node

        cur = self.head
        while cur:
            cur = cur.get_next()
        cur.set_next(node)

    def pop(self, index=-1):
        if index == -1:
            if self.is_empty():
                raise Exception('linked list is empty')
            cur = self.head
            pre = None
            while cur.get_next() is not None:
                pre = cur
                cur = cur.get_next()
            data = cur.get_data()
            pre.set_next(None)
            return data
        else:
            return self._pop(index)

    def _pop(self, index):
        size = self.size()
        if index > size-1:
            raise IndexError('index {} large linked list size'.
                        format(index))
        cur = self.head
        pre = None

        for i in range(index-1):
            pre = cur
            cur = cur.get_next()
        data = cur.get_data()
        pre = cur.get_next()
        cur.set_next(None)
        return data

def test_linkedlist():
    l = LinkedList()
    l.add(1)
    l.add(2)
    l.add(23)
    l.add('aa')

    if l.size() != 4:
        print('linked link error')
    if l.pop() == 1:
        print('success')
    if l.pop(0) == 'aa':
        print('success')

if __name__ == '__main__':
    test_linkedlist()
