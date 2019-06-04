/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;

        map<int, int> m;
        int i;
        for(i=0; i<nums.size(); i++) {
            if(m.count(nums[i]) == 0) m[nums[i]] = i;
            else if(i-m[nums[i]] <= k) return true;
            else m[nums[i]] = i;
        }

        return false;
    }
};

/*
法二：参考解析
*/
class SolutionV2 {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;

        vector<vector<int>> lis(nums.size(), vector<int>(2));
        int i;
        for(i=0; i<nums.size(); i++) {
            lis[i][0] = nums[i];
            lis[i][1] = i;
        }

        sort(lis.begin(), lis.end(), cmp);
        for(i=0; i<lis.size()-1; i++)
            if(lis[i][0] == lis[i+1][0])
                if(lis[i+1][1]-lis[i][1] <= k) return true;
        
        return false;
    }
};

/*
法一：暴力解法，超时
*/
class SolutionV1 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // k %= nums.size();
        int i, j;
        for(i=0; i<nums.size(); i++)
            for(j=i+1; j<=i+k&&j<nums.size(); j++)
                if(nums[i] == nums[j]) return true;
        
        return false;
    }
};

