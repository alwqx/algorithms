/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (53.63%)
 * Total Accepted:    57.3K
 * Total Submissions: 106.8K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;

//     ListNode(int x) : val(x), next(NULL) {}
// };

class SolutionV1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ph = new ListNode(0);
        ListNode *cur = ph;
        
        while(l1 && l2) {
            if(l1->val < l2->val) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            } else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }

        cur->next = (l1==NULL)?l2:l1;

        return ph->next;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode *ph;
        if(l1->val < l2->val) {
            ph = l1;
            ph->next = mergeTwoLists(l1->next, l2);
        } else {
            ph = l2;
            ph->next = mergeTwoLists(l1, l2->next);
        }

        return ph;
    }
};

