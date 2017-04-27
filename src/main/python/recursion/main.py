def to_str(n, base):
    BASICSTR = '0123456789ABCEDF'
    if n < base:
        return BASICSTR[n]
    else:
        return to_str(n//base, base) + BASICSTR[n%base]

import turtle
def draw_rec(length):
    my_t = turtle.Turtle()
    my_w = turtle.Screen()

    def draw_spiral(my_t, length):
        if length > 0:
            my_t.forward(length)
            my_t.right(90)
            draw_spiral(my_t, length-5)

    draw_spiral(my_t, length)
    my_w.exitonclick()

"""
conslusion:
    1. basic condition
    2. change program state and come to basic condition
    3. call func itself
"""
