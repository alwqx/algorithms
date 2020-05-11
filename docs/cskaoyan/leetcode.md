# LeetCode

## 思路总结
1. 有些题目虽然描述起来让人觉得很难，但是看到问题的本质后就不难了，如561

### 数组
对于数组，常用的方法有：
1. 排序
2. 双指针
3. 使用map和set等

### 链表
1. 快、慢指针
2. 临界值、临界情况的处理

## 栈
### 42
[42. 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)

### 71
[简化路径](https://leetcode-cn.com/problems/simplify-path/description/)

## 堆
### 23
[合并K个排序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/description/)

## 贪心

## 排序

## 树
### 94
[二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)

## 图

## 动态规划

## 分治

## Easy
### 14
[最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/description/)

### 21
[合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

因为是链表，所以不用额外的存储空间

注意递归的方法

### 26
[删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)

1. 双指针法，最简洁的方法

### 27
[移除元素](https://leetcode-cn.com/problems/remove-element)

### 38
[报数](https://leetcode-cn.com/problems/count-and-say)

注意思路

### 53
[最大子序和](https://leetcode-cn.com/problems/maximum-subarray)

## Medium
### 3
[无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/)

自己想到了暴力解法，参考题解理解O(n)的滑动窗口解法

### 5
[最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring)

暴力解法O(n*n*n)，超时
看题解用的中心发散算法。

### 6
[Z 字形变换](https://leetcode-cn.com/problems/zigzag-conversion/description/)

### 11
[盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/description/)

双指针法，从两侧逼近

### 110
[平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree/submissions/)

top 10%的解法很快，要理解

### 111
[二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)

这题解法上有语言上的陷阱，**队列qt在for循环中是不断变化的，不能在for()中取q.size()**，会的到意外的结果。
```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        bool stop = false;
        int i, minLen = 0;
        queue<TreeNode*> qt;
        qt.push(root);
        TreeNode *tmp;

        while(!qt.empty() && !stop) {
            minLen++;
            // qLen = qt.size();
            for(i=0; i<qt.size(); i++) {
                tmp = qt.front();
                qt.pop();

                if(tmp->left==NULL && tmp->right==NULL) {stop=true; break;}
                if(tmp->left) qt.push(tmp->left);
                if(tmp->right) qt.push(tmp->right);
            }
        }

        return minLen;
    }
};
```

### 112
[路径总和](https://leetcode-cn.com/problems/path-sum/)

递归解法理解不深入

### 118
[杨辉三角](https://leetcode-cn.com/problems/pascals-triangle)

杨辉三角快速求法。

### 119
[杨辉三角 II](https://leetcode-cn.com/problems/pascals-triangle-ii/)

利用题目的特点和组合数计算i+1与i的关系快速计算

### 121 122
[买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)
[买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)

### 141
第一次见这种题目
[环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)

### 168
[Excel表列名称](https://leetcode-cn.com/problems/excel-sheet-column-title/)

为什么减1

### 268
[缺失数字](https://leetcode-cn.com/problems/missing-number/)

解法比较多，要拓宽思路

### 448
[找到所有数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/)

### 532
数组中的K-diff数对

### 566
重塑矩阵

### 605
对边界问题的巧妙使用

### 849
到最近的人的最大距离

### 888
公平的糖果交换

### 914
卡牌分组，没有弄清楚问题的本质

### 989
数组形式的整数加法

### 1002
查找常用字符，没想好思路

### 1010
总持续时间可被 60 整除的歌曲，**理解思路**

### 1013
将数组分成和相等的三个部分

### 1018
可被 5 整除的二进制前缀。利用数论知识简化计算

## 链表
### 203
移除链表元素
**经典题目，了解链表操作**

### 206
反转链表，经典题目，多看看

### 237
删除链表中的节点。根据题目要求没看懂题目意思...

### 707
设计链表。基础题目，注意`addAtIndex(int i, int v)`中`i<0`的处理方式