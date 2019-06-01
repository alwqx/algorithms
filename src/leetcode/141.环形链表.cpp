/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */
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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;

        ListNode *slow=head, *quick=head->next;

        while(slow != quick) {
            if(quick==NULL || quick->next==NULL) return false;
            slow = slow->next;
            quick = quick->next->next;
        }

        return true;
    }
};

class SolutionV1 {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> s;
        while(head != NULL) {
            if(s.find(head) != s.end()) return true;
            else s.insert(head);

            head = head->next;
        }

        return false;
    }
};

