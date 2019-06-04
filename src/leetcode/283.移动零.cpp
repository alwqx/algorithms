/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j=0;
        for(i=0; i<nums.size(); i++)
            if(nums[i] != 0) nums[j++] = nums[i];
        for(i=j; i<nums.size(); i++)
            nums[i] = 0;
    }
};

class SolutionV1 {
public:
    void moveZeroes(vector<int>& nums) {
        int i, nz=0;
        for(i=0; i<nums.size(); i++)
            if(nums[i] == 0) nz++;
        
        int iz = 0;
        for(i=0; i<nums.size(); i++)
            if(nums[i] != 0) nums[iz++] = nums[i];
        
        for(i=iz; i<nums.size(); i++) nums[i] = 0;
    }
};

