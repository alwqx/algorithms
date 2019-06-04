/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */
class Solution {
public:
    static bool cmp(int a, int b) {
        return a>b;
    }

    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if(nums.size()<3) return nums[0];

        int res = nums[0], c = 0;
        for(int i=0; i<nums.size() && c<2; i++)
            if(res>nums[i]) {
                res = nums[i];
                c++;
            }
        if(c == 2) return res;
        return nums[0];
    }
};

