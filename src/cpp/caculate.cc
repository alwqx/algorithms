// leetcode 224. 基本计算器 https://leetcode.cn/problems/basic-calculator/
#include <string>
#include <stack>
#include <iostream>

using namespace std;

int caculate(string s)
{
    int i = 0, n = s.size();
    stack<int> ops;
    ops.push(1);
    int ans = 0, sign = 1, c;
    long num;

    while (i < n)
    {
        c = s[i];
        if (c == ' ')
        {
            i++;
        }
        else if (c == '+')
        {
            sign = ops.top();
            i++;
        }
        else if (c == '-')
        {
            sign = -ops.top();
            i++;
        }
        else if (c == '(')
        {
            ops.push(sign);
            i++;
        }
        else if (c == ')')
        {
            // 括号内的符号失效，出栈
            ops.pop();
            i++;
        }
        else
        {
            num = 0;
            for (; i < n && isdigit(s[i]); i++)
                num = 10 * num + s[i] - '0';
            ans += sign * num;
        }
    }

    return ans;
}

int main()
{
    string s = "1+2";
    cout << s << "=" << caculate(s) << endl;

    s = "2-1 + 2 ";
    cout << s << "=" << caculate(s) << endl;

    s = "(1+(4+5+2)-3)+(6+8)";
    cout << s << "=" << caculate(s) << endl;
}

/*
参考的题解，因为表达式只有 + - ()，没有涉及乘除运算，所以没有考察优先级。

从题解看，本题考察的**理解括号对应的符号与栈的关系**，每个括号对应的首部符号，在遇到 `(` 时入栈，遇到`)`时出栈。
括号中间的数通过栈首的符号调整最终符号。
*/