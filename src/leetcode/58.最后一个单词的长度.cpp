/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (29.22%)
 * Total Accepted:    23.4K
 * Total Submissions: 79.7K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i;
        // check empty char
        for(i=0; i<s.size(); i++) if(s[i]!=' ') break;
        if(i == s.size()) return 0;

        i = s.size()-1;
        int cnt = 0;
        while(s[i]==' ') {
            i--;
            cnt++;
        }
        for(; i>=0; i--) {
            if(i==s.size()-1 && s[i]==' ') return 0;
            if(s[i] == ' ') break;
        }

        return s.size()-i-1-cnt;
    }
};

