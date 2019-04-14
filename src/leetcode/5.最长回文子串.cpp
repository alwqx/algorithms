/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (24.82%)
 * Total Accepted:    49.9K
 * Total Submissions: 200.8K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


// abbd abc aabbdd
bool isHuiwen(string s, int low, int high) {
    int i=low, j=high;
    while(i <= j) {
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }

    return true;
}

// time limit exceeded
class SolutionV1 {
public:
    string longestPalindrome(string s) {
        int i, j, ret = 0;
        int ri = 0;
        for(i=0; i<s.size(); i++) {
            for(j=i; j<s.size(); j++) {
                if(isHuiwen(s, i, j)) {
                    if(ret < j-i+1) {
                        ret = j-i+1;
                        ri = i;
                    }
                }
            }
        }

        return s.substr(ri, ret);
    }
};


int expandAroundCenter(string s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.size() && s[L] == s[R]) {
        L--;
        R++;
    }
    return R - L - 1;
}

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        
        int i, len, len1, len2, start=0, end=0;
        for(i=0; i<s.size(); i++) {
            len1 = expandAroundCenter(s, i, i);
            len2 = expandAroundCenter(s, i, i+1);
            len = max(len1, len2);

            if(len > end-start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end-start+1);
    }
};

/*
int main() {
    Solution sou = Solution();
    cout<<sou.longestPalindrome("cbbd")<<endl;
    // cout<<sou.longestPalindrome("c")<<endl;
    // cout<<sou.longestPalindrome("ac")<<endl;
    // cout<<sou.longestPalindrome("babad")<<endl;

    return 0;
}


/*
# 思维过程
## 法一
暴力法，时间复杂度O(n*n*n)

## 法二
s反转得到一个新字符串，求两者的公共子串
*/

