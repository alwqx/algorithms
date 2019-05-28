/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return x;
        
        double last = 0.0;
        double res = 1.0;
        while(res!=last) {
            last = res;
            res = (res + x/res)/2;
        }

        return int(res);
    }

    int mySqrt1(int x) {
        long long int ret, mid, left=0, right=x/2+1;
        while(left<=right) {
            mid = (left+right)/2;
            ret = mid*mid;
            if(ret==x) return mid;
            else if(ret>x) right = mid-1;
            else left = mid+1;
        }

        return right;
    }
};

