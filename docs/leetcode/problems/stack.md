# 栈

# [71. 简化路径](https://leetcode-cn.com/problems/simplify-path/)

# [32. 最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)
自己理解错题意了，题目要求是求有效括号的最大长度，不是求有效括号的数量。

当然自己没有想出来咯(要求30分钟内搞定)，参考了[官方题解](https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/)的栈的做法，有两点值得借鉴：
1. stack中存放的是括号对应的下标，这样有利于计算长度，如果存`(`和`)`，则还需要额外信息记录长度
2. stack中默认加了一个-1，方便后续计算

# [331. 验证二叉树的前序序列化](https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/)

没有想到方法，题解也不是熟练理解了，感觉都利用了**二叉树叶子节点数=度为2的节点数+1**这个性质。

另一个性质：**所有节点的入度之和=出度之和**，但是不能直接迭代到最后再判断，因为中间可能不符合条件，但是最后计算下来是符合的。
```cpp
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder == "#") return true;

        int i=0, size=preorder.size();
        int inn=0, out=0;
        while(i < size) {
            if(i == 0) {
                if(preorder[i] == '#') return false;
                while(i<size && preorder[i]!=',') i++;
                out += 2;
                continue;
            }

            if(preorder[i] == ',') {
                i++;
            } else if(preorder[i] == '#') {
                inn += 1;
                i++;
            } else {
                while(i<size && preorder[i]!=',') i++;
                inn += 1;
                out += 2;
            }

            if(i<size-1 && inn>=out) return false;
        }

        return inn == out;
    }
};
```

# [316. 去除重复字母](https://leetcode-cn.com/problems/remove-duplicate-letters/)
这个题目的要求有点绕，首先要理解题目的要求：
1. 去重
2. 保证字典序最小
3. 不改变字母间的相对顺序

[字典序](https://baike.baidu.com/item/%E5%AD%97%E5%85%B8%E5%BA%8F)的含义要好好理解，**然后理解如何去掉一个字符，使得剩下的字典序最小**？

因为字符串的字典序是`从前往后比较`的，所以我们去掉的字符要尽量靠前，把前面较大的字符去掉，让较小的字符尽可能靠前。在这一过程中，还要保证题目中的要求：
1. 去重，如果该字符只出现一次，则不能去除
2. 不改变字符间的相对顺序，使用单调栈实现。

有了上面的思路作为铺垫，再来看[官方题解](https://leetcode-cn.com/problems/remove-duplicate-letters/solution/qu-chu-zhong-fu-zi-mu-by-leetcode-soluti-vuso/)就好理解一些了。

但还是要多看看。`这题的思路和方法特别是单调栈的用法我还是有点陌生`。

# [227. 基本计算器 II](https://leetcode-cn.com/problems/basic-calculator-ii/)
明确题目的含义再想解决方案，自己一开始不是很懂，就想着遍历字符串，得到数字和对应的符号，分别入栈，然后比较运算符的优先级进行动态计算。但是逻辑不自洽，有了代码框架，却无法实现功能。
```cpp
class Solution {
private:
    bool isnum(char c) {
        return c>='0' && c<='9';
    }

    bool isop(char c) {
        if(c=='+' || c=='-' || c=='/' || c=='*') return true;
        return false;
    }

    // 比较操作符a的优先级是否大于b
    // 一定是大于，不能等于
    bool checkop(char a, char b) {
        if(a=='*' || a=='/') {
            if(b=='+' || b=='-') return true;
        }
        return false;
    }

    int calc(int a, int b, char c) {
        if(c == '+') return a+b;
        if(c == '-') return a-b;
        if(c == '/') return a/b;

        return a*b;
    }

    // 从字符串s的pos位置开始，拿到对应的数字
    int getnum(string s, int& pos) {
        int n=0, i=*pos;
        char c = s[i];
    }

public:
    int calculate(string s) {
        stack<int> nums, ops;
        int i, size=s.size();
        int a, b, v=0;
        char c;

        for(i=0; i<size; i++) {
            c = s[i];
            if(i == size-1) {
                // 遍历到最后一位，只可能是数字或者空格
                // 将v存储到nums栈中
                if(isnum(c)) v = v*10+c-'0';
                nums.push(v);
                v = 0;
                break;
            }

            if(c == ' ') continue;
            if(isnum(c)) {
                v = v*10 + c-'0';
                continue;
            }

            // 不是最后一位，并且是操作符
            if(isop(c)) {
                nums.push(v);
                v = 0;

                if(ops.empty()){
                    ops.push(c);
                } else {
                    // 这里比较操作符c和ops栈顶操作符的优先级
                    if(checkop(c, ops.top())) {
                        b = nums.top();
                        nums.pop();
                        a = nums.top();
                        nums.pop();

                        nums.push(calc(a, b, c));
                    } else {
                        ops.push(c);
                    }
                }
            }

            char op;
            while(!ops.empty()) {
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                op = ops.top();
                ops.pop();

                nums.push(calc(a, b, op));
            }

            return nums.top();
        }

        return 0;
    }
};
```