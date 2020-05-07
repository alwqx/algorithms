/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
#include <vector>
#include <stdio.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int i = 0;
        TreeNode *p = helper(nums, 0, nums.size()-1, i);
        return p;
    }

    TreeNode* helper(vector<int>& nums, int start, int end, int index) {
        TreeNode *pNode;
        printf("[%d]start %d, end %d\n", index, start, end);
        if(start > end) return pNode;
        
        int mid = (start+end)/2;
        printf("[%d]mid %d, nums[mid] %d\n", index, mid, nums[mid]);
        pNode->val = nums[mid];
        pNode->left = helper(nums, start, mid-1, index+1);
        pNode->right = helper(nums, mid+1, end, index+1);

        return pNode;
    }
};

int main() {
    // vector<int> testcase = {-10, -3, 0, 5, 9};
    vector<int> testcase = {-10};
    
    TreeNode *p = Solution().sortedArrayToBST(testcase);
    // printf("%d\n", p->val);
    return 0;
}
