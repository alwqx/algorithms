# 基础算法思想
- 枚举
- 贪心
- 分治
- 排序
- 双指针
- 查找
- 压缩

1. 如何分割字符串 C++

## 999. 可以被一步捕获的棋子数
1. 两层for循环终止时不能只在内部for循环加break，外部也要加。

## 巧用初始化减少循环次数
这个思路是[1200. 最小绝对差](https://leetcode-cn.com/problems/minimum-absolute-difference/)总结来的，很多题解中也用到了。

思路就是先排序，第一遍循环找到最小差，第二次循环把最小差收集起来。下面是我的代码：
```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int i, v = INT_MAX;
        for(i=1; i<arr.size(); i++) {
            v = min(v, arr[i]-arr[i-1]);
        }

        vector<vector<int>> res;
        for(i=1; i<arr.size(); i++) {
            if(arr[i]-arr[i-1] == v) {
                res.push_back({arr[i-1], arr[i]});
            }
        }

        return res;
    }
};
```

看到别人的代码自己突然顿悟，可以**只用一次循环**，实时更新结果。在for循环中，如果发现更小的差，**就把之前收集的res丢弃掉**，换成新的值。
优化的解法
```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int i, tmp, v = INT_MAX;

        vector<vector<int>> res;
        for(i=1; i<arr.size(); i++) {
            tmp = arr[i]-arr[i-1];
            if(tmp < v) {
                v = tmp;
                // 这里对res进行了更新
                res = {{arr[i-1], arr[i]}};
            } else if(tmp == v) res.push_back(vector<int>{arr[i-1], arr[i]});
        }

        return res;
    }
};
```

上述思想还可以用在很多地方，比如一个数组中有多个最小值，请你都找出来...
```cpp
class Solution {
    public:
    vector<int> findMin(vector<int>& nums) {
        int tmp = INT_MIN;
        vector<int> res;
        for(int n:nums) {
            if(tmp < n) {
                tmp = n;
                res = {n};
            } else if(tmp == n) res.emplace_back(n);
        }

        return res;
    }
}
```