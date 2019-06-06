/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int i, j, r=M.size(), c=M[0].size();
        vector<vector<int>> res(M);

        int tmp, count;
        for(i=0; i<r; i++) {
            for(j=0; j<c; j++) {
                tmp = 0;
                count = 1;
                tmp += M[i][j];

                if(i-1>=0) {
                    tmp += M[i-1][j];
                    count++;
                }
                if(i+1<r) {
                    tmp += M[i+1][j];
                    count++;
                }
                if(j-1>=0) {
                    tmp += M[i][j-1];
                    count++;
                }
                if(j+1<c) {
                    tmp += M[i][j+1];
                    count++;
                }
                if(i-1>=0 && j-1>=0) {
                    tmp += M[i-1][j-1];
                    count++;
                }
                if(i-1>=0 && j+1<c) {
                    tmp += M[i-1][j+1];
                    count++;
                }
                if(i+1<r && j-1>=0) {
                    tmp += M[i+1][j-1];
                    count++;
                }
                if(i+1<r && j+1<c) {
                    tmp += M[i+1][j+1];
                    count++;
                }

                res[i][j] = tmp/count;
            }
        }

        return res;
    }
};

