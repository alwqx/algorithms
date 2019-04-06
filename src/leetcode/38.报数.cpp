/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (48.79%)
 * Total Accepted:    26K
 * Total Submissions: 53.2K
 * Testcase Example:  '1'
 *
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
 * 
 * 注意：整数顺序将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 
 * 
 */
class Solution {
public:
    string countAndSay(int n) {
        string s, tmp;
        int i, j, count;
        if(n==1) s = "1";
        if(n==2) s = "11";
        if(n==3) s = "21";
        if(n==4) s = "1211";
        if(n==5) s = "111221";
        else if(n>=6){
            count = 1;
            s = countAndSay(n-1);
            for(i=0; i<s.size()-1; i++) {
                if(s[i] == s[i+1]) count++;
                else {
                    tmp.push_back(char(count+48));
                    tmp.push_back(s[i]);
                    count = 1;
                }
            }

            tmp.push_back(char(count+48));
            tmp.push_back(s[s.size()-1]);

            s = tmp;
        }

        return s;
    }
};

