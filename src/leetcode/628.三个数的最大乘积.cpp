/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int a = nums[0]*nums[1]*nums[len-1];
        int b = nums[len-1]*nums[len-2]*nums[len-3];

        return a>b?a:b;
    }
};

