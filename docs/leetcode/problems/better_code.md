# 最佳代码

之前面试了微软亚研的岗位，面试官提出了代码要简洁、尽量包含较少的变量，逻辑设计要合理，以便后期维护和扩展。

这里列举一些LeetCode上的题目，我自己的解法`有很大的优化空间`，并列出找到的相对更好的解法。

# [80. 删除有序数组中的重复项 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/)

我的解法：
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> m;
        for(auto n:nums) m[n]++;
        int cur=0, tot=nums.size();
        for(auto it:m) {
            int up = 0;
            if(it.second<=2) {
                up = it.second;
            } else {
                up = 2;
                tot -= (it.second-2);
            }

            for(int j=0; j<up; j++) nums[cur++] = it.first;
        }

        return tot;
    }
};
```

相对较好的解法：
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, j=1, cnt=1;
        for(; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]) cnt++;
            else cnt = 1;

            if(cnt <= 2) nums[j++] = nums[i];
        }

        return j;
    }
};
```

# [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)
这里面需要注意的是map在遍历过程中的容量是逐渐递增的，找到了就停下来。

另一种做法是遍历完数组后再判断，这样map的容量可能大一些。
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        int i, v;
        vector<int> ans;
        for(i=0; i<nums.size(); i++) {
            int v = target - nums[i];
            if(m.count(v)) {
                ans = {m[v], i};
                break;
            }
            m[nums[i]] = i;
        }

        return ans;
    }
};
```

# [56. 合并区间](https://leetcode-cn.com/problems/merge-intervals/)
官方的代码更`优`，精简且好理解。

# [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)

# LC contest 246 2
[5789. 你完成的完整对局数](https://leetcode-cn.com/contest/weekly-contest-246/problems/the-number-of-full-rounds-you-have-played/)
```cpp
class Solution {
public:
    int numberOfRounds(string s, string t) {
        int a, b, cnt=0;
        a = stoi(s.substr(0, 2))*60 + stoi(s.substr(3));
        b = stoi(t.substr(0, 2))*60 + stoi(t.substr(3));
        if(b<a) b += 24*60;

        for(int i=a/15*15; i<=b; i+=15) {
            if(a<=i && i<=b && i+15<=b) cnt++;
        }

        return cnt;
    }
};
```