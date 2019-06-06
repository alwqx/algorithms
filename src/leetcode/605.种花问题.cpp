/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i;
        for(i=0; n && i<flowerbed.size(); i++) {
            if((i==0 || flowerbed[i-1]==0) && flowerbed[i]==0 &&
                (i==flowerbed.size()-1 || flowerbed[i+1]==0)) {
                    n--;
                    flowerbed[i] = 1;
                }
        }

        return !n;
    }
};

