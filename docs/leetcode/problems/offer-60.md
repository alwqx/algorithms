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