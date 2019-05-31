/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
#include <map>

using namespace std;

class Solution {
public:
    bool isBalancedTree = true;
    bool isBalanced(TreeNode* root) {
        height(root);
        return isBalancedTree;
    }

    int height(TreeNode* root) {
        if(!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        if(l-r>1 || r-l>1) isBalancedTree = false;

        return l>r?l+1:r+1;
    }
};

class SolutionV1 {
public:
    map<TreeNode*, int> m;
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int subb = height(root->left)-height(root->right);
        return (subb>=-1) && (subb<=1) && isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode* root) {
        if(root == NULL) return 0;

        if(root->left==NULL && root->right==NULL) return 1;
        if(root->left!=NULL && root->right!=NULL) {
            if(m.find(root) == m.end()) {
                int hLeft = height(root->left);
                int hRight = height(root->right);
                int maxH = hLeft>=hRight?hLeft:hRight;
                m[root] = maxH + 1;
            }
            
            return m[root];
        }

        m[root] = 1+height(root->left)+height(root->right);
        return m[root];
    }
};

