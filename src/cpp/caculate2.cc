/* Given a string `s` which represents an expression, evaluate this expression and return its value.
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate results will be in the range of [-2^(31), 2^(31)-1].
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as `eval()`.

Example 1:
Input: s = "1*2+3*4-0"
Output: 14

Example 2:
Input: s = " 3/2 "
Output: 1

Example 3:
Input: s = " 3+15 / 2 "
Output: 10

Hint:

1. 1 <= s.length <= 300000
2. `s` consists of integers and operators `('+', '-', '*', '/')` separated by some number of spaces.
3. s represents a valid expression.
4. All the integers in the expression are non-negative integers in the range [0, 2^(31) - 1].
5. The answer is guaranteed to fit in a 32-bit integer.

leetcode 227. 基本计算器2 https://leetcode.cn/problems/basic-calculator-ii/description/
*/

#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool isnum(char c)
{
    return c >= '0' && c <= '9';
}

int caculate(string str)
{
    int n = str.size();
    stack<int> stk;
    int i = 0;
    while (i < n)
    {
        char c = str[i];
        if (c == ' ')
        {
            i++;
            continue;
        }

        if (isnum(c))
        {
            int j = i, a = 0;
            for (j = i; j < n && isnum(str[j]); j++)
            {
                a = a * 10 + str[j] - '0';
            }
            i = j;
            // cout << "a=" << a << " j=" << j << endl;
            if (stk.empty())
            {
                stk.push(a);
                continue;
            }

            char op = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();

            if (op == '*')
            {
                stk.push(b * a);
            }
            else if (op == '/')
                stk.push(b / a);
            else
            {
                stk.push(b);
                stk.push(op);
                stk.push(a);
            }
        }
        else
        {
            stk.push(c);
            i++;
        }
    }

    stack<int> reverse;
    while (!stk.empty())
    {
        reverse.push(stk.top());
        stk.pop();
    }
    while (reverse.size() > 1)
    {
        int a = reverse.top();
        reverse.pop();
        int op = reverse.top();
        reverse.pop();
        int b = reverse.top();
        reverse.pop();
        if (op == '+')
            reverse.push(a + b);
        else
            reverse.push(a - b);
    }

    return reverse.top();
}

int main()
{
    string str = "1-0";
    cout << caculate(str) << endl;

    str = "1*2+3*4-0";
    cout << caculate(str) << endl;

    str = " 3/2 ";
    cout << caculate(str) << endl;

    str = " 3+15 / 2 ";
    cout << caculate(str) << endl;

    str = " 3+15 / 2 +     90 -  29 /2";
    cout << caculate(str) << endl;

    return 0;
}