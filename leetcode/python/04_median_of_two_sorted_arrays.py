def median_sorted_arrays(n1, n2):
    """
    :type n1: List[int]
    :type n2: List[int]
    :rtype: float
    """

    def midian(n):
        tot = len(n)
        if tot%2 != 0:
            return float(n[tot//2])
        else:
            m = tot//2
            return (n[m-1]+n[m])/2.0

    if len(n1) == 0:
        ret = n2
    elif len(n2) == 0:
        ret = n1
    else:
        i = j = 0
        tot = len(n1) + len(n2)
        ret = [0]*tot

        for t in range(tot):
            if n1[i] < n2[j]:
                ret[t] = n1[i]
                i += 1
                if i >= len(n1):
                    for n in range(j, len(n2)):
                        ret[i+n] = n2[n]
                    break
            else:
                ret[t] = n2[j]
                j += 1
                if j >= len(n2):
                    for n in range(i, len(n1)):
                        ret[j+n] = n1[n]
                    break

    return midian(ret)

def test_msa():
    assert median_sorted_arrays([1,3], [2]) == 2.0
    assert median_sorted_arrays([1,2], [3,4]) == 2.5
    assert median_sorted_arrays([1,3,4], [2,6]) == 3.0
    assert median_sorted_arrays([1,3,4,9], [0,6]) == 3.5
    assert median_sorted_arrays([1], [2,6]) == 2.0
    assert median_sorted_arrays([1,4], [2,6]) == 3.0
    assert median_sorted_arrays([3,4], [2,6]) == 3.5

print(median_sorted_arrays([], [0,6]))
