/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */
class SolutionV0 {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> m;
        vector<int> n;
        int i, j;
        for(i=0; i<nums.size(); i++) m[nums[i]]++;

        int degree=0;
        for(auto it=m.begin(); it!=m.end(); it++)
            if(degree <= it->second)
                degree = it->second;
        for(auto it=m.begin(); it!=m.end(); it++)
            if(degree == it->second)
                n.push_back(it->first);

        int left, right, minLen=INT_MAX;
        for(i=0; i<n.size(); i++) {
            for(j=0; j<nums.size(); j++) if(nums[j] == n[i]) {left=j; break;}
            for(j=nums.size()-1; j>=0; j--) if(nums[j] == n[i]) {right=j; break;}
            minLen = min(minLen, right-left+1);
        }

        return minLen;
    }
};

/*
wrong answer
*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> m;
        int i;
        for(i=0; i<nums.size(); i++) m[nums[i]]++;
        
        int degree = 0;
        for(auto it=m.begin(); it!=m.end(); it++)
            if(degree < it->second)
                degree = it->second;
        
        int right, minlen=INT_MAX;
        map<int, bool> visited;
        for(i=0; i<nums.size(); i++) {
            right=nums.size()-1;
            if(m[nums[i]]==degree && !visited[nums[i]]) {
                while(nums[right] != nums[i]) right--;
                minlen = min(minlen, right-i+1);
            }
            visited[nums[i]] = true;
        }

        return minlen;
    }
};
