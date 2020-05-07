/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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

/*
使用字典统计每个Node的次数，第一个等于2的节点即为所求。
*/

/*
下面的方法参考自官方题解，Floyd方法。思路理解了实际编程实现也有一定难度
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode *fast=head->next->next, *slow=head->next;
        while(fast && fast->next && fast!=slow) {
            fast = fast->next->next;
            slow = slow->next;
        }

        if(fast==NULL || fast->next==NULL) return NULL;
        fast = head;
        while(fast!=slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};
// @lc code=end

