# 面试题33. 二叉搜索树的后序遍历序列

根据二叉搜索树的性质，找到左子树、右子树的区间，然后递归判断。

```cpp
class Solution {
private:
    vector<int> pr;
public:
    bool helper(int left, int right) {
        if(left >= right) return true;

        int i, j, m;
        for(i=left; pr[i]<pr[right]; i++) {}
        m = i;
        for(; pr[i]>pr[right]; i++) {}

        return i==right && helper(left, m-1) && helper(m, right-1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        int len = postorder.size(); 
        if(len <= 1) return true;
        pr = postorder;
        return helper(0, len-1);
    }
}
```