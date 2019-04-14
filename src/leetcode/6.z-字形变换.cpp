/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (41.55%)
 * Total Accepted:    28.1K
 * Total Submissions: 67.3K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 */
#include <ctype.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void pp(char **m, int numRows, int len) {
    int i, j;
    for(i=0; i<numRows; i++) {
        for(j=0; j<len; j++)
            cout<<m[i][j];
        cout<<endl;
    }
}

class SolutionV1 {
public:
    string convert(string s, int numRows) {
        string ret;
        int i, j, k, flag, len=s.size();
        if(numRows<=1 || numRows>=len) return s;

        char **m;
        m = new char *[numRows];
        for(i=0; i<numRows; i++) m[i] = new char [len];
        for(i=0; i<numRows; i++)
            for(j=0; j<len; j++)
                m[i][j] = '*';

        flag = i = j = k = 0;
        while(k<len) {
            if(flag == 0) {
                while(i<numRows) m[i++][j] = s[k++];
                i--;k--;
                flag = 1;
            }
            if(flag == 1) {
                while(i>=0) m[i--][j++] = s[k++];
                i++;j--;k--;
                flag = 0;
            }
            // pp(m, numRows, len);
            // cout<<endl;
        }

        for(i=0; i<numRows; i++)
            for(j=0; j<len; j++)
                if(isalpha(m[i][j])) ret.push_back(m[i][j]);
        
        return ret;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || s.size()<=numRows) return s;

        int curRow = 0;
        bool isGoDown = false;
        vector<string> rows(min(numRows, int(s.size())));
        for(char c : s) {
            rows[curRow] += c;
            if(curRow==0 || curRow==numRows-1)
                isGoDown = !isGoDown;
            curRow += isGoDown?1:-1;
        }

        string ret;
        for(string row:rows) ret += row;

        return ret;
    }
};

/*
int main() {
    Solution s = Solution();
    cout<<s.convert("PAYPALISHIRING", 3)<<endl;
    cout<<s.convert("LEETCODEISHIRING", 4)<<endl;
    return 0;
}*/

/*
# 思维过程
## 法一
通过模拟，利用二位数组模拟字母的排列过程，然后拼接结果。

这个方法比较直接，考研的是基础编程能力
*/