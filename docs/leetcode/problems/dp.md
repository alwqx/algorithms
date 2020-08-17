# 动态规划
[leetcode dp tags](https://leetcode-cn.com/tag/dynamic-programming/)

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

# [221. 最大正方形](https://leetcode-cn.com/problems/maximal-square/)

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