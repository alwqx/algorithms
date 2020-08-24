# 最长序列问题


# [674. 最长连续递增序列](https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/)
## 动态规划
找到状态和状态转移方程dp[i]表示索引为i的元素对应的连续LIS，dp[i+1]的结果为：
1. dp[i]+1      n[i+1]>n[i]
2. 1            n[i+1]<=n[i]

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int i, ans=1;
        vector<int> dp(nums.size(), 1);
        for(i=1; i<nums.size(); i++)
            if(nums[i] > nums[i-1]) {
                dp[i] = dp[i-1]+1;
                ans = max(ans, dp[i]);
            }

        return ans;
    }
}
```

## DP优化
我们发现每次执行中的dp只和前一个dp有关，因此可以使用一个变量，把空间复杂度降为O(1)。

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int i, ans=1, cnt=1;
        for(i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                cnt++;
                ans = max(ans, cnt);
            } else cnt = 1;
        }

        return ans;
    }
}
```

## 双指针滑动窗口法
```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;

        int i=0, j=1, ans=1;
        while(j < n) {
            while(j<n && nums[j]>nums[j-1]) j++;
            ans = max(ans, j-i);
            i = j;
            j++;
        }

        return ans;
    }
}
```

滑动窗口的另一种写法：
```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;

        int i=0, j=0, ans=1;
        for(; i<n; i++) {
            if(i>=1 && nums[i]<=nums[i-1]>) j=i;
            ans = max(ans, i-j+1);
        }

        return ans;
    }
}
```

# [300. 最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)
## DP
关键在于定义状态和找到状态间的转移方程，我们用dp[i]表示以元素n[i]结尾的上升子序列的长度

更新dp[i]需要找到`0<=j<i`中所有的n[j]<n[i]中最大的那个dp[j]+1，遍历结束后返回最大的那个数。

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;

        int i, j, ans=1;
        // 每个元素自身满足条件，所以默认值为1
        vector<int> dp(n, 1);
        for(i=0; i<n; i++) {
            for(j=0; j<i; j++) {
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j]+1);
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
}
```

## Tail
这个思路是参考[LeetCode用户liweiwei1419](https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/)的题解。思路也是动态规划，只不过含义和上面的不同，这里也能看出来DP法的核心是**定义状态和状态间的转移方程**。

tail数组表示长度相同的LIS中末尾元素虽小的那个，遍历nums数组更新tail的值(追加/更新已有值)，最后tail数组的长度就是所求。

因为tail数组长度是从0开始的，所以tail[i]表示长度为i+1的LIS中末尾元素最小的那个。

初始化时，tail[0] = nums[0]，后续遍历过程中：
1. 如果nums[i]严格大于tail[end]，则追加
2. 否则在tail数组中找是否有元素等于nums[i]，如果有则不操作，如果没有，找第一个大于nums[i]的数，将其更新为小的nums[i]

最后返回tail的长度

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;

        int i, left, right, mid, end=0;
        vector<int> tail(n, 1);
        tail[0] = nums[0];
        for(i=1; i<n; i++) {
            if(nums[i] > tail[end]) {
                tail[++end] = nums[i];
            } else {
                left = 0;
                right = end + 1;
                while(left < right) {
                    mid = (left+right)>>1;
                    if(nums[i] > tail[mid]) left = mid+1;
                    else right = mid;
                }
                tail[left] = nums[i];
            }
        }

        return end + 1;
    }
}
```

上面代码的难点在二分查找中的边界与停止条件，因为要找的数要么和nums[i]相等，要么是第一个大于nums[i]的数，所以对right进行了放大，取end+1，并且每次right=mid。

# [354. 俄罗斯套娃信封问题](https://leetcode-cn.com/problems/russian-doll-envelopes/)
这是二维LIS问题，要转化成一维来做，关键是如何降维

```cpp
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n < 2) return n;

        int i, j;
        vector<int> dp(n, 1);
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] != b[0]) return a[0]<b[0];
            return a[1]>b[1];
        });

        for(i=0; i<n; i++) {
            for(j=0; j<i; j++) {
                if(envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
}
```

上面的代码中，为什么对w升序，对h降序？

一维w升序后，求LIS w就不再考虑了，但是比较h时，如果w相等，h升序，会重复计算，所以对h降序。

# [673. 最长递增子序列的个数](https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/)
## 300DP改进
这道题目的思路应该和`300 最长上升子序列`的思路类似，只是需要结合题目进行改进。在使用dp数组表示`以nums[i]为结尾的上升子序列的最大长度`基础上，引入cnt数组，`cnt[i]表示以nums[i]为结尾的最大上升子序列的个数`，在动态规划的过程中不断更新dp和cnt。

cnt和dp的默认值都是1，cnt数组记录的是最大长度的个数。

```cpp
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return size;

        int i, j;
        vector<int> dp(size, 1);
        vector<int> cnt(size, 1);
        for(j=0; j<size; j++) {
            for(i=0; i<j; i++) {
                // 当j>i且nums[j]>nums[i]，把nums[j]附加到以nums[i]为结尾的最大子序列的后面，形成新的子序列。
                if(nums[j] > nums[i]) {
                    // 如果j的序列长度比i小，则j的长度为i加一，且j的数量等于i的数量
                    // 取=是因为初始化时大家是相等的，要考虑这个情况
                    if(dp[j] <= dp[i]) {
                        dp[j] = dp[i] + 1;
                        cnt[j] = cnt[i];
                    // 如果j的长度和新的长度相等，则加到后面
                    // 这块感觉还不是很理解...
                    } else if(dp[i]+1 == dp[j]) cnt[j] += cnt[i];
                }
            }
        }

        int mlen = *max_element(dp.begin(), dp.end());
        int ans = 0;
        for(i=0; i<size; i++) {
            if(dp[i] == mlen) ans += cnt[i];
        }

        return ans;
    }
}

```

## 线段树
TODOs