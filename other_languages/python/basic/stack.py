# -*- coding: utf-8 -*-
class Stack():
    def __init__(self):
        self.items = []
        self._size = 0

    def push(self, item):
        if item is None:
            raise ValueError("arguments to push() should not none!")
        self.items.append(item)
        self._size += 1

    def pop(self):
        if self.size() == 0:
            raise Exception("can not pop, stack has no items")
        item = self.items[self.size() - 1]
        del self.items[self.size() - 1]
        self._size -= 1
        return item

    def peek(self):
        if self.size() == 0:
            raise Exception("stack has no items")
        return self.items[self.size() - 1]

    def is_empty(self):
        return self.size() == 0

    def size(self):
        return self._size

    # refer http://stackoverflow.com/questions/19151/build-a-basic-python-iterator
    def __iter__(self):
        return self

    def __next__(self):
        if self.pos - 1 < 0:
            raise StopIteration()
        else:
            item = self.items[self.pos-1]
            self.pos -= 1
            return item

def test_stack():
    stack = Stack()
    stack.push("adolph")
    stack.push("wr")
    stack.push("zsh")
    assert(stack.pop() == "zsh")
    assert(stack.size() == 2)
    assert(stack.peek() == "wr")

def bracket_match(symbol_str):
    '''Judge is brackets in symbol are all match.
    Args:
        symbol: collect of brackets('(()))').
    Returns:
        bool: True all match therefore False.
    '''
    s = Stack()
    balanced = True
    index = 0
    while index < len(symbol_str) and balanced:
        symbol = symbol_str[index]
        if symbol == '(':
            s.push(symbol)
        else:
            if s.is_empty():
                balanced = False
                break
            else:
                s.pop()
        index += 1

    if balanced and s.is_empty():
        return True
    else:
        return True

#bracket_match("((())")
#bracket_match("(()())")

def decimal2binary(decimal):
    s = Stack()
    while decimal > 0 :
        mod = decimal % 2
        s.push(mod)
        decimal = decimal // 2

    binary = ''
    for b in s :
        binary += str(b)
    print(binary)

##decimal2binary(21)
def base_convert(decimal, base):
    digits = '0123456789ABCDEF'

    s = Stack()

    while decimal > 0 :
        mod = decimal % base
        s.push(mod)
        decimal = decimal // base

    out = ''
    for i in s :
        out += digits[i]
    print(out)

#base_convert(15, 7)
