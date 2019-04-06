/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.18%)
 * Total Accepted:    61.1K
 * Total Submissions: 164K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> v;
        int i;
        char c, o;
        for(i=0; i<s.length(); i++) {
            if(i == 0) v.push(s[i]);
            else {
                c = s[i];
                if(c=='(' || c=='[' || c=='{') {
                    v.push(c);
                    continue;
                }
                if(v.empty()) {
                    v.push(c);
                    continue;
                }

                o = v.top();
                if(o=='(' && c==')') v.pop();
                else if(o=='[' && c==']') v.pop();
                else if(o=='{' && c=='}') v.pop();
                else v.push(c);
            }
        }
        
        return v.empty();
    }
};

