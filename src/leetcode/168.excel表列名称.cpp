/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */
class Solution {
public:
    string convertToTitle(int n) {
        char a[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        string res;

        while(n) {
            n--;
            res = a[n%26] + res;
            n /= 26;
        }

        return res;
    }
};

