/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len=nums.size();
        if(len<3) return -1;

        int i, suml=0, sumr=0;
        for(i=1; i<len; i++) sumr += nums[i];

        for(i=0; i<len; i++) {
            if(suml == sumr) return i;
            suml += nums[i];
            if(i<len-1) sumr -= nums[i+1];
        }

        return -1;
    }
};

