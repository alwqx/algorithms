# DFS

# [131. 分割回文串](https://leetcode-cn.com/problems/palindrome-partitioning/)
这是一道综合题目，结合了dfs和dp，dp主要是用来加速判断一个字符串任意s[i...j]是否是回文串。在O(n^2)时间和空间复杂度内，得到任意s[i...j]是否是回文串的结果:
```cpp
class Solution {
private:
    vector<vector<bool>> dp;
    vector<vector<string>> ans;
    vector<string> res;
    int n;
public:
    void dfs(const string& s, int i) {
        if(i == n) {
            ans.push_back(res);
            return;
        }

        for(int j=i; j<n; j++) {
            if(dp[i][j]) {
                res.push_back(s.substr(i, j-i+1));
                dfs(s, j+1);
                res.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        dp.assign(n, vector<bool>(n, true));

        int i, j;
        for(i=n-1; i>=0; i--) {
            for(j=i+1; j<n; j++) {
                dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1];
            }
        }
        dfs(s, 0);

        return ans;
    }
};
```

另外就是如何做深搜了，自己开始么有理解清楚，不知道如何设置中间容器并在dfs过程中更新。