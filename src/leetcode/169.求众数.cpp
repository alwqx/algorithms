/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int res;

        for(int i=0; i<nums.size(); i++) {
            if(m.find(nums[i]) == m.end()) m[nums[i]] = 1;
            else m[nums[i]] += 1;

            if(m[nums[i]] > nums.size()/2) {
                res = nums[i];
                break;
            }
        }

        return res;
    }
};

class SolutionV1 {
public:
    static bool cmp(const int &a, const int &b) {
        return a<b;
    }

    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        return nums[nums.size()/2];
    }
};
