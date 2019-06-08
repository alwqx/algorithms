/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for(auto i=0; i<bits.size(); i++)
            if(i==bits.size()-1 && bits[i]==0) return true;
            else if(bits[i] == 1) i++;
        
        return false;
    }
};

class SolutionV1 {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i, len=bits.size();
        for(i=0; i<len; i++) {
            if(i == len-1) return true;
            if(i == len-2) return bits[i] == 0;
            if(bits[i] == 1) i++;
        }

        return false;
    }
};

