/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};

/*
法二：参考解析
*/
class SolutionV2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return false;

        sort(nums.begin(), nums.end());
        int i;
        for(i=0; i<nums.size()-1; i++)
            if(nums[i] == nums[i+1]) return true;
        
        return false;
    }
};

/*
法一：使用map，速度不是很快
*/
class SolutionV1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        int i;

        for(i=0; i<nums.size(); i++) {
            if(m.find(nums[i]) == m.end()) m[nums[i]] = 1;
            else {
                m[nums[i]] += 1;
                if(m[nums[i]] >= 2) return true;
            }
        }

        return false;
    }
};

