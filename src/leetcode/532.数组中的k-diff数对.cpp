/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的K-diff数对
 */
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int len = nums.size();
        if(len <= 1) return 0;

        sort(nums.begin(), nums.end());
        if(nums[len-1]-nums[0] < k) return 0;

        int left=0, right=1, res=0;
        while(right < len) {
            if(nums[right]-nums[left]>k) left++;
            else if(nums[right]-nums[left]<k) right++;
            else {
                left++;
                right++;
                res++;
            }

            while(left-1>=0 && left<(right-1) && nums[left-1]==nums[left]) left++;
            while(right<len && nums[right-1]==nums[right]) right++;

            if(left >= right) right++;
        }

        return res;
    }
};

