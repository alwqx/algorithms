/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (64.72%)
 * Total Accepted:    28.1K
 * Total Submissions: 43.2K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
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
Your runtime beats 97.01 % of cpp submissions
Your memory usage beats 20.24 % of cpp submissions (9.4 MB)
*/
class SolutionV1 {
public:
    void traverse(TreeNode* root, vector<int>& v) {
        if(root == NULL) return;

        traverse(root->left, v);
        v.push_back(root->val);
        traverse(root->right, v);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        traverse(root, ret);

        return ret;
    }
};

/*
Your runtime beats 97.01 % of cpp submissions
Your memory usage beats 59.72 % of cpp submissions (9.1 MB)
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode *cur = root;
        stack<TreeNode*> s;

        while(cur!=NULL || !s.empty()) {
            if(cur != NULL) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                ret.push_back(cur->val);
                cur = cur->right;
            }
        }

        return ret;
    }
};

