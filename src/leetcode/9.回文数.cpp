/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (56.03%)
 * Total Accepted:    91.5K
 * Total Submissions: 163.3K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 * 
 * 输入: 121
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3:
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 进阶:
 * 
 * 你能不将整数转为字符串来解决这个问题吗？
 * 
 */
class SolutionV1 {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int i, j, a[32];
        i = 0;
        while(x) {
            a[i++] = x%10;
            x /= 10;
        }

        for(j=0; j<i/2; j++)
            if(a[j] != a[i-1-j]) return false;
        
        return true;
    }
};

// 参考题解
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0 && x!=0)) return false;

        int ret = 0;
        while(x>ret) {
            ret = ret*10 + x%10;
            x /= 10;
        }

        return x==ret || x==ret/10;
    }
};
/*
0 1 2 i=3
0   2

0 1 2 3 4 i=5

*/
