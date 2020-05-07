/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
这个问题自己一开始完全没有思路，是“缺少知识储备”。
一方面自己对树的认知淡忘了，
另一方面对递归执行过程的函数调用没有清楚的认识，自己把下面的代码执行过程的栈情况画出来才理解
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;
        return (left==nullptr)?right:left;
    }
};

/*
下面的代码比较好理解，参考自https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/si-chong-si-lu-liang-tiao-lu-jing-qiu-jiao-dian-di/
利用递归，递归过程中进行剪枝
*/
class SolutionV1 {
private:
    TreeNode *ans = nullptr;
public:
    int dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(root == nullptr) return 0;
        int mid = 0;
        if(root==p || root==q) mid=1;

        int left = dfs(root->left, p, q);
        if(left+mid == 2) {
            if(ans == nullptr) ans = root;
            return 2;
        }

        int right = dfs(root->right, p, q);
        if(mid+left+right == 2) if(ans == nullptr) ans = root;
        

        return left+right+mid;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};
// @lc code=end

