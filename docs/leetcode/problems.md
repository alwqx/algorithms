# 问题列表
>只列出自己没有思路或者很重要的问题

网上已经有非常多关于LeetCode的优秀题解了，**不会的题目自己参考别人的题解，再做的时候发现不会做了，或者想不起来思路了**，这时再去搜索阅读别人的题解思路就浪费了时间。

最后还是决定在理解别人题解的基础上整理自己的思路，自己写出来的再不好也是自己的理解过程，有参考意义，而且也会慢慢内化成自己的。

- [树系列](/leetcode/problems/tree)
- [215. 数组中的第K个最大元素](/leetcode/problems/215-kth-largest-element)
- [674 300 354. LIS问题](/leetcode/problems/lis)
- [547. 朋友圈](/leetcode/problems/547-friend-circles)
- [图问题汇总：遍历和回溯、DFS和BFS](/leetcode/problems/graph)
- [剑指Offer-面试题38. 字符串的排列](/leetcode/problems/offer-38-string-pailie)
- [剑指Offer-面试题46. 把数字翻译成字符串](/leetcode/problems/offer-46-translate-num-to-str)
- [面试题43. 1~n整数中1出现的次数](/leetcode/problems/offer-43-calculate-one)
- [面试题33. 二叉搜索树的后序遍历序列](/leetcode/problems/offer-33)
- [序列问题](/leetcode/problems/sequential)
- [面试题60. n个骰子的点数](/leetcode/problems/offer-60)

## 数组
1. [16. 最接近的三数之和](https://leetcode-cn.com/problems/3sum-closest/)：暴力法，或者排序后利用二分查找
2. [31. 下一个排列](https://leetcode-cn.com/problems/next-permutation/)：起初被题目难倒了，不知道如何入手。后来看解析发现可以用分割法。把问题分成两部分，首先是全降序的，重新排序返回即可；然后非降序里面，从后往前找第一个不递增的元素a，和后面的比a大的最小数b交换，然后从a后面反转数组。
3. [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)：d二分查找中确定重复元素的左右边界
4. [73. 矩阵置零](/leetcode/problems/73)
5. [74. 搜索二维矩阵](/leetcode/problems/74)
6. [75. 颜色分类](/leetcode/problems/75)
7. [80. 删除排序数组中的重复项 II](/leetcode/problems/80)
8. [81. 搜索旋转排序数组 II](/leetcode/problems/81)
9. [90. 子集 II](/leetcode/problems/90)
10. [152. 乘积最大子数组](/leetcode/problems/152)
11. [153. 寻找旋转排序数组中的最小值](/leetcode/problems/153)
12. [162. 寻找峰值](/leetcode/problems/162)