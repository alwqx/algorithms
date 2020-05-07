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

/*
自己的代码中res没有初始化为NULL，如果没有相交的话返回未初始化的值，打分程序会报错
*/
class SolutionV2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        map<ListNode *, int> m;
        ListNode *res=NULL, *ta=headA, *tb=headB;
        while(ta || tb) {
            if(ta) {
                m[ta]++;
                ta = ta->next;
            }
            if(tb) {
                m[tb]++;
                tb=tb->next;
            }
        }

        for(auto it=m.begin(); it!=m.end(); it++) {
            if(it->second==2) {
                res = it->first;
                break;
            }
        }

        return res;
    }
};

