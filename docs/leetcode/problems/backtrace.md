# 回溯

# [93. 复原IP问题](https://leetcode-cn.com/problems/restore-ip-addresses/)
# 93. 复原IP问题
自己没有想到方法，参考题解。

这个方法简洁、优雅，好理解。
```cpp
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		string ip;
		helper(s, 0, ip);
		return res;
	}
	void helper(string s, int n, string ip) {
		if (n == 4) {
			if (s.empty()) res.push_back(ip);
		}
		else {
			for (int k = 1; k < 4; ++k) {
				if (s.size() < k) break;
				int val = stoi(s.substr(0, k));
				//值大于255或者以0开头不符合IP规定,可以剪枝
				if (val > 255 || k != std::to_string(val).size()) continue;
				helper(s.substr(k), n + 1, ip + s.substr(0, k) + (n == 3 ? "" : "."));
			}
		}
		return;
	}
private:
	vector<string> res;
};
```

```cpp
class Solution {
public:
    bool isValid(string ip)
{
    int val = stoi(ip);
    if (val > 255)    return false;
    if (ip.size() >= 2 && ip[0] == '0')    return false;
    return true;
}
void dfs(string& s, int pos, vector<string> &path, vector<string>& res)
{
    //首先判断剩余的位数，是不是还能满足要求，比如25525511135，若2.5.5.25511135显然不满足，这可以预判
    //4组，每组最多3位数字
    int maxLen = (4 - path.size()) * 3;
    if (s.size() - pos > maxLen)    return;
    if (path.size() == 4 && pos == s.size()) {
        string ans = "";
        for (int i = 0; i < 4; ++i) {
            ans += path[i];
            if (i != 3)    ans += ".";
        }
        res.push_back(ans);
        return;
    }
    //回溯算法的典型模式，循环递归
    for (int i = pos; i < s.size() && i <= pos + 2; ++i) {
        string ip = s.substr(pos, i - pos+1);
        if (!isValid(ip))    continue;
        path.push_back(ip);
        dfs(s, i + 1, path, res);
        path.pop_back();
    }
}
vector<string> restoreIpAddresses(string s)
{
    //找3个.的位置,每个.之前组成的的数值必须要小于255，且以0开头的除非数字是0本身，否则也是非法
    vector<string> res;
    if (s.size() == 0 || s.size() < 4)    return res;
    vector<string> path;//存储从根开始的到叶子节点的满足条件的路径,因为最多3位数字一组，所以同一层横向循环时尝试最多3个位的长度
    dfs(s, 0, path, res);
    return res;
}
};

/*
作者：ali40
链接：https://leetcode-cn.com/problems/restore-ip-addresses/solution/cqing-xi-yi-dong-jie-fa-by-ali40/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
```

# [60. 排列序列](https://leetcode-cn.com/problems/permutation-sequence/)

# [39. 组合总和](https://leetcode-cn.com/problems/combination-sum/)
注意可以选择跳过当前数或者不跳过。
```cpp
class Solution {
private:
    void dfs(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& cand, int target, int pos) {
        int size = cand.size();
        if(pos>=size || cand[pos]>target) return;
        int v = cand[pos];
        if(target == v) {
            tmp.push_back(v);
            ans.push_back(tmp);
            tmp.pop_back();
            return;
        }

        // 跳过当前数
        dfs(ans, tmp, cand, target, pos+1);

        // for(int i=pos; i<size; i++) {
            tmp.push_back(v);
            dfs(ans, tmp, cand, target-v, pos);
            tmp.pop_back();
        // }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        vector<vector<int>> ans;
        // for(int i=0; i<candidates.size(); i++)
        dfs(ans, tmp, candidates, target, 0);
        return ans;
    }
};
```

# [95. 不同的二叉搜索树 II](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)

题解还会太抽象了，自己看不懂，多看看熟悉下。

# [78. 子集](https://leetcode-cn.com/problems/subsets/)
自己将问题分割，分别求0-n个数的子集，然后push到最终结果中，做出来了，就是代码相对多些，没有官方题解中的简洁。

代码越简洁，思维过程越复杂。

通过位运算和二进制的思路来做简直牛逼：
```cpp
class Solution {
private:
    vector<int> t;
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // ans.push_back({});
        int i, mask, size=nums.size();
        for(mask=0; mask<(1<<size); mask++) {
            t.clear();
            for(i=0; i<size; i++) {
                if(mask & (1<<i)) {
                    t.push_back(nums[i]);
                }
            }
            ans.push_back(t);
        }

        return ans;
    }
};
```

下面的思路也很简单啊，都比我的算法简洁：
```cpp
class Solution {
private:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(int cur, vector<int>& nums) {
        int size = nums.size();
        if(cur == size) {
            ans.push_back(t);
            return;
        }

        t.push_back(nums[cur]);
        dfs(cur+1, nums);
        t.pop_back();

        dfs(cur+1, nums);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};
```

# [77. 组合](https://leetcode-cn.com/problems/combinations/)
自己试着用回溯的框架去做，但是提示一直不对，想了1个多小时没想出来，主要是在图书馆没预约到座位，换了几次，**做不到不受环境影响沉浸式思考**。

感觉自己没有想清楚本问题的本质，dfs过程中各个参数的含义也不明确，这就导致dfs框架结构不明晰。**在dfs框架不明晰的情况下，怎么修改都是徒劳的，应该先想清楚框架和流程，再去做**。


# [22. 括号生成](https://leetcode-cn.com/problems/generate-parentheses/)
这个题目我想复杂了，题目的意思是计算出**有效括号对**的数量，我的回溯中加入了判断括号是否有效的逻辑，增加了程序的复杂性。

通过查看[官方题解](https://leetcode-cn.com/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode-solution/)了解到，可以利用题目的隐含信息，认为调整逻辑跳过非法的括号对，简化程序。**通过跟踪左括号、右括号的数量关系来做到这点**。

**如果左括号数量不大于n，我们可以放一个左括号。如果右括号数量小于左括号的数量，我们可以放一个右括号**。

```cpp
class Solution {
private:
    void dfs(vector<string>& res, string str, int li, int ri, int n) {
        if(str.size() == n*2) {
            res.push_back(str);
            return;
        }

        if(li < n) {
            str.push_back('(');
            dfs(res, str, li+1, ri, n);
            str.pop_back();
        }
        if(ri < li) {
            str.push_back(')');
            dfs(res, str, li, ri+1, n);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        dfs(res, str, 0, 0, n);

        return res;
    }
};
```