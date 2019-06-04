/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i, sum = 0;
        for(i=0; i<nums.size(); i++) 
            sum = sum-nums[i]+i;

        return sum+nums.size();
    }
};


class SolutionV4 {
public:
    int missingNumber(vector<int>& nums) {
        int i, sum = (nums.size()*(1+nums.size()))/2;
        for(i=0; i<nums.size(); i++) 
            sum -= nums[i];

        return sum;
    }
};

/*
法三：参考解析
*/
class SolutionV3 {
public:
    int missingNumber(vector<int>& nums) {
        int i, res = nums.size();
        for(i=0; i<nums.size(); i++) {
            res ^= nums[i];
            res ^= i;
        }

        return res;
    }
};


/*
法二：法一的代码优化
*/
class SolutionV2 {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i;
        for(i=0; i<nums.size(); i++)
            if(i != nums[i]) return i;
        
        return nums.size();
    }
};

/*
法一：暴力
*/
class SolutionV1 {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[nums.size()-1] != nums.size()) return nums.size();
        
        int i, res=0;
        for(int i=0; i<nums.size(); i++)
            if(i != nums[i]) {
                res = i;
                break;
            }

        return res;
    }
};

