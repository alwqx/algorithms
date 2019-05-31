/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0) return res;

        vector<int> tmp;
        tmp.push_back(1);
        res.push_back(tmp);

        int i, j;
        for(i=1; i<numRows; i++) {
            vector<int> tmp2;
            for(j=0; j<=i; j++) {
                int x = 0;
                if(j-1>=0) x += res[i-1][j-1];
                if(j<i) x += res[i-1][j];
                tmp2.push_back(x);
            }

            res.push_back(tmp2);
        }

        return res;
    }

};

/*
class SolutionV1 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0) return res;

        int i, j;
        for(i=0; i<numRows; i++) {
            vector<int> tmp;
            for(j=0; j<=i; j++) {
                tmp.push_back(ccc(i, j));
            }

            res.push_back(tmp);
        }

        return res;
    }

    int ccc(int base, int n) {
        if(n==0) return 1;
        if(n>base/2) return ccc(base, base-n);

        long long int i, up=1, down=1;
        for(i=1; i<=n; i++) down *= i;
        for(i=0; i<n; i++) up *= (base-i);

        return up/down;
    }
};
*/
