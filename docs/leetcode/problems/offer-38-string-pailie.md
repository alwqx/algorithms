# 剑指Offer-面试题38. 字符串的排列
感觉对这种提醒还不是很熟练，按照ACM学弟的建议，要多写几遍，在理解的基础上，把思路固化成记录。

题目主要有两种思路，一种是交换、dfs的思路，一种是决策树回溯的思路。

交换+dfs是参考[Krahets](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/mian-shi-ti-38-zi-fu-chuan-de-pai-lie-hui-su-fa-by/)的思路和代码，使用set来去重。

```cpp
class Solution {
public:
    vector<string> permutation(string s) {
        if(s.size() == 0) return {};

        set<string> res;
        dfs(s, res, 0);
        return vector<string>(res.begin(), res.end());
    }

    void dfs(string s, set<string>& res, int pos) {
        if(pos == s.size()) {
            res.insert(s);
            return;
        }

        for(int i=pos; i<s.size(); i++) {
            swap(s[i], s[pos]);
            dfs(s, res, pos+1);
            swap(s[i], s[pos]);
        }
    }
}
```

基于决策树的思路，参考[落鲸与鱼](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/hui-su-fa-by-luo-jing-yu-yu/)的思路。通过排序和判断来避免重复(剪枝)。

```cpp
class Solution {
public:
    vector<string> permutation(string s) {
        int len = s.size();
        if(len == 0) return {};

        vector<bool> vis(len, false);
        vector<string> res;
        string track;
        sort(s.begin(), s.end());

        dfs(s, res, vis, track);
        return res;
    }

    void dfs(string s, vector<string>& res, vector<bool>& vis, string track) {
        if(track.size() == s.size()) {
            res.push_back(track);
            return;
        }

        for(int i=0; i<s.size(); i++) {
            if(vis[i]) continue;
            // 下面这行代码至关重要！要好好理解
            if(i>0 && !vis[i-1] && s[i-1]==s[i]) continue;

            vis[i] = true;
            track.push_back(s[i]);
            dfs(s, res, vis, track);
            track.pop_back();
            vis[i] = false;
        }
    }
}
```