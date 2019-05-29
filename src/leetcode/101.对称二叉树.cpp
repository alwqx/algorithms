/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
#include <queue>

using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> mq;
        mq.push(root);
        mq.push(root);

        TreeNode *pl, *pr;
        while(!mq.empty()) {
            pl = mq.front();
            mq.pop();
            pr = mq.front();
            mq.pop();

            if(pl==NULL && pr==NULL) continue;
            if(pl==NULL || pr==NULL) return false;
            if(pl->val != pr->val) return false;

            mq.push(pl->left);
            mq.push(pr->right);
            mq.push(pl->right);
            mq.push(pr->left);
        }

        return true;
    }
};

class SolutionV1 {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        TreeNode *pleft, *pright;
        pleft = root->left; pright = root->right;

        if(pleft==NULL && pright==NULL) return true;
        
        if(pleft!=NULL && pright!=NULL) {
            if(pleft->val != pright->val) return false;
            return twoNodes(pleft, pright);
        }
        
        return false;
    }

    bool twoNodes(TreeNode *left, TreeNode *right) {
        if(left==NULL && right==NULL) return true;
        if(left!=NULL && right!=NULL) {
            if(left->val != right->val) return false;
            return twoNodes(left->left, right->right) && twoNodes(left->right, right->left);
        }

        return false;
    }
};

class SolutionVOfficial {
public:
    bool isSymmetric(TreeNode* root) {
        return twoNodes(root, root);
    }

    bool twoNodes(TreeNode *left, TreeNode *right) {
        if(left==NULL && right==NULL) return true;
        if(left==NULL || right==NULL) return false;
        return (left->val == right->val)
                && twoNodes(left->left, right->right)
                && twoNodes(left->right, right->left);
    }
};

