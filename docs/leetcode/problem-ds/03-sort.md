# 排序

# [56. 合并区间](https://leetcode-cn.com/problems/merge-intervals/)
自己的思路是先排序，然后使用滑动窗口/双指针做，提交4-5次出现一些没有考虑的情况。最后改改通过了。

核心思路是找到待合并区间最后的left和right，然后加到结果中。

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int l=0, r=0, size=intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int right;

        while(l < size) {
            right = -1;
            while(r<size && (intervals[r][0]<=intervals[l][1] || right>=intervals[r][0])) {
                right = max(right, intervals[r][1]);
                r++;
            }
            r--;
            if(r >= size) break;
            ans.push_back({intervals[l][0], right});
            r += 1;
            l = r;
        }

        return ans;
    }
};
```

参考了一个人的答案，思路是一样的，但是对于滑动条件的分类和判断，一位作者的题解很清晰，比我的好
```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals.size() == 1) return intervals;
        // initialize
        int u = 0, v = 0;
        vector<vector<int>> ans;
        // 思路①
        std::sort(intervals.begin(), intervals.end());
        // 思路②
        while (v < intervals.size()) {
            if (intervals[v][0] > intervals[u][1]) {
                ans.emplace_back(intervals[u]);
                u = v;
            } else if (intervals[v][1] <= intervals[u][1]) {
                ++ v;
            } else {
                intervals[u][1] = intervals[v][1];
                ++ v;
            }
        }
        // 思路③
        ans.emplace_back(intervals[u]);
        return ans;
    }
};
/*
作者：wen-mu-yang
链接：https://leetcode-cn.com/problems/merge-intervals/solution/c-ji-yu-two-points-he-pai-xu-de-jian-ji-shi-xian-f/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
```

下面是我自己修改后的代码：
```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end());

        int left=0, right=1;
        while(right<intervals.size()) {
            if(intervals[left][1] < intervals[right][0]) {
                res.emplace_back(intervals[left]);
                left = right;
                right++;
            } else if(intervals[left][1]>=intervals[right][1]) {
                right++;
            } else {
                intervals[left][1] = intervals[right][1];
                right++;
            }
        }
        res.emplace_back(intervals[left]);
        return res;
    }
};
```