/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int minLen = a.size()<=b.size()?a.size():b.size();
        string ret = "";
        int i, carry=0, tmp=0;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(i=0; i<minLen; i++) {
            tmp = a[i]-'0'+b[i]-'0'+carry;
            carry = tmp/2;
            ret.push_back(tmp%2+'0');
        }

        for(; i<a.size(); i++) {
            tmp = a[i]-'0'+carry;
            carry = tmp/2;
            ret.push_back(tmp%2+'0');
        }
        for(; i<b.size(); i++) {
            tmp = b[i]-'0'+carry;
            carry = tmp/2;
            ret.push_back(tmp%2+'0');
        }
        if(carry) ret.push_back(carry+'0');
        reverse(ret.begin(), ret.end());

        return ret;
    }
};

