/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        
        string s1;
        for(int i=0; i<s.size(); i++) {
            s[i] = tolower(s[i]);
            if(isalnum(s[i])) s1 += s[i];
        }

        int left=0, right=s1.size()-1;
        while(left<=right)
            if(s1[left] == s1[right]) {left++; right--;}
            else return false;
        
        return true;
    }
};

class SolutionV1 {
public:
    bool isPalindrome(string s) {
        int left=0, right=s.size()-1;
        bool res = true;
        if(s.size() <= 1) return res;

        while(left<=right) {
            while(left<s.size() && !valids(s[left])) left++;
            while(right>=0 && !valids(s[right])) right--;
            if(left<=right && tolower(s[left])!=tolower(s[right])) {
                res = false;
                break;
            }

            left++;right--;
        }

        return res;
    }

    bool valids(char c) {
        return c>='a'&&c<='z' ||
                c>='A'&&c<='Z' ||
                c>='0'&&c<='9';
    }
};

