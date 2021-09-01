# 链表
- dummy节点的使用
- 字典存储
- 链表考什么？就是哨兵节点+虚拟节点+链表指针的移动
- **链表是链式结构，可以使用数组或者字典转换成顺序存储结构来辅助解决问题**，见143

# [430. 扁平化多级双向链表](https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/)
自己想到可能要用递归或者栈来做，但是没有想出来具体方案。看了官方题解发现要把结构抽象成二叉树来做。厉害厉害，没想到(手动狗头)

无论是递归解法还是使用栈迭代，都是非常好的样例代码，多学习，多练习。
# [143. 重排链表](https://leetcode-cn.com/problems/reorder-list/)
这个问题自己想到了一个解法，就是使用数组将链表顺序化，然后根据索引的关系改变next指针指向。

官方题解提供了另一个解法，就是先找到链表的重点，然后截断，将后半段逆序，然后将两个链表合并。

官方解法相对复杂，**但是考察的知识点很全面**，是一道综合解决方案，[自己的提交](https://leetcode-cn.com/submissions/detail/176945125/)在最后链表合并上有问题，值得多做巩固练习
- 链表找中点
- 链表翻转
- 链表合并

# [173. 二叉搜索树迭代器](https://leetcode-cn.com/problems/binary-search-tree-iterator/)
可控递归的解法不熟悉

# [109. 有序链表转换二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)
这里涉及到递归、二叉树抽象以及平衡树构造与链表关系的等价转换。

需要多做几遍

# [86. 分隔链表](https://leetcode-cn.com/problems/partition-list/)
没有想到最佳的虚拟指针方案。

# [82. 删除排序链表中的重复元素 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/)

使用字典存储，时间和空间都是O(n)，关键是要想出一次遍历就能解决的方案。**自己没有想到用dummy node的思路**。

使用dummy指向head节点，这样简化了后续记录head位置变更的相关逻辑，**这里通过良好的数据结构设计，简化了算法思路和流程**。
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        // 注意这里初始化pre的方法
        ListNode *tmp, *pre = new ListNode(-1, head);
        ListNode *cur = pre;
        int v;
        while(cur->next && cur->next->next) {
            if(cur->next->val == cur->next->next->val) {
                v = cur->next->val;
                while(cur->next && cur->next->val == v) {
                    tmp = cur->next;
                    cur->next = cur->next->next;
                    tmp->next = NULL;
                }
            } else {
                cur = cur->next;
            }
        }

        return pre->next;
    }
};
```


# [148. 排序链表](https://leetcode-cn.com/problems/sort-list/)
这个题目很好，考察了链表和归并排序的思路，也考验编程能力。

链表的赋值、交换操作和数据有很大差异，所以自己起初没有想到合适的解法，下面的代码都是在参考别人思路的基础上完成的。

## 字典
时间和空间复杂度都是O(n)，然是思路和代码很好理解。
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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        map<int, int> m;
        ListNode* cur = head;
        while(cur) {
            m[cur->val]++;
            cur = cur->next;
        }

        int i;
        cur = head;
        auto it = m.begin();
        while(it!=m.end()) {
            for(i=0; i<it->second; i++) {
                cur->val = it->first;
                cur = cur->next;
            }
            it++;
        }

        return head;
    }
};
```

## 归并排序
这思路参考自[Sort List （归并排序链表）](https://leetcode-cn.com/problems/sort-list/solution/sort-list-gui-bing-pai-xu-lian-biao-by-jyd/)，使用了归并排序的思路。

关键点是链表的切分和排序合并，切分上使用`快慢指针`，这里要注意`while(fast->next && fast->next->next)`的判断条件，自己起初写错了，导致编译出错。
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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *fast=head, *slow=head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;

        // return merge(sortList(head), sortList(mid));

        ListNode *left, *right;
        left = sortList(head);
        right = sortList(mid);

        ListNode *h, *ans;
        h = ans = new ListNode(0);
        while(left && right) {
            if(left->val < right->val) {
                h->next = left;
                left = left->next;
            } else {
                h->next = right;
                right = right->next;
            }

            h = h->next;
        }

        h->next = (left?left:right);
        return ans->next;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* head;
        ListNode* next;
        if (l1->val < l2->val) {
            head = l1;
            next = l1;
            l1 = l1->next;
        } else {
            head = l2;
            next = l2;
            l2 = l2->next;
        }

        while (l1 && l2) {
            if (l1->val < l2->val) {
                next->next = l1;
                next = next->next;
                l1 = l1->next;
            } else {
                next->next = l2;
                next = next->next;
                l2 = l2->next;
            }
        }

        next->next = l1 ? l1 : l2;

        return head;
    }
};
```

该方法的时间复杂度为O(n*log(n))，空间复杂度为O(log(n))，不符合题目的O(1)，可以通过迭代法进行改进。

## 迭代法
TBD...