/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        if(rowIndex == 0) return res;
        
        for(int i=0; i<rowIndex; i++)
            res.push_back(static_cast<int>(double(res[i])*(rowIndex-i)/(i+1)));

        return res;
    }

    int ccc(int pre, int base, int n) {
        if(n == 0) return 1;
        // if(n>base/2) return ccc(base, base-n);

        return static_cast<int>(double(pre)*(base-n)/(n+1));
    }
};

