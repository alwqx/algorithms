/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        if(nums.size()>1) {
            for(int i=1; i<nums.size(); i++)
                res = res^nums[i];
        }

        return res;
    }
};

class SolutionV1 {
public:
    int singleNumber(vector<int>& nums) {
        int res;
        map<int, int> m;

        for(int i=0; i<nums.size(); i++) {
            if(m.find(nums[i]) == m.end()) m[nums[i]] = 1;
            else m[nums[i]]++;
        }
        for(int i=0; i<nums.size(); i++)
            if(m[nums[i]] == 1) {
                res = nums[i];
                break;
            }

        return res;
    }
};

