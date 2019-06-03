/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n>=5) {
            res += n/5;
            n /= 5;
        }

        return res;
    }
};

