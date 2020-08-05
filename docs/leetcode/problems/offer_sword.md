# 剑指Offer

# 面试题33. 二叉搜索树的后序遍历序列

根据二叉搜索树的性质，找到左子树、右子树的区间，然后递归判断。

```cpp
class Solution {
private:
    vector<int> pr;
public:
    bool helper(int left, int right) {
        if(left >= right) return true;

        int i, j, m;
        for(i=left; pr[i]<pr[right]; i++) {}
        m = i;
        for(; pr[i]>pr[right]; i++) {}

        return i==right && helper(left, m-1) && helper(m, right-1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        int len = postorder.size(); 
        if(len <= 1) return true;
        pr = postorder;
        return helper(0, len-1);
    }
}
```

# 剑指Offer-面试题38. 字符串的排列
感觉对这种题型还不是很熟练，按照ACM学弟的建议，要多写几遍，在理解的基础上，把思路固化成记录。

题目主要有两种思路，一种是交换、dfs的思路，一种是决策树回溯的思路。

交换+dfs是参考[Krahets](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/mian-shi-ti-38-zi-fu-chuan-de-pai-lie-hui-su-fa-by/)的思路和代码，使用set来去重。

```cpp
class Solution {
public:
    vector<string> permutation(string s) {
        if(s.size() == 0) return {};

        set<string> res;
        dfs(s, res, 0);
        return vector<string>(res.begin(), res.end());
    }

    void dfs(string s, set<string>& res, int pos) {
        if(pos == s.size()) {
            res.insert(s);
            return;
        }

        for(int i=pos; i<s.size(); i++) {
            swap(s[i], s[pos]);
            dfs(s, res, pos+1);
            swap(s[i], s[pos]);
        }
    }
}
```

基于决策树的思路，参考[落鲸与鱼](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/hui-su-fa-by-luo-jing-yu-yu/)的思路。通过排序和判断来避免重复(剪枝)。

```cpp
class Solution {
public:
    vector<string> permutation(string s) {
        int len = s.size();
        if(len == 0) return {};

        vector<bool> vis(len, false);
        vector<string> res;
        string track;
        sort(s.begin(), s.end());

        dfs(s, res, vis, track);
        return res;
    }

    void dfs(string s, vector<string>& res, vector<bool>& vis, string track) {
        if(track.size() == s.size()) {
            res.push_back(track);
            return;
        }

        for(int i=0; i<s.size(); i++) {
            if(vis[i]) continue;
            // 下面这行代码至关重要！要好好理解
            if(i>0 && !vis[i-1] && s[i-1]==s[i]) continue;

            vis[i] = true;
            track.push_back(s[i]);
            dfs(s, res, vis, track);
            track.pop_back();
            vis[i] = false;
        }
    }
}
```

# 面试题43. 1～n整数中1出现的次数
这个题目自己没有思路，参考的[Krahets](https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/mian-shi-ti-43-1n-zheng-shu-zhong-1-chu-xian-de-2/)大佬的解法。

Krahets的思路一开始没有理解，后来自己的草稿纸上画了20多分钟，渐渐理解了。其思路是`逐位计算`，根据该位数字的不同，来判断有多少个1，然后累加到结果上。

![](https://pic.leetcode-cn.com/78e60b6c2ada7434ba69643047758e113fa732815f7c53791271c5e0f123687c-Picture1.png)

下面以当前数字cur为0讨论，设数字是`2304`，那么0位为1的数字有`0010~2219`中把0位1去掉，即000~229，一共230个。

然后找规律，判断cur为1，为2-9时的情况。

```cpp
class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        if(n <= 0) return ans;

        int high=n/10, cur=n%10, low=0, digit=1;
        while(high!=0 || cur!=0) {
            if(cur == 0) ans += high*digit;
            else if(cur == 1) ans += high*digit + low + 1;
            else ans += (high+1)*digit;
        }

        low += 10*cur;
        cur = high%10;
        high /= 10;
        digit *= 10;
    }

    return ans;
}
```

**记住这个思路，遇到了现推理**

# 面试题46. 把数字翻译成字符串
这个题目的思路不是很好想，参考了别人的思路，这里自己模拟下。

首先把数字表示成x1x2x3,...,xn的形式，
1. x1,x2,...,x_i-1的方案数为f(i-1)
1. x1,x2,...,x_i-2的方案数为f(i-2)

那么结果为
1. 如果x_i-1x_i这两个数可以翻译，结果为f(i-1)+f(i-2)
2. 如果x_i-1x_i这两个数不可以翻译，结果为f(i-1)

这样整个过程就是一个动态的过程，从一个初始点开始，慢慢动态到最终结果。

```cpp
class Solution {
public:
    int translateNum(int num) {
        int c, n, x, y=num%10, a=1, b=1;
        while(num) {
            num /= 10;
            x = num%10;
            n = 10*x + y;
            c = (n<=9 || n>25)?b:a+b;
            a = b;
            b = c;
            y = x;
        }

        return b;
    }
}
```

下面是递归解法：
```cpp
class Solution {
public:
    int translateNum(int num) {
        if(num < 10) return 1;
        int n = num%100;
        if(n<=9 || n>25) return translateNum(num/10);

        return translateNum(num/10)+translateNum(num/100);
    }
}
```

# 面试题60. n个骰子的点数
题目没有想到解题思路，或者说没有想到如何用dp做。

**用dp[i][j]表示投完i枚色子后，点数和j出现的次数。**

dp[n][j]表示投完n枚色子后，点数和j出现的次数。它等于投n-1枚色子，和为j-1,j-2,...,j-6的次数，这里的1...6表示第n次出现的1-6。

按照上面的思路，从最终状态回溯到初始状态，然后迭代求和，得到最终状态。

初始状态表示投1枚色子，点数1-6的次数，都为1

```cpp
class Solution {
public:
    vector<double> twoSum(int n) {
        int dp[15][70];
        memset(dp, 0, sizeof(dp));
        int i, j, k;
        for(i=1; i<=6; i++) dp[1][i] = 1;

        // 投第几个色子
        for(i=2; i<=n; i++) {
            // 出现的点数
            for(j=i; j<=6*i; j++) {
                for(k=1; k<=6; k++) {
                    if(j-k < 1) break;
                    dp[i][j] += dp[i-1][j-k];
                }
            }
        }

        vector<double> ans(5*n+1);
        int cnt = pow(6, n);
        for(i=n; i<=6*n; i++)
            ans[i-n] = dp[n][i]*1.0/cnt;

        return ans;
    }
};
```

上述代码的时间复杂度是O(n^2)，最里面的循环次数为6是常量。

## Reference
- [【n个骰子的点数】：详解动态规划及其优化方式](https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/solution/nge-tou-zi-de-dian-shu-dong-tai-gui-hua-ji-qi-yo-3/)