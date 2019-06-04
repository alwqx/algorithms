/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int i;
        for(i=0; i<nums.size(); i++) {
            if(nums[abs(nums[i])-1] < 0) continue;
            nums[abs(nums[i])-1] *= -1;
        }

        for(i=0; i<nums.size(); i++)
            if(nums[i] > 0) res.push_back(i+1);

        return res;
    }
};

class SolutionV1 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int, int> m;
        int i;
        for(i=0; i<nums.size(); i++) {
            if(m.count(nums[i] == 0)) m[nums[i]] = 1;
            else m[nums[i]] += 1;
        }

        vector<int> res;
        for(i=1; i<=nums.size(); i++)
            if(m.count(i) == 0) res.push_back(i);

        return res;
    }
};

