# 数组
TODO：**加上思路！**

# [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return -1;
        if(nums.size() == 1) return nums[0];

        int mid, l=0, r=nums.size()-1;
        if(nums[r] > nums[0]) return nums[0];

        while(l <= r) {
            mid = l + (r-l)/2;
            if(nums[mid] > nums[mid+1]) return nums[mid+1];
            if(nums[mid-1] > nums[mid]) return nums[mid];

            if(nums[mid] > nums[0]) l = mid+1;
            else r = mid - 1;
        }

        return -1;
    }
};
```

# [154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)

脑袋要灵活，不要陷入**找到最佳解决方法中**，可以先找到简单粗暴的解法，然后慢慢优化。

比如[C++简洁代码（四种方法）](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/cjian-ji-dai-ma-by-orangeman-18/)题解用了4个方法，暴力、排序、二分等。

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid, l=0, r=nums.size()-1;
        while(l < r) {
            mid = (l+r)>>1;
            if(nums[mid] > nums[r]) l = mid+1;
            else if(nums[mid] < nums[r]) r = mid;
            else r--;
        }

        return nums[l];
    }
};
```

为什么这种解法是对的？还有没有其它方法？**不能局限于把问题解决出来，而是要弄明白原理，是否还有其它优化的方法？**

# [31. 下一个排列](https://leetcode-cn.com/problems/next-permutation/)
起初被题目难倒了，不知道如何入手。

后来看解析发现可以用`分割法`。把问题分成两部分，首先是全降序的，重新排序返回即可；然后非降序里面，从后往前找第一个不递增的元素a，和后面的比a大的最小数b交换，然后从a后面反转数组。

# [剑指 Offer 66. 构建乘积数组](https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/)
自己的方法O(n^2)，超时。

之前的代码自己没看懂，看了[Krahets的题解](https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/solution/mian-shi-ti-66-gou-jian-cheng-ji-shu-zu-biao-ge-fe/)迷迷糊糊弄明白了。

后面有个大佬的解释很清晰，就是使用动态规划来做，维护两个数组left[i]和right[i]，分别表示ans[i]左侧和右侧的乘积，最后ans[i]=left[i]*right[i]。


# [45. 跳跃游戏 II](https://leetcode-cn.com/problems/jump-game-ii/)
这道题目我没有思考清楚解题思路，自己采用dfs的方式，但是时间复杂度太高了，一直超时。

**看了题解，~~核心思路是确保下一步跳的位置的值最大~~**，核心思路理解错了，导致做不出来题目。真正的核心思路是**确保下一步到的位置和下一步的潜在步长加起来最大，这样才能保证未来跳的最远**。新的思路下代码如下：
```cpp
/*
这段代码相对较长，和官方题解中的代码相比多很多，但是思路很直接，比较好理解。
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 0;

        int i, v, cur=0, pos=0, mpos=0, cnt=0;
        while(cur < size-1) {
            v = nums[cur];
            if(cur+v >= size-1) {
                cnt++;
                break;
            }

            mpos = INT_MIN;
            for(i=1; i<=v && cur+i<size; i++) {
               if(mpos < i+nums[cur+i]) {
                   mpos = i + nums[cur+i];
                   pos = cur+i;
               }
            }
            cur = pos;
            cnt++;
        }

        return cnt;
    }
};
```

另外，自己起初没有想到贪心的思路，想到的是深搜，写出来的代码超时了，即使使用一些条件剪枝，依然超时...
```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 0;

        priority_queue<int, vector<int>, greater<int>> ans;
        vector<bool> visit(size, false);
        dfs(ans, 0, 0, nums);
        // sort(ans.begin(), ans.end());
        return ans.top();
    }

    void dfs(priority_queue<int, vector<int>, greater<int>> &ans, int pos, int len, vector<int>& nums) {
        int size = nums.size();
        if(pos >= size) {
            return;
        }
        if(pos == size-1) {
            ans.push(len);
            return;
        }

        int v = nums[pos];
        if(v == 0) return;
        if(pos+v >= size-1) {
            ans.push(len+1);
            return;
        }

        for(int i=1; i<=v; i++) {
            if(!ans.empty() && ans.top()<= len+1) {
                return;
            }
            dfs(ans, pos+i, len+1, nums);
        }
    }
};
```

# [341. 扁平化嵌套列表迭代器](https://leetcode-cn.com/problems/flatten-nested-list-iterator/)
抽象能力不行，想到了递归和栈的思路，但是比较模糊，没有具体明确的实现方案，一直在试探如何写出代码，最后还是没有写出来，参考了题解。

# [1524. 和为奇数的子数组数目](https://leetcode-cn.com/problems/number-of-sub-arrays-with-odd-sum/)
需要一定的数学基础，`前缀和`的套路。

常规思路超时了，需要使用数学方法减少计算过程，化繁为简。[官方题解](https://leetcode-cn.com/problems/number-of-sub-arrays-with-odd-sum/solution/he-wei-qi-shu-de-zi-shu-zu-shu-mu-by-leetcode-solu/)该如何理解呢？

首先，前缀和只有两种可能，要么是奇数，要么是偶数。我们这里是要统计前缀和为奇数的个数。

其次，题解的代码是遍历数组中的元素求前缀和，分别统计前缀和为奇数和偶数的个数，用odd和even存储。

最后，我们统计的方法是**以元素i结尾的，[0, i], [1, i],...,[i-1, i]中和为奇数的子数组的个数，这不就是i前面和为偶数的前缀和的数量么。**

```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int i, odd=0, even=1, size=arr.size();
        const int MODULO = 1000000007;
        int cnt=0, sum=0;

        for(i=0; i<size; i++) {
            sum += arr[i];
            // 这里求和部分，如果前缀和是偶数，就加奇数，否则偶数
            cnt = (cnt + (sum%2==0?odd:even)) % MODULO;

            // 这里是分别统计奇数和偶数前缀和的个数
            if(sum%2 != 0) {
                odd++;
            } else {
                even++;
            }
        }

        return cnt;
    }
};
```

最后的问题是，为什么even是从1开始？

从1开始要和整体的解题思路相一致，当i=0时，sum=arr[0]，此时odd和even的初始值要和题设一致，i=0的情况下：
- 如果sum是奇数，cnt应该为1，`cnt = (cnt + (sum%2==0?odd:even)) % MODULO`取even的值，所以even初始值应该为1
- 如果sum是偶数，cnt应该为0，`cnt = (cnt + (sum%2==0?odd:even)) % MODULO`取odd的值，所以odd初始值应该为0