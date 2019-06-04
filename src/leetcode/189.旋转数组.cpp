/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>=nums.size()) k %= nums.size();
        if(k != 0) {
            rrs(nums, 0, nums.size()-k-1);
            rrs(nums, nums.size()-k, nums.size()-1);
            rrs(nums, 0, nums.size()-1);
        }
    }

    void rrs(vector<int> &nums, int left, int right) {
        int tmp;
        while(left <= right) {
            tmp = nums[right];
            nums[right] = nums[left];
            nums[left] = tmp;
            left++;
            right--;
        }
    }
};

/*
法三：参考解析
*/
class SolutionV3 {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>=nums.size()) k %= nums.size();
        if(k != 0) {
            vector<int> cache(nums.size());
            int i;
            for(i=0; i<nums.size(); i++)
                cache[(i+k)%nums.size()] = nums[i];
            for(i=0; i<nums.size(); i++)
                nums[i] = cache[i];
        }
    }
};

/*
法二：参考解析，没有达到原地存储的要求。
*/
class SolutionV2 {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>=nums.size()) k %= nums.size();
        if(k != 0) {
            vector<int> cache(k);
            int i, ic = 0;
            for(i=nums.size()-k; i<nums.size(); i++) {
                cache[ic] = nums[i];
                ic++;
            }

            for(i=nums.size()-1; i>=k; i--) nums[i] = nums[i-k];
            for(i=0; i<k; i++) nums[i] = cache[i];
        }
    }
};

/*
法一：暴力解法，超时
*/
class SolutionV1 {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        if(!k) return;

        int i, j, tmp;
        for(i=0; i<k; i++) {
            tmp = nums[nums.size()-1];
            for(j=nums.size()-1; j>=1; j--)
                nums[j] = nums[j-1];
            nums[0] = tmp;
        }
    }
};

