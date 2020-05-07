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

## 合并K个数组
这道题目难度级别是`困难`，我第一次遇到时也是束手无策，找不到突破口。后来做了`合并两个链表`后再回来看题目，结合别人的题解做出来了。

这道题目难的是思路，我们在没有思路的时候可以把问题划分成多个子问题，通过子问题的解决来处理整个问题。这就是分治的思想。

即先写一个辅助函数，合并两个链表，返回合并后的链表头，然后遍历K的链表数组。关于如何遍历有多种方法，我用的是线性遍历，看到别人的代码有用Login遍历的。我把代码放出来就理解了。

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* help(ListNode *a, ListNode *b) {
        if(!a) return b;
        if(!b) return a;

        ListNode *cur, *dummy = new ListNode(-1);
        cur = dummy;
        while(a && b) {
            if(a->val < b->val) {
                cur->next = a;
                cur = cur->next;
                a = a->next;
            } else {
                cur->next = b;
                cur = cur->next;
                b = b->next;
            }
        }
        cur->next = (a==nullptr)?b:a;

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i, len=lists.size();
        if(len == 0) return nullptr;
        if(len == 1) return lists[0];

        ListNode *p1, *p2;
        queue<ListNode*> q;
        for(i=0; i<len; i++) q.push(lists[i]);

        // 利用队列每次拿出来2个合并，降低复杂度
        while(q.size()>1) {
            p1 = q.front();q.pop();
            p2 = q.front();q.pop();
            q.push(help(p1, p2));
        }

        return q.front();
    }

    // 我这个是线性遍历
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i, len=lists.size();
        if(len == 0) return nullptr;
        if(len == 1) return lists[0];
        ListNode *dummy = lists[0];

        for(i=1; i<len; i++) {
            dummy = help(dummy, lists[i]);
        }

        return dummy;
    }
};
```