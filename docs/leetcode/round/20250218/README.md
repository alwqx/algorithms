# 2025-02-18 轮次刷题

leetcode 刷题中收藏的题目见 [round-20250218](https://leetcode.cn/problem-list/FAygP2I2/)

# 刷题记录

## 20250225

树

1. 104
2. 100
3. 226
4. 101
5. 105
6. 106
7. 117
8. 114
9. 112
10. 129

## 20250226

链表

1. 141
2. 2
3. 21
4. 138
5. 206
6. ~~92~~

# DP

## 2209. 用地毯覆盖后的最少白色砖块

[连接](https://leetcode.cn/problems/minimum-white-tiles-after-covering-with-carpets)

### 解题过程

根据题目的样例，自己模拟覆盖过程，希望能从这个过程中找到解析思路。模拟了 2 个样例后，自己的思路是：

1. 分治思想，拆解问题，先把 问题简化为地毯数为 1 的情况
2. 只有 1 个地毯时，肯定是覆盖地毯长度能涵盖的最长白色砖块范围

因此初始的解决方案是

1. 按照地毯数量 carpetNum for 循环
2. 每次对地板 (floor) 选择地毯能覆盖的最大白色砖块范围，置为 0，也就是每次选择 1 个地毯贪心覆盖
3. 遍历 carpetNum 后，统计 floor 中 白色方块的数量并返回

[提交记录](https://leetcode.cn/problems/minimum-white-tiles-after-covering-with-carpets/submissions/601765769/)，对应代码为：

```cpp
class Solution {
public:
    string help(string floor, int carpetLen) {
        int size = floor.size();
        int pos=0, maxNum=0;
        for (int i=0; i<size; i++) {
            int subNum = 0;
            for (int j=0; j<carpetLen && j+i<size; j++) {
                if (floor[i+j] == '1') subNum++;
            }
            if (subNum > maxNum) {
                pos = i;
                maxNum = subNum;
            }
        }

        // 包含 1 最多的区间，置为 0
        for (int j=pos; j<size && j<pos+carpetLen; j++) {
            if (floor[j] == '1') floor[j] = '0';
        }

        return floor;
    }

    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        for (int i=0; i<numCarpets; i++) {
            floor = help(floor, carpetLen);
        }
        int ans = 0;
        for (int i=0; i<floor.size(); i++) {
            if (floor[i] == '1') {ans++;}
        }
        return ans;
    }
};
```

后来发现不对，再次思考，单次覆盖时，选择的方案对当前是最佳的，但是没有结合后续地毯的覆盖整体最佳，也就是**局部最优解未必是全局/整体最优解**。

如果还是这个思路，需要对 地毯数量进行拆分组合，比如有 3 个地毯，用字母 c 表示，则覆盖组合如下：

1. 分别单独覆盖：c,c,c
2. 2 个一组覆盖，剩下 1 个覆盖：cc,c
3. 3 个一组覆盖：ccc

因此需要组合全部情况去覆盖方格，然后在里面选择最优的结果。这样做不仅复杂度会增加，而且实现起来难度会陡增，**也不符合编写简单易懂代码**的思想。因此放弃选择看题解。

### 总结

这次算法准备，距离上次刷题 (2021 年校招）过去 3 年了，一些思想、数据结构、解题思路疏忽了，但底子还在，至少有自己的思路和实现，虽然结果不正确。

但是把思维过程记录下来，是因为自己的思路和枚举过程，和动态规划的思想很接近了，也可以很好地帮助自己理解 DP。

根据这个题目，我理解的 DP 是：

1. 目标结果很复杂，需要找到所有的情况，记录该情况下的结果，然后选择最优的结果，并返回。
2. 1 中的实现在思路上没问题，在实现上有难度：
   - 时间复杂度高
   - 空间复杂度高
   - 有很多冗余的计算过程：很多方案不是最优的，没有要统计结果，需要剪枝
3. DP 就是把主动枚举全部情况，改为通过状态转移的方式，去寻找最优的情况：最优结果由前 1 到多个结果，比较得出，这样逆向迭代反推最终结果。行话叫找到**状态转移方程**，找到转移方程的核心，是理解问题的主动解决过程（枚举全部情况，找到最优解），从而对问题抽象。

**把原问题，变成一个和原问题相似，规模更小的子问题**。

### 滚动数组优化

先看不使用滚动数组的代码：

```cpp
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        if (numCarpets*carpetLen >= n) return 0;

        vector<vector<int>> dp(n+1, vector<int>(numCarpets+1, n));
        for(int i=0; i<=numCarpets; i++) dp[0][i] = 0;
        // floor[i-1] 对应第 i 个位置的方块，所以下标是 i-1
        for(int i=1; i<=n; i++) dp[i][0] = dp[i-1][0] + (floor[i-1]=='1');

        // i 从 1 开始，实际上是从第一个位置顺序开始铺地毯
        // j 从 1 开始，也是从 1 个地毯开始铺
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=numCarpets; j++) {
                // floor[i-1] 对应第 i 个位置的方块，所以下标是 i-1
                dp[i][j] = dp[i-1][j] + (floor[i-1]=='1');
                dp[i][j] = min(dp[i][j], dp[max(0, i-carpetLen)][j-1]);
            }
        }

        return dp[n][numCarpets];
    }
};
```

转移过程有 2 种方案：

1. **从方块开始迭代**

```cpp
// i 从 1 开始，实际上是从第一个位置顺序开始铺地毯
// j 从 1 开始，也是从 1 个地毯开始铺
for(int i=1; i<=n; i++) {
    for(int j=1; j<=numCarpets; j++) {
        // floor[i-1] 对应第 i 个位置的方块，所以下标是 i-1
        dp[i][j] = dp[i-1][j] + (floor[i-1]=='1');
        dp[i][j] = min(dp[i][j], dp[max(0, i-carpetLen)][j-1]);
    }
}
```

2. **从地毯数量开始迭代**

```cpp
// i 从 1 开始，实际上是从第一个位置顺序开始铺地毯
// j 从 1 开始，也是从 1 个地毯开始铺
for(int j=1; j<=numCarpets; j++) {
    for(int i=1; i<=n; i++) {
        // floor[i-1] 对应第 i 个位置的方块，所以下标是 i-1
        dp[i][j] = dp[i-1][j] + (floor[i-1]=='1');
        dp[i][j] = min(dp[i][j], dp[max(0, i-carpetLen)][j-1]);
    }
}
```

减少空间复杂度，为什么能用滚动数组，以 floor="101111"，numCarpets=2，carpetLen=3 为例子。

不使用滚动数组，方块长度 n=6，地毯数量为 2，dp[n+1][num+1] 为 dp[7][3]：

| 序号 | 盖 0 个毯子 | 盖 1 个毯子 | 盖 2 个毯子 |
| :--: | :---------: | :---------: | :---------: |
|  0   |      0      |      0      |      0      |
|  1   |      1      |      0      |      0      |
|  2   |      1      |      0      |      0      |
|  3   |      2      |      0      |      0      |
|  4   |      3      |      1      |      0      |
|  5   |      4      |      1      |      0      |
|  6   |      5      |      2      |      0      |

上面就是整个状态转移表，如果从列看的话，每一列的计算过程只依赖左边一列的数据，对应于：

1. 盖 1 个毯子的数据，只依赖盖 0 个毯子的数据
2. 盖 2 个毯子的数据，只依赖盖 1 个毯子的数据
3. 盖 N 个毯子的数据，只依赖盖 (N-1) 个毯子的数据

因此可以使用 2 个数组，d 和 p：

1. d 表示前 1 列（盖 N-1 个毯子）状态数据
2. p 表示当前盖 N 个毯子的数据
3. 迭代算出 p 后，将 p 赋值给 d，p 重新初始化，开始下一轮 (N+1 个毯子）迭代
4. 在盖 N+1 个毯子时，d 已经变成 N 个毯子的数据了

因此可以使用 2 个数组，而不是 dp[n][m] 个空间。但是每轮迭代后要将 p 赋值给 d，需要额外的计算量，相当于用时间换空间。

而且这种滚动数组的方法，要从按列迭代（地毯数量）开始

```cpp
// i 从 1 开始，实际上是从第一个位置顺序开始铺地毯
// j 从 1 开始，也是从 1 个地毯开始铺
for(int j=1; j<=numCarpets; j++) {
    for(int i=1; i<=n; i++) {
        // floor[i-1] 对应第 i 个位置的方块，所以下标是 i-1
        dp[i][j] = dp[i-1][j] + (floor[i-1]=='1');
        dp[i][j] = min(dp[i][j], dp[max(0, i-carpetLen)][j-1]);
    }
}
```

### 发散

这个场景还可以复杂化，就是地毯长度不固定，这时该如何处理？
