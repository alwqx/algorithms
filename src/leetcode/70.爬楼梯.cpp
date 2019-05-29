/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include <map>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;

        int i, tmp, first = 1, second = 2;
        for(i=2; i<n; i++) {
            tmp = first+second;
            first = second;
            second = tmp;
        }

        return second;
    }
};

class SolutionV1 {
public:
    map<int, int> m;
    int climbStairs(int n) {
        if(n<=2) {
            m[n] = n;
            return n;
        }
        
        auto search = m.find(n);
        if(search != m.end()) return m[n];
        
        m[n] = climbStairs(n-1)+climbStairs(n-2);
        return m[n];
    }
};

