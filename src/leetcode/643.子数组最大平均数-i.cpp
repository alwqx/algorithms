/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i, maxn=INT_MIN, sum=0, len=nums.size();
        for(i=0; i<k; i++) sum += nums[i];
        maxn = sum;
        
        for(i=k; i<len; i++) {
            sum += nums[i] - nums[i-k];
            if(sum >= maxn) maxn = sum;
        }

        return double(maxn)/k;
    }
};

