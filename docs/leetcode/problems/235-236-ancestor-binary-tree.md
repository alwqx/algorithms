# 235 二叉搜索树的最近公共祖先
二叉搜索树自身具有一些性质：左节点值小于根节点，右节点的值大于根节点。
递归版：
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;

        int cv=root->val, pv=p->val, qv=q->val;
        if(cv<pv && cv<qv) return lowestCommonAncestor(root->right, p, q);
        else if(cv>pv && cv>qv) return lowestCommonAncestor(root->left, p, q);

        return root;
    }
};
```

非递归：
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *res = root;
        if(!res) return res;

        int cv, pv=p->val, qv=q->val;
        while(true) {
            cv = res->val;
            if(cv<pv && cv<qv) res = res->right;
            else if(cv>pv && cv>qv) res = res->left;
            else break;
        }

        return res;
    }
};
```



# 236 二叉树的最近公共祖先
初次看到题目，`感觉上`是使用dfs，但是编程细节上还不清楚怎么dfs。

**dfs思想中，本质是把树的问题简化成当前节点、左节点(左子树)、右节点(右子树)之间的问题**。

因此，思路是在dfs过程中，判断当前节点(`node`)、左子树(`left`)和右子树(`right`)中是否存在需要搜索的值。dfs返回的结果bool，表示当前节点的树是否包含需要搜索的节点。情况如下：
- left包含，right包含，则node为所求节点，返回true
- left包含，right不包含；或者left不包含，right包含，返回true
- left，right，node都不包含，返回false
- node包含，返回true

详细代码：
```cpp
class Solution {
public:
    TreeNode *ans;
    bool dfs(TreeNode *node, TreeNode *p, TreeNode *q) {
        if(!node) return false;
        bool left = dfs(node->left, p, q);
        bool right = dfs(node->right, p, q);

        if((left&&right) || ((node==p||node==q)&&(left||right))) ans = node;

        return left||right||(node==p||node==q);
    }

    TreeNode* lowestCommonAncestor(TreeNode *node, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }
}
```

上面dfs的思路是判断节点所在树是否存在目标节点，还可以表示节点所在树包含的目标节点个数：
- left包含，right包含，node节点为所求节点，返回2
- left、right其中一个包含，node不包含，返回1
- left、right其中一个包含，node包含，返回2
- left、right不包含，返回node是否包含

```cpp
class Solution {
public:
    TreeNode *ans;
    int dfs(TreeNode *node, TreeNode *p, TreeNode *q) {
        if(!node) return 0;
        int nmid = (node==p||node==q)?1:0;
        int left = dfs(node->left, p, q);

        if(nmid+left == 2) {
            if(ans == NULL) ans = node;
            return 2;
        }

        int right = dfs(node->right, p, q);
        if(nmid+left+right == 2) {
            if(ans == NULL) ans = node;
            return 2;
        }

        return nmid+left+right;
    }

    TreeNode* lowestCommonAncestor(TreeNode *node, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }
}
```

终极简化版
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if(left && right) return root;
        return (left==NULL)?right:left;
    }
}
```