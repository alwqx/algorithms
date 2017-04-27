import pytest

def sequence_search(alist, item):
    pos = 0
    found = False

    while pos<len(alist) and not found:
        if item == alist[pos]:
            found = True
            break
        pos += 1

    return found


@pytest.mark.parametrize("test_input, item, expected", [
    ([1,4,5,6,7], 1, True),
    ([1,4,5,6,7], 2, False),
    ([1,2,3,4,6], 4, True),
    ([1,4,5,8,10], 6, False)
])
def test_sequence_search(test_input, item, expected):
    assert sequence_search(test_input, item) is expected

def ordered_sequence_search(alist, item):
    pos = 0
    found, stop = False, False

    while pos<len(alist) and not found and not stop:
        if alist[pos] == item:
            found = True
        elif alist[pos] > item:
            stop = True
        pos += 1

    return found
@pytest.mark.parametrize("test_input, item, expected", [
    ([1,4,5,6,7], 1, True),
    ([1,4,5,6,7], 2, False),
    ([1,2,3,4,6], 4, True),
    ([1,4,5,8,10], 6, False)
])
def test_ordered_sequence_search(test_input, item, expected):
    assert ordered_sequence_search(test_input, item) is expected

def binary_search(alist, item):
    found = False
    last = len(alist) - 1
    first = 0

    while first <= last and not found:
        mid = (first + last)//2
        if alist[mid] == item:
            found = True
        elif alist[mid] > item:
            last = mid - 1
        else:
            first = mid + 1

    return found


@pytest.mark.parametrize("test_input, item, expected", [
    ([1,4,5,6,7], 1, True),
    ([1,4,5,6,7], 2, False),
    ([1,2,3,4,6], 4, True),
    ([1,4,5,8,10], 6, False)
])
def test_binary_search(test_input, item, expected):
    assert binary_search(test_input, item) is expected

# slice of list need time
def recursion_binary_search(alist, item):
    if len(alist) == 0:
        return False
    mid = len(alist)//2

    if alist[mid] == item:
        return True
    elif alist[mid] > item:
        return recursion_binary_search(alist[:mid], item)
    elif alist[mid] < item:
        return recursion_binary_search(alist[mid+1:], item)
    else:
        return False

def recursion_binary_searchi(alist, item, first=None, last=None):
    if first >= last:
        return False

    print('first is {} last is {}'.format(first, last))

    mid = (first + last)//2

    if alist[mid] == item:
        return True
    elif alist[mid] > item:
        return recursion_binary_searchi(alist, item, first, mid-1)
    else:
        return recursion_binary_searchi(alist, item, mid+1, last)

@pytest.mark.parametrize("test_input, item, expected", [
    ([1,4,5,6,7], 1, True),
    ([1,4,5,6,7], 2, False),
    ([1,2,3,4,6], 4, True),
    ([1,4,5,8,10], 6, False)
])
def test_recursion_binary_search(test_input, item, expected):
    assert recursion_binary_search(test_input, item) is expected

@pytest.mark.parametrize("test_input, item, expected", [
    ([1,4,5,6,7], 1, True),
    ([1,4,5,6,7], 2, False),
    ([1,2,3,4,6], 4, True),
    ([1,4,5,8,10], 6, False)
])
def test_recursion_binary_searchi(test_input, item, expected):
    assert recursion_binary_searchi(test_input, item) is expected
