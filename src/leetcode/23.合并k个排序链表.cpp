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

/*
暴力法：把所有链表放到数组中，对数组排序，然后构造结果链表

从暴力法来看，面对难的acm题目，不应该被难度“吓到”，而是要把注意力回归到题目本身。
一开始不一定要想到最佳答案，而是想能解决的方案。
*/
class SolutionV1 {
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

/*
优先队列法：和暴力法类似，只不过引入了优先队列，进行动态排序
*/
class SolutionV2 {
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

/*
逐个合并链表，最新的测试集超时，合并的过程使用分治法，但是题目中的分治法我想不起来，
半天也看不懂怎么想出这种代码的。

评论中有人提示使用队列处理分治的思路
*/
class SolutionV3 {
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
        /*ListNode *ret = new ListNode(0);
        ret = ret->next;

        int i;
        for(i=0; i<lists.size(); i++)
            ret = merge(ret, lists[i]);
        
        return ret;*/
        int n, i, len=lists.size();
        if(len == 0) return nullptr;
        if(len == 1) return lists[0];
        n = 1;
        while(n<len) {
            for(i=0; i<len-n; i+=n*2)
                lists[i] = merge(lists[i], lists[i+n]);
            n *= 2;
        }
        
        return lists[0];
    }

    /*
    队列法
    */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i, len=lists.size();
        if(len == 0) return nullptr;
        if(len == 1) return lists[0];

        queue<ListNode*> q;
        for(i=0; i<len; i++)
            q.push(lists[i]);
        ListNode *p1, *p2;
        while(q.size()>=2) {
            p1 = q.front();q.pop();
            p2 = q.front();q.pop();
            q.push(merge(p1, p2));
        }

        return q.front();
    }
};


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
    ListNode* merge(ListNode *l1, ListNode *l2) {
        ListNode *p, *cur, *p1=l1, *p2=l2;
        p = new ListNode(-1);
        cur = p;
        while(p1 && p2) {
            if(p1->val < p2->val) {
                cur->next = new ListNode(p1->val);
                p1 = p1->next;
                cur = cur->next;
            } else {
                cur->next = new ListNode(p2->val);
                p2 = p2->next;
                cur = cur->next;
            }
        }

        cur->next = (p1==nullptr)?p2:p1;
        ListNode *res = p->next;
        p->next = nullptr;
        return res;
    }

    ListNode* mergedigui(vector<ListNode*>& lists, int left, int right) {
        if(left == right) return lists[left];
        int mid = (left+right)/2;
        ListNode *p1, *p2;
        p1 = mergedigui(lists, left, mid);
        p2 = mergedigui(lists, mid+1, right);
        return merge(p1, p2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n, i, len=lists.size();
        if(len == 0) return nullptr;
        if(len == 1) return lists[0];
        return mergedigui(lists, 0, len-1);
    }
};

/*
# 思路分析
## 暴力

## 堆
*/
