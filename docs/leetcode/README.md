# 算法学习/复习与面试

# 元思考

1. 如何学习算法与数据结构
2. 如何通过公司的面试？头条、阿里、微软、招行、intel 等公司的算法面试部分

个人觉得应该从`基础知识`和`动手实践`两部分入手，同时要注意**思想方法的归纳总结**。

基础知识从刷 LeetCode 和之前的 algorithm 这个 repo 入手，动手实践不仅是参加 LeetCode 编程挑战赛，还要能够从实际应用中找到练习的内容，这里主要参考 [巩鹏-我的算法学习之路](http://lucida.me/blog/on-learning-algorithms/)。

# 有效复习方法

1. 熟悉基础的 CPP 数据结构和操作，思想方法，按照室友帆洋的做法，就是整理模板
2. 根据 1 中的数据结构和模板刷 LeetCode
3. 根据 20/80 原则，整理算法中的常用基础、重要的知识
4. 做一些重要的算法应用

## 常用数据结构与算法思想

- 数组
- 链表
- 栈
- 队列
- 排序
  - 快排
  - 归并排序
- 并查集 UF
- 树
  - 3 种遍历
  - dfs
  - bfs
- 图
  - 遍历 dfs bfs
  - 路径（联通性问题）
  - 入度/出度
- 字符串
- DFS
- BFS
- 回溯
- 动态规划

## 问题分类

> 只列出自己没有思路或者很重要的问题

- [剑指 Offer 系列](/leetcode/problem-ds/offer_sword)
- [数组系列](/leetcode/problem-ds/00-array)
- [树系列](/leetcode/problem-ds/02-tree)
- [链表系列](/leetcode/problem-ds/00-linked_list)
- [动态规划系列](/leetcode/problem-algo/02-dp)
- [设计系列](/leetcode/problem-ds/design)
- [图问题汇总：遍历和回溯、DFS 和 BFS](/leetcode/problem-ds/02-graph)
- [序列问题](/leetcode/problem-algo/00-sequential)
- [674 300 354. LIS 问题](/leetcode/problem-algo/00-lis)
- [215. 数组中的第 K 个最大元素](/leetcode/problems/215-kth-largest-element)
- [547. 朋友圈](/leetcode/problems/547-friend-circles)
- [面试题 43. 1~n 整数中 1 出现的次数](/leetcode/problems/offer-43-calculate-one)
- [面试题 33. 二叉搜索树的后序遍历序列](/leetcode/problems/offer-33)
- [面试题 60. n 个骰子的点数](/leetcode/problems/offer-60)
- [海量数据中寻找中位数](https://zhuanlan.zhihu.com/p/75397875)

## 待提高

- 数组前缀和的用法
- 单调栈的用法
- DFS BFS
- 回溯

# 算法思想方法整理

## 看到题目的预备思考

当我在刷题/做算法题，我到底在做什么？

1. 分析问题、解决问题的范式/思考方式
2. 着手写代码前，问清楚问题是什么
   1. 问题的规模
   2. 输入和输出
   3. 边界条件
3. 设计好代码的框架
4. 编写代码+调试

## 常用思路

1. 快慢指针
2. 滑动窗口法，是数组/字符串问题中常用的抽象概念。 窗口通常是在数组/字符串中由开始和结束索引定义的一系列元素的集合，即 [i,j)[i, j)[i,j)（左闭，右开）。而滑动窗口是可以将两个边界向某一方向“滑动”的窗口。例如，我们将 [i,j)[i, j)[i,j) 向右滑动 111 个元素，则它将变为 [i+1,j+1)[i+1, j+1)[i+1,j+1)（左闭，右开）
3. dfs
4. bfs
5. 并查集

# 算法面试

编程面试，**只有高频知识点，没有所谓的高频题**。

**时间不够没必要面面俱到，可以先掌握高频知识点**。

# 刷题轮次

- [2021 年实习/校招](/leetcode/round/round-20210101)
- [2025](/leetcode/round/round-20250218)

# 参考

- [labuladong-fucking-algorithm](https://github.com/labuladong/fucking-algorithm)
- [别再埋头刷 LeetCode 之：北美算法面试的题目分类，按类型和规律刷题，事半功倍](https://zhuanlan.zhihu.com/p/161204634)
- [Grokking the System Design Interview](https://www.educative.io/courses/grokking-the-system-design-interview)
