/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (38.01%)
 * Total Accepted:    45.3K
 * Total Submissions: 119.2K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */
class SolutionV1 {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        if(haystack.size()<needle.size()) return -1;
        // if(haystack == needle) return 0;

        int i, j;
        for(i=0; i<=haystack.size()-needle.size(); i++) {
            for(j=0; j<needle.size(); j++) {
                if(haystack[i+j] != needle[j]) break;
            }
            if(j == needle.size()) return i;
        }

        if(j == needle.size()) return i;
        else return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        if(haystack.size()<needle.size()) return -1;

        int i=0, j=0;
        for(i=0; i<haystack.size(); i++) {
            if(j == needle.size()) return i-j;
            
            if(haystack[i] == needle[j]) j++;
            else {
                i -= j;
                j = 0;
            }
        }

        if(j == needle.size()) return i-j;
        return -1;
    }
};

class SolutionV3 {
public:
    int strStr(string haystack, string needle) {
        if (needle.size()==0)
            return 0;
        if (needle.size() > haystack.size())
            return -1;
        int j=0;//needle指针
        int i=0;
        for (i = 0; i < haystack.size(); ++i) {
            if (j==needle.size()){//判断完成
                return i - needle.size();
            }
            if (haystack[i] == needle[j]){
                j++;
            } else{
                i -= j;
                j=0;
            }
        }
        if (j==needle.size()){//判断完成
            return i - needle.size();
        }
        return -1;
    }
};
