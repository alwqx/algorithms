# 二分查找

## 167 两数之和 2 - 输入有序数组

## 153 寻找旋转排序数组中的最小值

[153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)

如下代码，`while(left <= right)`中`=`加和不加是什么区别？最后是如何判断找到了？

```cpp
int i, t, mid, left, right;
for(i=0; i<m; i++) {
    left=0, right=n-1;
    while(left <= right) {
        mid = (left+ right)>>1;
        t = matrix[i][mid];
        if(t == target) return true;
        else if(t > target) right = mid-1;
        else left = mid+1;
    }
}
```

例题：

## 35 搜索插入位置

[35 搜索插入位置](https://leetcode.cn/problems/search-insert-position/)

标准二分查找写法

```cpp
int searchInsert(vector<int> &nums, int target) {
    int l=0, r=nums.size()-1;
    // 为什么是 l<=r 并且最后返回 l 呢？
    // 实在想不出来，就带入特殊值辅助判断下
    while(l<=r) {
        int m = (l-r)/2+l;
        if(nums[mid]<target) {l = m+1;}
        else if(nums[mid]>target) {r = m-1;}
    }
    return l;
}
```
