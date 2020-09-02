# 数组
TODO：**加上思路！**

# [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return -1;
        if(nums.size() == 1) return nums[0];

        int mid, l=0, r=nums.size()-1;
        if(nums[r] > nums[0]) return nums[0];

        while(l <= r) {
            mid = l + (r-l)/2;
            if(nums[mid] > nums[mid+1]) return nums[mid+1];
            if(nums[mid-1] > nums[mid]) return nums[mid];

            if(nums[mid] > nums[0]) l = mid+1;
            else r = mid - 1;
        }

        return -1;
    }
};
```

# [154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)

脑袋要灵活，不要陷入**找到最佳解决方法中**，可以先找到简单粗暴的解法，然后慢慢优化。

比如[C++简洁代码（四种方法）](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/cjian-ji-dai-ma-by-orangeman-18/)题解用了4个方法，暴力、排序、二分等。

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid, l=0, r=nums.size()-1;
        while(l < r) {
            mid = (l+r)>>1;
            if(nums[mid] > nums[r]) l = mid+1;
            else if(nums[mid] < nums[r]) r = mid;
            else r--;
        }

        return nums[l];
    }
};
```

为什么这种解法是对的？还有没有其它方法？**不能局限于把问题解决出来，而是要弄明白原理，是否还有其它优化的方法？**

# [31. 下一个排列](https://leetcode-cn.com/problems/next-permutation/)
起初被题目难倒了，不知道如何入手。

后来看解析发现可以用`分割法`。把问题分成两部分，首先是全降序的，重新排序返回即可；然后非降序里面，从后往前找第一个不递增的元素a，和后面的比a大的最小数b交换，然后从a后面反转数组。