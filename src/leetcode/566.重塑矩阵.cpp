/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int i, orr=nums.size(), oc=nums[0].size();
        if(c*r != orr*oc) return nums;

        vector<vector<int>> res(r, vector<int>(c));
        for(i=0; i<r*c; i++)
            res[i/c][i%c] = nums[i/oc][i%oc];

        return res;
    }
};

