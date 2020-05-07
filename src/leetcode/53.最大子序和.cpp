/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (43.81%)
 * Total Accepted:    47.2K
 * Total Submissions: 107.5K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */
class Solution {
public:
    int maxSubArray(vector<int>& v) {
        if(v.size() == 0) return 0;

        int i, ret, n, sum=0;
        ret = v[0];

        for(i=0; i<v.size(); i++) {
            if(sum>0) sum+=v[i];
            else sum = v[i];

            ret = ret>sum?ret:sum;
        }

        return ret;
    }
};

/*
思维方式有点绕，自己要弄清楚
*/
class SolutionV1 {
public:
    int maxSubArray(vector<int>& nums) {
        int i, sum, res, len=nums.size();
        if(len == 0) return 0;
        res = sum = nums[0];

        for(i=1; i<len; i++) {
            sum = max(nums[i], sum+nums[i]);
            res = max(res, sum);
        }

        return res;
    }
};
 