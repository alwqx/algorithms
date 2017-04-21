class LNRS(object):
    def lnrsdp(self, s):
        if s is None or len(s) == 1:
            return s

        max_len = index = last = 0
        dp = [0] * len(s)
        dp[0] = 1

        for i in range(1,len(s)):
            for j in range(i-1,last,-1):
                if s[i] == s[j]:#将当前状态和之前的状态对比，是否有重复字符
                    dp[i] = i-j
                    last = j+1
                    break
                elif j == last:
                    dp[i] = dp[i-1] + 1
            # 上层for循环得到当前状态（i）的dp值，更新last索引
            # i状态的dp有之前状态决定，需要遍历

            if dp[i] > max_len:
                max_len = dp[i]
                index = i - max_len + 1
        #print(dp)
        #print("max len is:", max_len)
        #print("max len substring is:", s[index:index+max_len])

    def lnrsdpmap(self, s):
        if s is None or len(s) == 0:
            return s

        dp = [0] * len(s)
        dp[0] = 1
        index = last = max_len = 0
        m = {s[0]:0}

        for i in range(1, len(s)):
            if s[i] in m:
                dp[i] = i - m[s[i]]
                last = m[s[i]] + 1
            else:
                dp[i] = dp[i-1] + 1
            m[s[i]] = i
            if dp[i] > max_len:
                max_len = dp[i]
                index = i-max_len+1
        #print(m)
        #print(dp)
        #print("max len is:", max_len)
        #print("max len substring is:", s[index:index+max_len])

    def lnrstiny(self, s):
        used_char = {}
        start = max_len = 0

        for i in range(len(s)):
            if s[i] in used_char and start <= used_char[s[i]]:
                start = used_char[s[i]] + 1
            max_len = max(max_len, i-start+1)
        used_char[s[i]] = i
        return max_len

lnrs = LNRS()
#lnrs.lnrsdp("abacdefgafg")
#lnrs.lnrsdpmap("abacdefgafg")
lnrs.lnrsdp("abcabcbb")
lnrs.lnrsdpmap("abcabcbb")
lnrs.lnrstiny("abcabcbb")
