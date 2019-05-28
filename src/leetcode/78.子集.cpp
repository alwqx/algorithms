/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (72.29%)
 * Total Accepted:    17.2K
 * Total Submissions: 23.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

/*
Your runtime beats 95.56 % of cpp submissions
Your memory usage beats 53.81 % of cpp submissions (9.1 MB)
*/
class SolutionV1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.push_back({});

        int size = nums.size();
        int subsize = pow(2, size);
        int k, a, hash = 1;

        while(hash<subsize) {
            vector<int> tmp;
            for(k=0; k<size; k++) {
                a = 1<<k;
                if(a&hash) tmp.push_back(nums[k]);
            }

            ret.push_back(tmp);
            hash++;
        }

        return ret;
    }
};

/*
Your runtime beats 48.24 % of cpp submissions
Your memory usage beats 78.61 % of cpp submissions (9 MB)
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result(1);//这是个小技巧
        for(int i=0;i<nums.size();i++)
        {
            int ret_size=result.size();
            for(int j=0;j<ret_size;j++)
            {
                vector<int> temp=result[j];
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }
        return result;
    }
};

/*
# 思路分析
## 法一 参考题解


*/
