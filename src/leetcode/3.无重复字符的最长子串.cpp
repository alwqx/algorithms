/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.91%)
 * Total Accepted:    103.9K
 * Total Submissions: 358.5K
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */
#include <vector>
#include <map>
#include <stdio.h>
#include <set>

using namespace std;

class SolutionV1 {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1) return s.size();
        vector<char> v;

        int i, j, ret=0;
        bool flag;

        for(i=0; i<s.size(); i++) {
            if(!v.empty()) v.clear();
            flag = false;
            for(j=i; j<s.size(); j++) {
                if(v.empty()) {
                    v.push_back(s[j]);
                    continue;
                }

                int k;
                for(k=0; k<v.size(); k++)
                    if(v[k]==s[j]) {
                        flag = true;
                        break;
                    }
                if(flag) break;
                v.push_back(s[j]);
            }

            if(ret<v.size()) ret = v.size();
        }

        return ret;
    }
};

class SolutionV2 {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> ss;
        int i=0, j=0, ret=0;

        while(i<s.size() && j<s.size()) {
            auto it = ss.find(s[j]);
            if(it == ss.end()) {
                ss.insert(s[j]);
                j++;
            } else {
                ss.erase(s[i]);
                i++;
            }

            ret=ret<ss.size()?ss.size():ret;
        }

        return ret;
    }
};

// V2
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j, ret=0;
        map<char, int> m;
        
        for(i=0,j=0; j<s.size(); j++) {
            auto it = m.find(s[j]);
            if(it != m.end()) {
                i = max(i, m[s[j]]);
            }

            ret = max(ret, j-i+1);
            m[s[j]] = j+1;
        }

        return ret;
    }
};

/*
# 思维过程：
## 法一（暴力解法）
1. 临界情况，当长度为0或1时，返回长度
2. 辅助函数：返回从当前位置开始，不重复的最大长度
3. 遍历字符串，返回从当前位置的字串的最大长度，得到最大值

坑：int ret=-1, ret<v.size()一直是false

## 法二（滑动窗口）
参考 https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/
*/

