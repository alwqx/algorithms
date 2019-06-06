/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i, cnt=0;
        for(i=0; i<nums.size()-1; i++) {
            int a = nums[i];
            int b = nums[i+1];
            if(a>b) {
                cnt++;
                if(cnt>1) return false;

                if(i>0 && nums[i-1]>b && i+2<nums.size() && a>nums[i+2])
                    return false;
            }
        }
        
        return true;
    }
};

