/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
class SolutionV2 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int i, j;
        
        i=0; j=numbers.size()-1;
        while(numbers[i]+numbers[j] != target) {
            while(numbers[i]+numbers[j] < target) i++;
            while(numbers[i]+numbers[j] > target) j--;
        }
        res.push_back(i+1);
        res.push_back(j+1);
        
        return res;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int i, j;
        
        i=0; j=numbers.size()-1;
        while(i<j) {
            // tmp = numbers[i] + numbers[j];
            if(numbers[i]+numbers[j] > target) j--;
            else if(numbers[i]+numbers[j] < target) i++;
            else {
                res.push_back(i+1);
                res.push_back(j+1);
                break;
            }
        }
        
        return res;
    }
};

class SolutionV1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int i, j;
        for(i=0; i<numbers.size(); i++)
            for(j=i+1; j<numbers.size(); j++)
                if(numbers[i]+numbers[j] == target) {
                    res.push_back(i+1);
                    res.push_back(j+1);
                }
        
        return res;
    }
};

 