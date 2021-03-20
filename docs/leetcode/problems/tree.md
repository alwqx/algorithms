# 树系列

# 101 对称二叉树
简单题型，但是要注意里面的方法。借助一些基本的数据结构(栈、队列、递归、抽象)和思路来解决这个问题。

我自己首先采用的是`问题分割`的思想，先求树的对称树，然后比较这两个树是否相等。用连两子函数实现，内存占用大约18M。

后来的思路是**抽象**，**将二叉树问题抽象成根节点、左子树、右子树三个节点间的关系，把三个节点的对称关系理清楚了使用递归来做**。直接原地比较二叉树，大概使用15M内存，节省了一部分内存。

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
    bool isSymmetric(TreeNode* root) {
        return judge(root, root);
    }

    bool judge(TreeNode* l, TreeNode* r) {
        if(l == NULL) {
            return r == NULL;
        }

        if(r == NULL) {
            return false;
        }

        return l->val==r->val && judge(l->left, r->right) && judge(l->right, r->left);
    }
};


// 使用队列
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
```

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

```cpp
class Solution{
public:
    TreeNode* bbb(TreeNode *root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;
        TreeNode *left = bbb(root->left, p, q);
        TreeNode *right =
    }
}
```

# 124. 二叉树中的最大路径和
自己想到了可能用dfs做，但是没有具体思路。看了官网题解。

**重点是理解题目的含义**，**题干要求计算的最大路径和，不是指从根节点到叶子节点的一条最大路径和，而是任意节点到任意节点**。根据递归的思想，只考虑`当前节点`、`左子树`、`右子树`，先求出当前节点的最大贡献值，然后在递归步骤中更新结果。函数dfs(node)计算当前节点的最大路径和，分别求出左、右子树的最大路径和记为left、right，然后结合node的值更新结果ans。

最后返回node->val + max(left, right)，是因为dfs返回的是节点最大贡献值，不能返回node->val+left+right(这是当前阶段的最大值，不能和上层节点构成路径)。

```cpp
class Solution {
public:
    int ans = INT_MIN;

    int dfs(TreeNode *node) {
        if(!node) return 0;

        // 负值用0代替，相当于没有考虑这条路径
        int left = max(dfs(node->left), 0);
        int right = max(dfs(node->right), 0);

        int n = node->val + left + right;
        ans = max(ans, n);

        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
}
```

# 113. 路径总和 II
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

有思路，但是未必能写出来，多练练：
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
    vector<vector<int>> ans;
    vector<int> cur;

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ans;
    }

    void dfs(TreeNode* node, int sum) {
        if(!node) return;
        if(!node->left && !node->right) {
            if(node->val == sum) {
                cur.push_back(node->val);
                ans.push_back(cur);
                cur.pop_back();
            }
            return;
        }

        if(node->left) {
            cur.push_back(node->val);
            dfs(node->left, sum-node->val);
            cur.pop_back();
        }

        if(node->right) {
            cur.push_back(node->val);
            dfs(node->right, sum-node->val);
            cur.pop_back();
        }
    }
};
```

# 230. 二叉搜索树中第K小的元素
## 法一
这个方法是自己想到的，对二叉搜索树先序遍历，将元素放到数组aux中，然后返回aux[k-1]即可。

时间和空间复杂度都是O(n);

## 法二
这个方法是参考别人的代码，依然是先序遍历，但是遍历过程中加上判断，而不使用数组。时间复杂度O(k)，空间复杂度O(1)。

```cpp
class Solution {
public:
    void dfs(TreeNode *node, bool& finded, int& ans, int& pos, int k) {
        if(!node || finded) return;

        dfs(node->left, finded, ans, pos, k);
        if(++pos == k) {
            ans = node->val;
            finded = true;
            return;
        }
        dfs(node->right, finded, ans, pos, k);
    }

    int kthSmallest(TreeNode *root, int k) {
        int ans=-1, pos=0;
        bool finded = false;
        dfs(root, finded, ans, pos, k);
        return ans;
    }
};
```

下面的代码更加精简一些：
```cpp
class Solution {
private:
    int ans, pos=0;
public:
    void dfs(TreeNode *node, int k) {
        if(!node) return;
        dfs(node->left, k);
        if(++pos == k) {
            ans = node->val;
            return;
        }
        dfs(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};
```

# 根据遍历顺序构建二叉树中的递归顺序问题
LeetCode上的105和106都是这个问题:
1. 先序遍历 preorder = [3,9,20,15,7]
2. 中序遍历 inorder = [9,3,15,20,7]
3. 后序遍历 postorder = [9,15,7,20,3]

解答思路是使用递归重新模拟二叉树的遍历过程，根据给出的遍历顺序构造相关节点，然后形成整棵树。在实际编程过程中有一些关键点需要理解：
1. 递归过程中求出node后，node->left和node->right的先后顺序
2. 在算法思路中，根节点的位置pos如何变化

## 根据先序和中序
先序遍历的代码思路是先找到根节点，然后找到左右子树，接着递归求左右子树的根节点。解决代码：
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

        // ihead是根节点的位置，在上面TreeNode *node = new TreeNode(preorder[pos])中已经被使用了，
        // 所以这里ihead不会参与到递归的范围中
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
1. pos是`引用传递`，node->left=helper(...)调用过程中会不断递归左子树，因此先序遍历中的根节点、子问题中的根节点都会被遍历到，这样pos就需要跟着递归而增加，因此是引用传递
2. node->left在node->right的前面，这是由于先序、中序遍历节点中顺序特点决定的。先序中对应着根节点，然后通过根节点把中序分割成左右两个子树。**中序遍历中左->中->右的遍历特点决定分割的左子树在前面，右子树在后面**，所以递归中先求node->left，然后是node->right。
3. 递归前的`if(left <= ihead-1)`和`if(ihead+1 <= right)`是否可以去掉？不能去掉，`TreeNode *node = new TreeNode(preorder[pos]);`中node的左右子树本身是NULL，在下面递归中如果子树是空，就不需要递归，**避免不必要的++pos运算**，这样会扰乱pos的值。

## 根据中序和后序
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