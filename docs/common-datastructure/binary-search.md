# 二分查找
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
1. [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)