def quick(alist):
    if len(alist) <= 1:
        return
    quick_helper(alist, 0, len(alist)-1)

def quick_helper(alist, first, last):
    if first < last:
        split_point = partition(alist, first, last)
        quick_helper(alist, first, split_point-1)
        quick_helper(alist, split_point+1, last)

def partition(alist, first, last):
    pivot = alist[first]
    left = first + 1
    right = last
    done = False

    while not done:
        while left <= right and alist[left] <= pivot:
            left += 1
        while right >= left and alist[right] >= pivot:
            right -= 1
        if right < left:
            done = True
        else:
            tmp = alist[right]
            alist[right] = alist[left]
            alist[left] = tmp
    tmp = alist[first]
    alist[first] = alist[right]
    alist[right] = tmp

    return right

def test_quick():
    alist = [1,7,2,5,9,12,5]
    print("before sort: ", alist)
    quick(alist)
    print("after sort: ", alist)
    assert alist[0] == 1

test_quick()
