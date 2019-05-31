/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
#include <stack>
#include <map>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return helper(root, 0, sum);
    }

    bool helper(TreeNode* root, int cur, int sum) {
        if(root == NULL) return false;
        cur += root->val;
        if(root->left==NULL && root->right==NULL) return cur == sum;
        return helper(root->left, cur, sum) || helper(root->right, cur, sum);
    }
};

class SolutionV2 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        
        if(root->left==NULL && root->right==NULL) return root->val == sum;

        if(root->left == NULL) return hasPathSum(root->right, sum-root->val);
        if(root->right == NULL) return hasPathSum(root->left, sum-root->val);

        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};

/*
wrong thought
*/
class SolutionV1 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        
        // special value
        // if(root->left==NULL && root->right==NULL) return root->val == sum;

        stack<TreeNode*> st;
        map<TreeNode*, bool> visited;
        int ret = 0;

        st.push(root);
        TreeNode *tmp;

        while(!st.empty()) {
            tmp = st.top();
            st.pop();
            if(visited[tmp]) {
                ret -= tmp->val;
                continue;
            }
            visited[tmp] = true;

            ret += tmp->val;
            if(tmp->left==NULL && tmp->right==NULL) {
                if(ret == sum) return true;

                ret -= tmp->val;
            }

            if(tmp->right != NULL) st.push(tmp->right); 
            if(tmp->left != NULL) st.push(tmp->left); 
        }

        return false;
    }
};