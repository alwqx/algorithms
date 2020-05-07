/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
自己没有思路，参考的比人的代码，引入了map，空间复杂度不是O(1)，但是至少AC了...
*/
class SolutionV1 {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        map<int, int> m;
        ListNode *p = head;
        while(p) {
            m[p->val]++;
            p = p->next;
        }

        p = head;
        auto it = m.begin();
        while(it!=m.end()) {
            for(int i=0; i<it->second; i++) {
                p->val = it->first;
                p = p->next;
            }
            it++;
        }

        return head;
    }
};

/*
V2使用到了归并排序和递归，这里的代码涉及归并排序的写法，链表的快慢指针分割，非常基础的代码，必须熟练掌握
*/
class SolutionV2 {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *fast=head, *slow=head, *breakn;
        while(fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            breakn = slow;
            slow = slow->next;
        }
        // split
        breakn->next = NULL;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        return merge(l1, l2);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {

    }
};
// @lc code=end

