# 动态规划

# 5. 最长回文子串

根据[官方题解](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/)，这个问题有三种思路，第三种Manacher算法自己不是很理解，先不看了。

## 动态规划
这个思路是从子串的两侧向中心判断。状态转移方程为：
```shell
P(i, j) = P(i+1, j-1) && s[i]==s[j]
```

有了这个思路，代码还是不太好写出来的，我参考了题解的代码：
```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        string ans;
        vector<vector<bool>> dp(size, vector<bool>(size, false));

        int i, j, start=0;
        // 从0到s.size()之间进行判断，start是判断的起始点
        for(start=0; start<size; start++) {
            for(i=0; i+start<size; i++) {
                // 迭代，i和j才是真正的判断区间
                j = i+start;

                if(start == 0) dp[i][j] = true;
                else if(start == 1) dp[i][j] = (s[i]==s[j]);
                else dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);

                if(dp[i][j] && j-i+1>ans.size())
                    ans = s.substr(i, j-i+1);
            }
        }

        return ans;
    }
};
```

时间复杂度O(n*n)

## 中心扩散法
代码中有个问题要弄清，为什么循环中调用了`t0 = help(s, i, i);`和`t1 = help(s, i, i+1);`两个进行判断？

**因为中心可能是字符，也可能是字符间隙**

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int i, t0, t1, t;
        int pl=0, pr=0;
        for(i=0; i<s.size(); i++) {
            t0 = help(s, i, i);
            t1 = help(s, i, i+1);
            t = max(t0, t1);
            if(t > pr-pl+1) {
                pl = i-(t-1)/2;
                pr = i+t/2;
            }
        }

        return s.substr(pl, pr-pl+1);
    }
 
    int help(string s, int left, int right) {
        while(left>=0 && right<s.size() && s[left]==s[right]) {
            left--;
            right++;
        }

        return right-left-1;
    }
};
```