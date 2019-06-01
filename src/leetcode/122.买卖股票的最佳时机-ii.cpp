/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int i, maxProfit=0;

        for(i=1; i<prices.size(); i++) {
            if(prices[i]>prices[i-1])
                maxProfit += prices[i]-prices[i-1];
        }

        return maxProfit;
    }
};

class SolutionV1 {
public:
    int maxProfit(vector<int>& prices) {
        int ps = prices.size(), maxProfit=0;
        if(ps <= 1) return maxProfit;
        int i=0, valley=prices[0], peak=prices[0];
        

        while(i<ps-1) {
            while(i<ps-1 && prices[i]>=prices[i+1]) i++;
            valley = prices[i];
            while(i<ps-1 && prices[i]<=prices[i+1]) i++;
            peak = prices[i];

            maxProfit += peak-valley;
        }
        
        return maxProfit;
    }
};

