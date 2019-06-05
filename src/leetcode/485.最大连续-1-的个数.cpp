/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i, len=nums.size(), sum=0, maxn=0;
        for(i=0; i<len; i++) {
            if(nums[i] != 0) {
                sum++;
                maxn = max(maxn, sum);
            } else sum = 0;
        }

        return maxn;
    }
};

class SolutionV1 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        nums.push_back(0);
        int i, tm=0, maxn=INT_MIN;
        for(i=0; i<nums.size(); i++) {
            if(nums[i] == 1) tm++;
            else {
                maxn = max(maxn, tm);
                tm = 0;
            }
        }

        return maxn;
    }
};

