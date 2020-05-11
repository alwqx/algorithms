# 根据遍历顺序构建二叉树中的递归顺序问题
LeetCode上的105和106都是这个问题:
1. 先序遍历 preorder = [3,9,20,15,7]
2. 中序遍历 inorder = [9,3,15,20,7]
3. 后序遍历 postorder = [9,15,7,20,3]

解答思路是使用递归重新模拟二叉树的遍历过程，根据给出的遍历顺序构造相关节点，然后形成整棵树。在实际编程过程中有一些关键点需要理解：
1. 递归过程中求出node后，node->left和node->right的先后顺序
2. 在算法思路中，根节点的位置pos如何变化

## 根据先序和中序
解决代码：
```cpp
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
    TreeNode* helper(vector<int>& preorder, int& pos, vector<int>& inorder, int left, int right) {
        if(left>right || pos>=preorder.size()) return nullptr;
        TreeNode *node = new TreeNode(preorder[pos]);
        int ihead=left;
        while(ihead<=right && preorder[pos]!=inorder[ihead]) ihead++;

        if(left <= ihead-1) node->left = helper(preorder, ++pos, inorder, left, ihead-1);
        if(ihead+1 <= right) node->right = helper(preorder, ++pos, inorder, ihead+1, right);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos = 0;
        return helper(preorder, pos, inorder, 0, inorder.size()-1);
    }
};
```

上面的代码有以下注意点：
1. pos是`引用传递`，node->left=helper(...)调用过程中会不断递归把左子树，因此先序遍历中的根节点、子问题中的根节点都会被遍历到，这样pos就需要跟着递归而增加，因此是引用传递
2. node->left在node->right的前面，这是由于先序、中序遍历节点中顺序特点决定的。先序中对应这根节点，然后通过根节点把中序分割成左右两个子树。**中序遍历中左->中->右的遍历特点决定分割的左子树在前面，右子树在后面**，所以递归中先求node->left，然后是node->right。
3. 递归前的`if(left <= ihead-1)`和`if(ihead+1 <= right)`是否可以去掉？不能去掉，`TreeNode *node = new TreeNode(preorder[pos]);`中node的左右子树本身是NULL，在下面递归中如果子树是空，就不需要递归，**避免不必要的++pos运算**，这样会扰乱pos的值。


## 根据后序和中序
解决代码：
```cpp
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
    TreeNode* helper(vector<int>& postorder, int &pos, vector<int>& inorder, int left, int right) {
        if(left>right || pos<0) return nullptr;
        
        TreeNode *root = new TreeNode(postorder[pos]);
        int ihead = left;
        while(ihead<=right && inorder[ihead] != postorder[pos]) ihead++;
        
        if(ihead+1 <= right) root->right = helper(postorder, --pos, inorder, ihead+1, right);
        if(left <= ihead-1) root->left = helper(postorder, --pos, inorder, left, ihead-1);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pos = postorder.size()-1;
        return helper(postorder, pos, inorder, 0, inorder.size()-1);

    }
};
```

后续遍历的代码思路和先序类似，不同点是`node->right在node->left的前面`，这是由后序遍历和中序遍历的特点决定的。

思路是通过后序遍历找到树和各个子树的根，然后用根把中序遍历分割成左右子树，递归求子树，得到最终结果。而后序遍历的根是按照`左->右->根`从后往前计算的，根节点前面是右子树，因此在这个思路下递归时先求node->right，这样才能和后序遍历从后往前找根节点的特点对应上。