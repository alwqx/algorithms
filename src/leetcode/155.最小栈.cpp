/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
class MinStack {
public:
    stack<int> data;
    int min;
    /** initialize your data structure here. */
    MinStack() {
        min = 0;
    }
    
    void push(int x) {
        if(data.empty()) {
            data.push(x);
            data.push(x);
            min = x;
        } else {
            if(x < min) {
                data.push(x);
                data.push(x);
                min = x;
            } else {
                data.push(x);
                data.push(min);
            }
        }
    }
    
    void pop() {
        if(!data.empty()) {
            data.pop();
            data.pop();
            if(!data.empty() && min<data.top()) min = data.top();
        } else min = INT_MIN;
    }
    
    int top() {
        if(!data.empty()) {
            data.pop();
            int v = data.top();
            data.push(min);
            return v;
        }

        return min;
    }
    
    int getMin() {
        return min;
    }
};

class MinStackV3 {
public:
    stack<int> s;
    stack<int> min;

    /** initialize your data structure here. */
    MinStackV3() {
    }
    
    void push(int x) {
        if(min.empty() || x<=min.top())
            min.push(x);
        s.push(x);
    }
    
    void pop() {
        if(s.top() == min.top())
            min.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};

class MinStackV2 {
public:
    typedef struct StackNode {
        int val;
        StackNode *next, *curmin;
        StackNode(int v) : val(v), next(nullptr), curmin(nullptr) {};
    } SN;

    /** initialize your data structure here. */
    MinStackV2() {
        size = 0;
        cur = nullptr;
        p = nullptr;
    }
    
    void push(int x) {
        p = new SN(x);
        if(size == 0) {
            p->curmin = p;
        } else {
            p->curmin = x<cur->curmin->val?p:cur->curmin;
            p->next = cur;
        }

        size++;
        cur = p;
    }
    
    void pop() {
        p = cur;
        cur = cur->next;
        delete p;
        p = nullptr; // 防止p指向一片已经被删除的区域
        size--;
    }
    
    int top() {
        return cur->val;
    }
    
    int getMin() {
        return cur->curmin->val;
    }

private:
    SN *cur, *p;
    int size;
};

class MinStackV1 {
public:
    typedef struct StackNode {
        int val, curmin;
        StackNode *next;
        StackNode(int v) : val(v), next(nullptr), curmin(v) {};
    } SN;

    /** initialize your data structure here. */
    MinStackV1() {
        cur = nullptr;
        p = nullptr;
        size = 0;
    }
    
    void push(int x) {
        p = new SN(x);
        if(size++) {
            p->curmin = x>cur->curmin?cur->curmin:x;
            p->next = cur;
        }
        cur = p;
    }
    
    void pop() {
        p = cur;
        cur = cur->next;
        delete p;
        p = nullptr;
        size--;
    }
    
    int top() {
        return cur->val;
    }
    
    int getMin() {
        return cur->curmin;
    }
private:
    SN *cur, *p;
    int size;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

