/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int i, res=0;
        sort(nums.begin(), nums.end());
        for(i=0; i<nums.size(); i+=2)
            res += nums[i];

        return res;
    }
};

