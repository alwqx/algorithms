# 字符串

# [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

# [459. 重复的子字符串](https://leetcode-cn.com/problems/repeated-substring-pattern/)
感觉这道题目在PUA我，不算是`简单题`，如果以简单题目的心态去做，结果发现做不出来，再看题解，涉及到KMP了，可能会打击到自己。

不过要调整好自己的心态，查漏补缺，现在不会把相关知识点补上就好了！

先看枚举法：
```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        /*
        这里的枚举代码很精妙、精简，加上注释才好理解
        1. 外层循环的i表示子串s_的长度
        2. 内层if(n%i==0)是s一定是s_长度的倍数，只有满足这个条件才for-loop枚举
        3. 内层循环的j表示s开始判断的起始索引，j-i则表示s_的起始索引
        */
        int n = s.size();
        for(int i=1; i*2<=n; i++) {
            if(n%i == 0) {
                bool match = true;
                for(int j=i; j<n; j++) {
                    if(s[j] != s[j-i]) {
                        match = false;
                        break;
                    }
                }

                if(match) return true;
            }
        }

        return false;
    }
};
```

题解的代码是非常精简的，个人认为是经过多次优化、精简的代码了，我在注释中进行了说明，方便自己理解。

这个思路即使有了，未必能容易地写出代码，所以这里也考察个人的编程能力。