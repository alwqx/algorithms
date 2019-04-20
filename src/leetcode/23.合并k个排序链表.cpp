/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (44.38%)
 * Total Accepted:    20.3K
 * Total Submissions: 45.2K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
class SolutionV1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode*& a, ListNode*& b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(auto node:lists) {
            if(node) pq.push(node);
        }

        ListNode *dummy=new ListNode(-1), *cur=dummy;
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            cur->next = t;
            cur = cur->next;

            if(cur->next) pq.push(cur->next);
        }

        return dummy->next;
    }
};

class SolutionV2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        int i, len=lists.size();
        for(i=0; i<len; i++) {
            ListNode* pt = lists[i];
            while(pt) {
                v.push_back(pt->val);
                pt = pt->next;
            }
        }

        sort(v.begin(), v.end());
        ListNode *dummy=new ListNode(-1), *cur=dummy;
        for(i=0; i<v.size(); i++) {
            cur->next = new ListNode(v[i]);
            cur = cur->next;
        }

        return dummy->next;
    }
};

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *p, *cur, *p1=l1, *p2=l2;
        p = new ListNode(-1);
        cur = p;

        while(p1!=NULL && p2!=NULL) {
            if(p1->val < p2->val) {
                cur->next = p1;
                p1 = p1->next;
                cur = cur->next;
            } else {
                cur->next = p2;
                p2 = p2->next;
                cur = cur->next;
            }
        }

        if(p1 == NULL) cur->next=p2;
        else cur->next=p1;

        return p->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ret = new ListNode(0);
        ret = ret->next;

        int i;
        for(i=0; i<lists.size(); i++)
            ret = merge(ret, lists[i]);
        
        return ret;
    }
};

/*
# 思路分析
## 暴力

## 堆
*/
