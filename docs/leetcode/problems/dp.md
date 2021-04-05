# 动态规划
[leetcode dp tags](https://leetcode-cn.com/tag/dynamic-programming/)

# [97. 交错字符串](https://leetcode-cn.com/problems/interleaving-string/)
题解牛啊，自己没想到，[要弄清楚滚动数组优化存储空间的方法](https://leetcode-cn.com/problems/interleaving-string/solution/jiao-cuo-zi-fu-chuan-by-leetcode-solution/)

# [264. 丑数 II](https://leetcode-cn.com/problems/ugly-number-ii/)

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
        // 这里的循环判断写法是相当精妙了，以s="abbd"为例，判断过程一次为：
        // start = 0.    i   j
        //               0   0
        //               1   1
        //               2   2
        //               3   3
        // start = 1.    i   j
        //               0   1
        //               1   2
        //               2   3
        // start = 2.    i   j
        //               0   2
        //               1   3
        // start = 3.    i   j
        //               0   3
        //
        // 不得不佩服，上面的循环写法是怎么想起来的？
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

**因为中心可能是字符，也可能是两个相邻字符之间的间隙**

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

**上面的代码中，为什么`pl = i-(t-1)/2;`括号中是-1呢**？

考虑样例`abbd`，当i=1时，len1=2，这时更新left=i-len1/2导致得到的左边界不对。

# [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)
官方题解看思路能明白，但是给的代码感觉和思路不对应，有些细节1小时内看不懂，就参考了其他人的。

## 贪心+dfs
参考[ikaruga](https://leetcode-cn.com/problems/coin-change/solution/322-by-ikaruga/)的题解，代码简炼，很好理解。

先将coins从大到小排序，先尽可能多地选面值大的硬币，判断是否能凑齐，不够的再选小的配，直到选完所有的。
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int ans = INT_MAX;
        sort(coins.rbegin(), coins.rend());
        dfs(coins, amount, 0, 0, ans);
        return ans==INT_MAX?-1:ans;
    }

    // amount待匹配的面值，pos当前使用的硬币，cnt当前已有的数量，ans最终结果
    void dfs(vector<int>& coins, int amount, int pos, int cnt, int& ans) {
        /*
        if(pos == coins.size()) {
            if(amount == 0) {
                ans = min(ans, cnt);
            }
            return;
        }
        */
        // 这里两个if判断次序不能颠倒，否则结果不同
        // 如果放在后面，根据实际代码执行过程，pos == coins.size()时需要加上判断
        // 如上面代码注释所示，下面的代码对两种情况进行汇总得到的
        if(amount == 0) {
            ans = min(ans, cnt);
            return;
        }
        if(pos == coins.size()) return;

        for(int k=amount/coins[pos]; k>=0 && cnt+k<ans; k--) {
            dfs(coins, amount-k*coins[pos], pos+1, cnt+k, ans);
        }
    }
};
```

## 自上而下迭代
[sugar](https://leetcode-cn.com/problems/coin-change/solution/javadi-gui-ji-yi-hua-sou-suo-dong-tai-gui-hua-by-s/)的思路和官方思路一致，但是更好理解。

考虑最优子结构和递推公式:
```shell
F(s) = F(s-c)+1;
F(s) = 0 if s=0
F(s) = -1 if s<0 || coins empty
```

我们用dp数组存储最小硬币数，dp[amount-1](**下表从0开始，所以-1**)，表示amount的最少硬币数。amount的结果由`amount-c`中的最小值决定，c为硬币。
```cpp
class Solution {
public:
    vector<int> dp;
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty()) return -1;
        dp.resize(amount);
        return dfs(coins, amount);
    }

    int dfs(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        if(dp[amount-1] != 0) return dp[amount-1];

        int ans = INT_MAX;
        for(int c:coins) {
            int res = dfs(coins, amount-c);
            if(res!=-1 && res<ans) ans = res+1;
        }
        dp[amount-1] = ans==INT_MAX?-1:ans;
        return dp[amount-1];
    }
};
```

## 自下而上迭代
这里的代码很有意思，未注释的部分是原来的代码，我觉得最后返回判断太多，就用了注释的部分，但是coins=[2] amount=3无法通过测试，我自己根据样例推到了过程，发现如果在迭代过程中就对dp赋值-1，则后面`dp[i-c]<ans`有可能覆盖掉结果，dp[1]=-1,dp[3]结果应该是-1，但是因为dp[1]<INT_MAX，所以dp[3]会变为0，前后判断的不一致了，不能在迭代过程中将INT_MAX替换为-1。
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty()) return -1;
        vector<int> dp(amount+1, 0);

        for(int i=1; i<=amount; i++) {
            int ans = INT_MAX;
            for(int c:coins) {
                if(i-c>=0 && dp[i-c]<ans) ans = dp[i-c]+1;
            }
            // dp[i] = ans==INT_MAX?-1:ans;
            dp[i] = ans;
        }

        // return dp[amount];
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};
```

# [91. 解码方法](https://leetcode-cn.com/problems/decode-ways/)
递归法超时，尝试其它方法。

```cpp
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        if(s.size() == 1) return s=="0"?0:1;

        if(s[0] == '0') return 0;
        if(s[1] == '0') {
            if(s[0]=='1' || s[0]=='2') return numDecodings(s.substr(2));
            return 0;
        }
        if(s.substr(0, 2)>"26") return numDecodings(s.substr(1));
        return numDecodings(s.substr(1))+numDecodings(s.substr(2));
    }
};
```


