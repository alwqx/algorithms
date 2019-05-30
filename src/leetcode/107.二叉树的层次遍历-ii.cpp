/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
#include <algorithm>
#include <queue>

using namespace std;

void layerOrder(TreeNode *root, vector<vector<int>>& res) {
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        vector<int> tmp;
        int len = q.size();

        for(int i=0; i<len; i++) {
            TreeNode *now = q.front();
            q.pop();
            tmp.push_back(now->val);
            if(now->left) q.push(now->left);
            if(now->right) q.push(now->right);
        }
        res.push_back(tmp);
    }
}

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;

        layerOrder(root, res);
        vector<vector<int>> ans;
        for(int i=res.size()-1; i>=0; i--)
            ans.push_back(res[i]);
        
        return ans;
    }
};

class SolutionV2 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == NULL) return ret;

        int n;
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()) {
            n = qt.size();
            vector<int> tmp;
            for(int i=0; i<n; i++) {
                TreeNode *now = qt.front();
                qt.pop();
                tmp.push_back(now->val);
                if(now->left) qt.push(now->left);
                if(now->right) qt.push(now->right);
            }
            ret.push_back(tmp);
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};

class SolutionV1 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == NULL) return ret;

        int n, tmp;
        n = 1; tmp = 0;

        queue<TreeNode*> qn;
        qn.push(root);

        while(!qn.empty()) {
            vector<int> rett;
            for(int i=0; i<n; i++) {
                TreeNode *t = qn.front();
                rett.push_back(t->val);
                if(t->left != NULL) {
                    qn.push(t->left);
                    tmp++;
                }
                if(t->right != NULL) {
                    qn.push(t->right);
                    tmp++;
                }
                qn.pop();
            }
            ret.push_back(rett);
            n = tmp;
            tmp = 0;
        }
        
        reverse(ret.begin(), ret.end());

        return ret;
    }
};

