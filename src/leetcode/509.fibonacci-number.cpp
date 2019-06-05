/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */
class Solution {
public:
    int fib(int N) {
        int cur=0, next=1;
        while(N-- > 0) {
            next = next + cur;
            cur = next - cur;
        }

        return cur;
    }
};

class SolutionV2 {
public:
    int fib(int N) {
        if(N < 2) return N;

        return fib(N-1) + fib(N-2);
    }
};

class SolutionV1 {
public:
    int fib(int N) {
        if(N < 2) return N;

        int i, m=0, n=1, res=0;
        for(i=2; i<=N; i++) {
            res = m + n;
            m = n;
            n = res;
        }

        return res;
    }
};

