def merge(alist):
    if len(alist) > 1:
        mid = len(alist)//2
        left = alist[:mid]
        right = alist[mid:]

        merge(left)
        merge(right)

        i,j,k = 0, 0, 0
        while i<len(left) and j<len(right):
            if left[i]<right[j]:
                alist[k] = left[i]
                i += 1
            else:
                alist[k] = right[j]
                j += 1
            k += 1
        while i<len(left):
            alist[k] = left[i]
            k += 1
            i += 1

        while j<len(right):
            alist[k] = right[j]
            k += 1
            j += 1

def test_merge():
    alist = [1,7,2,5,9,12,5]
    merge(alist)
    assert alist[0] == 1
    assert alist[1] == 2
    assert alist[6] == 12
    assert alist[5] == 9
