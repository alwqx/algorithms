/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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

/**

 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;

        queue<TreeNode*> qt;
        qt.push(root);
        TreeNode *cur;
        int len, level=0;

        while(!qt.empty()) {
            vector<int> tmp;
            len = qt.size(); 
            while(len--) {
                cur = qt.front();
                qt.pop();
                if(level%2==0) tmp.push_back(cur->val);
                else tmp.insert(tmp.begin(), cur->val);
                if(cur->left) qt.push(cur->left);
                if(cur->right) qt.push(cur->right);
            }

            level++;
            res.emplace_back(tmp);
        }

        return res;
    }
};

/**
双端队列的速度是最快的
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;

        deque<TreeNode*> qt;
        qt.push_back(root);
        TreeNode* cur;
        bool flag = true;
        int len;

        while(!qt.empty()) {
            vector<int> tmp;
            len = qt.size(); 
            while(len) {
                if(flag) {
                    cur = qt.front();
                    qt.pop_front();
                    if(cur->left) qt.push_back(cur->left);
                    if(cur->right) qt.push_back(cur->right);
                } else {
                    cur = qt.back();
                    qt.pop_back();
                    if(cur->right) qt.push_front(cur->right);
                    if(cur->left) qt.push_front(cur->left);
                }
                tmp.push_back(cur->val);
                len--;
            }

            flag = !flag;
            res.emplace_back(tmp);
        }

        return res;
    }
};
// @lc code=end

