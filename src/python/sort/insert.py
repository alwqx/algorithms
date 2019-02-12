"""
变种冒泡排序！
def insert(alist):
    for first in range(len(alist)):
        for sec in range(first, 0 , -1):
            if alist[sec-1] > alist[sec]:
                tmp = alist[sec-1]
                alist[sec-1] = alist[sec]
                alist[sec] = tmp
"""

def insert(alist):
    for first in range(1, len(alist)):
        curval = alist[first]
        pos = first - 1
        # 这里pos的值为first/first-1都可以，关键在下面下标关系的正确判断
        while pos>=0 and alist[pos]>curval:
            alist[pos+1] = alist[pos]
            pos -= 1

        alist[pos+1] = curval

def test_insert():
    l0 = []
    l1 = [1]
    l2 = [2,1]
    l3 = [1,89,32,54,32,2,34,31]

    insert(l0)
    insert(l1)
    insert(l2)
    insert(l3)

    assert(len(l0)) == 0
    assert(l1[0]) == 1
    assert(l2[0]) == 1
    assert(l3[7]) == 89
    assert(l3[6]) == 54
    assert(l3[5]) == 34
    assert(l3[4]) == 32
    assert(l3[2]) == 31
