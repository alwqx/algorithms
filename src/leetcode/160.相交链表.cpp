/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *na=headA, *nb=headB;
        while(na != nb) {
            na = (na!=NULL)?na->next:headB;
            nb = (nb!=NULL)?nb->next:headA;
        }

        return na;
    }
};

class SolutionV1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *res;
        if(headA==NULL || headB==NULL) return res;

        ListNode *na=headA, *nb=headB;
        while(na!=NULL) {
            while(nb!=NULL) {
                if(na == nb) return na;
                else nb = nb->next;
            }
            na = na->next;
            nb = headB;
        }

        return res;
    }
};

