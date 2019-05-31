/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        bool stop = false;
        int i, qLen, minLen = 0;
        queue<TreeNode*> qt;
        qt.push(root);
        TreeNode *tmp;

        while(!qt.empty() && !stop) {
            minLen++;
            qLen = qt.size();
            for(i=0; i<qLen; i++) {
                tmp = qt.front();
                qt.pop();

                if(tmp->left==NULL && tmp->right==NULL) {stop=true; break;}
                if(tmp->left) qt.push(tmp->left);
                if(tmp->right) qt.push(tmp->right);
            }
        }

        return minLen;
    }
};

