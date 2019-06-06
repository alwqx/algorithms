/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i, len = nums.size();
        vector<int> tn(len);
        for(i=0; i<len; i++) tn[i] = nums[i];

        sort(tn.begin(), tn.end());
        int left=0, right=0;
        for(i=0; i<len; i++) if(nums[i]!=tn[i]) {left = i; break;}
        for(i=len-1; i>=0; i--) if(nums[i]!=tn[i]) {right = i; break;}
        if(left == right) return 0;

        return right-left+1;
    }
};

