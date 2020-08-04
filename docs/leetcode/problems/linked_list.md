# 链表

# [148. 排序链表](https://leetcode-cn.com/problems/sort-list/)
这个题目很好，考察了链表和归并排序的思路，也考验编程能力。

链表的赋值、交换操作和数据有很大差异，所以自己起初没有想到合适的解法，下面的代码都是在参考别人思路的基础上完成的。

## 字典
时间和空间复杂度都是O(n)，然是思路和代码很好理解。
```cpp

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