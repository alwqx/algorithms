def lcs(sx, sy):
    """
    :type s: string
    :rtype: substring

    >>> lcs("abcds", "abcs")
    4
    >>> lcs("", "")
    0
    >>> lcs("a", "")
    0
    >>> lcs("abdssde", "ac")
    1
    """
    dp = [[0 for i in range(len(sy))] for j in range(len(sx))]
    print(dp)
    for i in range(1, len(sx)):
        for j in range(1,len(sy)):
            if sx[i] == sy[j]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    print(dp)
    return dp[len(sx)-1][len(sy)-1]

print(lcs("a","a"))
print(lcs("abca","ca"))
print(lcs("ab","ac"))
