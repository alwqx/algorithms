"""
LIS: Longest Increased Subsequence
"""

def lis(s):
    """
    :type s: string
    :rtype: string subsequence

    >>> lis("abc")
    >>> lis("aabcd")
    """

def licint(l):
    """
    :type l: list of int
    :rtype: int

    >>> licint([1,-1,2,-2])
    2
    >>> licint([1,2,3,4])
    4
    """
    ret = 0
    dp = [0] * len(l)

    for i in range(len(l)):
        dp[i] = 1
        for j in range(i):
            if l[i] > l[j] and dp[i] < dp[j] + 1:
                dp[i] = dp[j]+1
                ret = max(ret, dp[i])
    return ret

lis("abc")
lis("azbcd")