`2021.4.1更新`：深搜也超时，看了[Iris_bupt](https://leetcode-cn.com/problems/decode-ways/solution/c-wo-ren-wei-hen-jian-dan-zhi-guan-de-jie-fa-by-pr/)的题解，自己也想到了使用动态规划，但是没有理清楚解码数dp[i]，dp[i-1] dp[i-2]之间的递推关系，导致没有找到解决方案。

首先，dp[i]表示s[0] s[1] ... s[i]的解码数。我们要找s[i]时，dp[i]和dp[i-1] dp[i-2]之间的关系，笔者没有想清楚他们之间的关系，还是理解不深刻，**建议自己可以从几个特例入手，把抽象的问题具体化，方便理解**。

下面是题主的最优解法：
```cpp
int numDecodings(string s) {
    if (s[0] == '0') return 0;
    int pre = 1, curr = 1;//dp[-1] = dp[0] = 1
    for (int i = 1; i < s.size(); i++) {
        int tmp = curr;
        if (s[i] == '0')
            if (s[i - 1] == '1' || s[i - 1] == '2') curr = pre;
            else return 0;
        else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
            curr = curr + pre;
        pre = tmp;
    }
    return curr;
}
```

# [221. 最大正方形](https://leetcode-cn.com/problems/maximal-square/)
>若某格子值为 1，则以此为右下角的正方形的、最大边长为：上面的正方形、左面的正方形或左上的正方形中，最小的那个，再加上此格。

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int row=matrix.size(), col=matrix[0].size();
        if(col == 0) return 0;

        int ans = matrix[0][0] - '0';
        int i, j;
        for(i=0; i<row; i++) {
            for(j=0; j<col; j++) {
                if(i==0 || j==0) {
                    ans = max(ans, matrix[i][j]-'0');
                    continue;
                }
                if(matrix[i][j]!='0' && matrix[i-1][j]!='0' && matrix[i][j-1]!='0' && matrix[i-1][j-1]!='0') {
                    matrix[i][j] = help(matrix[i][j-1]-'0', help(matrix[i-1][j]-'0', matrix[i-1][j-1]-'0'))+1+'0';
                }

                ans = max(ans, matrix[i][j]-'0');
            }
        }

        return pow(ans, 2);
    }

    int help(int a, int b) {
        return a<b?a:b;
    }
};
```

# 买卖股票系列
## [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)
自己能想到的方法是暴力法，套两层循环做，时间复杂度是O(n*n)，下面O(n)方法中，使用minp记录当天之前的最小值，然后假设当天卖能赚多少钱，一次比较得出最大值。
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profile=0, minp=INT_MAX;
        for(int p:prices) {
            if(p < minp) minp = p;
            else if(profile < (p-minp))
                profile = p-minp;
        }

        return profile;
    }
};

class SolutionV1 {
public:
    int maxProfit(vector<int>& prices) {
        int i, j, res = 0;
        if(prices.size() <= 1) return res;

        for(i=0; i<prices.size()-1; i++) {
            for(j=i+1; j<prices.size(); j++)
                if(res<=prices[j]-prices[i])
                    res = prices[j]-prices[i];
        }

        return res;
    }
};
```

## [122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)
>可以对此交易

下面的代码本质上思路是一致的，V1里面的思路是找波峰和波谷。V0的代码中，如果价格递增，后面的值会覆盖前面的值，从而达到波峰的目的。
```cpp
class SolutionV0 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int i, ans=0;
        for(i=1; i<prices.size(); i++) {
            if(prices[i] > prices[i-1])
                ans += prices[i]-prices[i-1];
        }

        return ans;
    }
};

class SolutionV1 {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, size=prices.size();
        if(size <= 1) return ans;

        int i=0, low=prices[0], high=prices[0];
        while(i < size-1) {
            while(i<size-1 && prices[i] >= prices[i+1]) i++;
            low = prices[i];
            while(i<size-1 && prices[i] <= prices[i+1]) i++;
            high = prices[i];

            ans += high-low;
        }

        return ans;
    }
};
```

## [123. 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)
>值允许交易两次

参考[Clark](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/xiao-bai-tong-su-yi-dong-de-jie-fa-by-clark-12/)题解。

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1=INT_MAX, b2=INT_MAX;
        int p1=0, p2=0;

        for(int p:prices) {
            b1 = min(b1, p);
            p1 = max(p1, p-b1);
            b2 = min(b2, p-p1);
            p2 = max(p2, p-b2);
        }

        return p2;
    }
};
```

# [10. 正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/)
不是很好理解，使用dp[i][j]表示s[i]和p[j]是否匹配，然后迭代。


```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        s = " " + s;
        p = " " + p;
        int m=s.size(), n=p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s[i-1]==p[j-1] || p[j-1]=='.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if(p[j-1] == '*') {
                    if(p[j-2]!=s[i-1] && p[j-2]!='.') {
                        dp[i][j] = dp[i][j-2];
                    } else {
                        dp[i][j] = dp[i][j-1] || dp[i][j-2] || dp[i-1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};
```

和下面的`编辑距离`方法和dp结构类似。

# [72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/)
这个题目本身比较有趣，代码还不能完全理解，慢慢悟
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m, n;
        n = word1.length();
        m = word2.length();
        if(m*n == 0) return m+n;

        int dp[n+1][m+1];
        for(int i=0; i<n+1; i++) dp[i][0] = i;
        for(int j=0; j<m+1; j++) dp[0][j] = j;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                int left = dp[i-1][j]+1;
                int down = dp[i][j-1]+1;
                int ld = dp[i-1][j-1];
                if(word1[i-1] != word2[j-1]) ld++;

                dp[i][j] = min(left, min(down, ld));
            }
        }

        return dp[n][m];
    }
};
```