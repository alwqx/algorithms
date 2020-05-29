# 序列问题汇总
## 面试题48. 最长不含重复字符的子字符串
### 基础DP
用dp[i]表示以s[i]为结尾的字符串的最长不重复子字符串，dp[0]=1，到dp[j]时，从s[j]向前回溯，找到s[i]==s[j]，然后判断`j-i`和dp[j-1]的关系来更新dp[j]。

代码如下：
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len == 0) return 0;

        vector<int> dp(len, 0);
        dp[0] = 1;
        int i, j;
        for(j=1; j<len; j++) {
            for(i=j-1; i>=0; i--)
                if(s[i] == s[j]) break;
            if(j-i > dp[j-1]) dp[j] = dp[j-1]+1;
            else dp[j] = j-i;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
```

上面的方法时间复杂度O(n^2)，空间复杂度O(n)，我们发现dp数组中当前状态只和前一个状态有关，所以可以简化空间复杂度，只使用两个变量存储状态。优化后的代码如下：

```cpp
class Solution {
public:
    int lentghOfLongestSubstring(string s) {
        int len = s.size();
        if(len == 0) return 0;

        int b, a=1, ans=1;
        int i, j;
        for(j=1; j<len; j++) {
            for(i=j-1; i>=0; i--)
                if(s[i] == s[j]) break;
            if(j-i > a) b = a+1;
            else b = j-i;
            a = b;
            ans = max(ans, b);
        }

        return ans;
    }
}
```

上面的方法只降低了空间复杂度到O(1)，但是时间复杂度还是O(n^2)，有没有方法可以降低呢？

一个思路是使用字典存储字符的索引，降低for内部的复杂度。
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len == 0) return 0;

        int b, a=1, i, j;
        map<int, int> m;
        m[s[0]] = 0;

        for(j=1; j<len; j++) {
            // 为什么可以这样做？因为j是从1开始向len迭代的，会慢慢向后改进，不会影响后面的值
            if(m[s[j]] != 0) i = m[s[j]];
            else i = (s[j]==s[0]?0:-1);
            // 更新index
            m[s[j]] = j;

            if(j-i > a) b = a+1;
            else b = j-i;
            a = b;
            ans = max(ans, b);
        }

        return ans;
    }
}
```

该方法参考[图解 滑动窗口（双指针）及优化方法](https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/solution/tu-jie-hua-dong-chuang-kou-shuang-zhi-zhen-shi-xia/)的题解。通过滑动窗口的思想来做。注意，引入字典后空间复杂度依然是O(1)，因为计算机中的字符数有限，ascii有128个，所以m存储的字符不超过128，空间复杂度O(1)。

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, right=0, ans=0;
        map<char, int> m;
        while(right < s.size()) {
            if(m.find(s[right]) != m.end()) left = max(left, m[s[right]]+1);
            m[s[right++]] = right;
            ans = max(ans, right-left);
        }

        return ans;
    }
}
```