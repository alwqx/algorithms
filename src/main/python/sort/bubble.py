def bubble(alist):
    for first in range(len(alist)-1,0,-1):
        for sec in range(first):
            if alist[sec] > alist[sec+1]:
                tmp = alist[sec+1]
                alist[sec+1] = alist[sec]
                alist[sec] = tmp

def test_bubble():
    alist = [1,7,2,5,9,12,5]
    bubble(alist)
    assert alist[0] == 1
    assert alist[1] == 2
    assert alist[6] == 12
    assert alist[5] == 9

def short_bubble(alist):
    exchange = True
    first = len(alist) - 1

    while first > 0 and exchange:
        exchange = False
        for sec in range(first):
            if alist[sec] > alist[sec+1]:
                exchange = True
                tmp = alist[sec+1]
                alist[sec+1] = alist[sec]
                alist[sec] = tmp
        first -= 1

def test_short_bubble():
    alist = [1,4,5,2,19,3,7]
    short_bubble(alist)

    assert alist[0] == 1
    assert alist[1] == 2
    assert alist[6] == 19
    assert alist[5] == 7
