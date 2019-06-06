/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int i, count=1, res=1;
        if(nums.size()<2) return nums.size();

        for(i=0; i<nums.size()-1; i++) {
            if(nums[i+1]>nums[i]) count++;
            else count=1;

            res = res>count?res:count;
        }

        return res;
    }
};

