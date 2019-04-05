// https://leetcode-cn.com/problems/add-two-numbers/
#include <stdio.h>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void PrintList(ListNode * list) {
    while(list) {
        printf("%d", list->val);
        if(list->next) printf("->");
        list = list->next;
    }

    putchar('\n');
}

ListNode* v1(ListNode* l1, ListNode* l2) {
    int carry, sum, x, y;
    ListNode* pHead = new ListNode(0);
    ListNode *p1=l1, *p2=l2, *ph=pHead;
    
    sum = carry = 0;
    while(p1!=NULL || p2!=NULL) {
        x = (p1!=NULL)?p1->val:0;
        y = (p2!=NULL)?p2->val:0;
        sum = carry + x + y;
        ph->next = new ListNode(sum%10);
        ph = ph->next;
        carry = sum/10;

        /*
        wrond code
        if(p1->next) p1 = p1->next;
        if(p2->next) p2 = p2->next;
        这样会不断累加下去，不会停止
        */
        if(p1) p1 = p1->next;
        if(p2) p2 = p2->next;
    }

    if(carry > 0) ph->next = new ListNode(carry);
    
    return pHead->next;
}

ListNode* v2(ListNode* l1, ListNode* l2) {
    ListNode *pHead = new ListNode(0);  //头节点
    ListNode *p1 = l1,*p2 = l2,*p3 = pHead;
    ListNode *pNext;
    int sum = 0,temp = 0;
    while(p1 != NULL || p2 != NULL)
    {
        int x = (p1 != NULL) ? p1->val : 0;
        int y = (p2 != NULL) ? p2->val : 0;
        sum = x + y + temp;
        temp = sum / 10;
        p3->next = new ListNode (sum % 10);
        p3 = p3->next;
        if(p1 != NULL)
            p1 = p1->next;
        if(p2 != NULL)
            p2 = p2->next;
    }
    if(temp == 1)
    {
        p3->next = new ListNode(1);
    }
    return pHead->next;
}

ListNode* create() {
    int n;
    ListNode* t = new ListNode(0);

    scanf("%d", &n);
    while(n--) {
        scanf("%d", &t->val);
        ListNode* v = new ListNode(0);
        v->next = t;
        t = v;
    }

    PrintList(t->next);
    return t->next;
}

int main() {
    ListNode* L1 = create();
    ListNode* L2 = create();

    ListNode* ret = v1(L1, L2);
    // ListNode* ret = v2(L1, L2);
    PrintList(ret);

    return 0;
}