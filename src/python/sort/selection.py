def selection(alist):
    length = len(alist)

    for first in range(length-1,0,-1):
        max_index = first
        for sec in range(first):
            if alist[sec] > alist[max_index]:
                max_index = sec
        if max_index != first:
            tmp = alist[first]
            alist[first] = alist[max_index]
            alist[max_index] = tmp

def test_selection():
    alist = [95,23,20,1,45,32,34,90]
    selection(alist)

    assert alist[0] == 1
    assert alist[1] == 20
    assert alist[2] == 23
    assert alist[6] == 90
    assert alist[7] == 95
