/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0, minPrice=INT_MAX;
        for(int i=0; i<prices.size(); i++)
            if(prices[i]<minPrice) minPrice=prices[i];
            else if(maxProfit<(prices[i]-minPrice))
                maxProfit = prices[i]-minPrice;

        return maxProfit;
    }
};

class SolutionV1 {
public:
    int maxProfit(vector<int>& prices) {
        int i, j, res = 0;
        if(prices.size() <= 1) return res;
        
        for(i=0; i<prices.size()-1; i++) {
            for(j=i+1; j<prices.size(); j++)
                if(res<=prices[j]-prices[i])
                    res = prices[j]-prices[i];
        }

        return res;
    }
};

