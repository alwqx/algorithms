# 数组


# 常用思想
1. 对数组排序后处理
2. 双指针法
3. 快慢指针

TODO：**加上思路！**

1.  [162. 寻找峰值](/leetcode/problems/162)


# [162. 寻找峰值](https://leetcode-cn.com/problems/find-peak-element/)

自己想到的是遍历法，时间复杂度是O(n)，而且代码不简炼，但是把一些特出情况单独拿出来处理，方便理解：
```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty()) return -1;
        if(nums.size() == 1) return 0;
        if(nums.size() == 2) return nums[0]>nums[1]?0:1;

        int i;
        for(i=1; i<nums.size()-1; i++) {
            if(i==1 && nums[i]<nums[i-1]) return 0;
            if(nums[i-1]<nums[i] && nums[i]>nums[i+1]) return i;
        }

        if(i == nums.size()-1) return i;
        return -1;
    }
};
```

官方参考中的遍历思路非常简单，但是隐含了很多情况，需要自己去理解：
```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] > nums[i+1]) return i;
        }

        return nums.size()-1;
    }
};
```

## 二分法
这个思路是对二分法的理解和灵活应用。

递归版本：
```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return search(nums, 0, nums.size()-1);
    }

    int search(vector<int> nums, int left, int right) {
        if(left == right) return left;
        int mid = (left + right)/2;
        if(nums[mid] > nums[mid+1]) return search(nums, left, mid);
        else return search(nums, mid+1, right);
    }
};
```

迭代版本：
```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int mid, left=0, right=nums.size()-1;
        while(left < right) {
            mid = (left+right)>>1;
            if(nums[mid] > nums[mid+1]) right = mid;
            else left = mid+1;
        }

        return left;
    }
};
```

迭代版中，`while(left < right)`中为什么不取`=`？因为我们是要逼近一个元素，如果取等号，left会最终越过我们需要的结果。

递归版本函数调用需要时间，递归栈也占用一定的存储，所以迭代法是效率最高的。

# [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)

自己没有想到二分搜索的思路，这个题目本质上是考察二分搜索思想的应用。

参考官方后的代码：
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return -1;
        if(nums.size() == 1) return nums[0];

        int mid, left=0, right=nums.size()-1;
        if(nums[right] > nums[0]) return nums[0];

        while(left <= right) {
            mid = left + (right-left)/2;
            if(nums[mid] > nums[mid+1]) return nums[mid+1];
            if(nums[mid-1] > nums[mid]) return nums[mid];

            if(nums[mid] > nums[0]) left = mid+1;
            else right = mid-1;
        }

        return -1;
    }
}
```

# [152. 乘积最大子数组](https://leetcode-cn.com/problems/maximum-product-subarray/)
思路是dp，但是没有弄清楚当前的最大值如何求，看了[官方题解](https://leetcode-cn.com/problems/maximum-product-subarray/solution/cheng-ji-zui-da-zi-shu-zu-by-leetcode-solution/)，知道要维护两个dp变量...本质还是要理解这个最优子结构的求解过程。

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i, t, mx, mn, res=nums[0];
        int mindp = res, maxdp = res;

        for(i=1; i<nums.size(); i++) {
            t = nums[i];
            // 下面这行很重要，不用临时变量保存mindp
            // 和maxdp，两个值在下面的计算中会变化，导致结果有问题
            mx = maxdp, mn = mindp;
            maxdp = max(t*mx, max(t, t*mn));
            mindp = min(t*mn, min(t, t*mx));
            res = max(res, maxdp);
        }

        return res;
    }
};
```

# [90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/)
看到题目完全没有思路...

看了[别人的思路](https://leetcode-cn.com/problems/subsets-ii/solution/c-shuang-100si-lu-by-lygin/)，是决策树或回溯的模板。

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    vector<int> v;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // dfs(nums, 0);
        v = nums;
        ddfs(0);
        return ans;
    }

    void ddfs(int pos) {
        ans.push_back(cur);
        if(pos == v.size()) return;

        for(int i=pos; i<v.size(); i++) {
            if(i>pos && v[i-1]==v[i]) continue;
            cur.push_back(v[i]);
            ddfs(i+1);
            cur.pop_back();
        }
    }

    void dfs(vector<int>& nums, int pos) {
        ans.push_back(cur);
        if(pos == nums.size()) return;

        int i;
        for(i=pos; i<nums.size(); i++) {
            if(i>pos && nums[i-1] == nums[i]) continue;
            cur.push_back(nums[i]);
            dfs(nums, i+1);
            cur.pop_back();
        }
    }
};
```

# [81. 搜索旋转排序数组 II]()

自己的思路是先找到旋转点，然后判断target在哪个区间中，接着在对应的区间进行二分查找。
```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;

        int i = 0, rot;
        for(i=0; i<nums.size()-1; i++) {
            if(nums[i] > nums[i+1]) {
                rot = i;
                break;
            }
        }

        int left, right;
        if(nums[0] < target) {
            left = 0;
            right = rot;
        } else if(nums[0] > target) {
            left = rot+1;
            right = nums.size()-1;
        } else return true;

        int t, mid;
        while(left <= right) {
            mid = left + ((right-left)>>1);
            t = nums[mid];
            if(t > target) right = mid-1;
            else if(t < target) left = mid+1;
            else return true;
        }

        return false;
    }
};
```

在题解中看到[别人的思路](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/solution/zai-javazhong-ji-bai-liao-100de-yong-hu-by-reedfan/441802)，是直接二分判断，在循环中判断是否存在。
```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int left=0, right=nums.size()-1;

        int t, mid;
        while(left <= right) {
            mid = (left+right)/2;
            t = nums[mid];
            if(t == target) return true;

            if(nums[left] == t) left++;
            else if(nums[right] == t) right--;
            else if(t > nums[left]) {
                if(target >= nums[left] && target < t) right = mid-1;
                else left = mid+1;
            } else if(t < nums[right]) {
                // 因为nums[mid] == target在循环开始就判断过了，所以这里和上面相等的判断是
                // 取非mid位置的边界
                if(target>t && target<=nums[right]) left = mid+1;
                else right = mid-1;
            }
        }

        return false;
    }
};
```

# [80. 删除排序数组中的重复项 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/)

自己的方法是O(n)存储空间，没有想到O(1)的方法。
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> m;
        for(auto n:nums) m[n]++;
        int cur=0, tot=nums.size();
        for(auto it:m) {
            int up = 0;
            if(it.second<=2) {
                up = it.second;
            } else {
                up = 2;
                tot -= (it.second-2);
            }

            for(int j=0; j<up; j++) nums[cur++] = it.first;
        }

        return tot;
    }
};
```

下面是参考[官方题解](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/solution/shan-chu-pai-xu-shu-zu-zhong-de-zhong-fu-xiang-i-7/)的方法：
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, j=1, cnt=1;
        for(; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]) cnt++;
            else cnt = 1;

            if(cnt <= 2) nums[j++] = nums[i];
        }

        return j;
    }
};
```

思路上是双指针的思路。

# [75. 颜色分类](https://leetcode-cn.com/problems/sort-colors/)
自己有思路，但是有一段时间没有用C++刷题了，有些疏忽，代码没撸出来...

利用计数排序，注意不是一定要用map的，向量就可以。
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> m(3, 0);
        for(int i=0; i<nums.size(); i++) m[nums[i]]++;

        int i=0, j=0, p=0;
        for(; j<=2; j++) {
            for(i=0; i<m[j]; i++) nums[p++] = j;
        }
    }
};
```

一趟排序
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0=0, cur=0;
        int p2 = nums.size()-1;
        while(cur <= p2) {
            if(nums[cur] == 0) swap(nums[cur++], nums[p0++]);
            else if(nums[cur] == 2) swap(nums[cur], nums[p2--]);
            else cur++;
        }
    }
};
```

为什么cur==2的情况没有cur++，因为交换后的cur值需要参与判断。

# [74. 搜索二维矩阵](/leetcode/problems/74)


# [73 矩阵置零](https://leetcode-cn.com/problems/set-matrix-zeroes/)

题目的难点在于将空间复杂度降至O(1)。自己编写出O(m*n)和O(m+n)的代码。

O(1)的思路参考官方题解，但是在实现上有些corner case需要处理。

官方的思路是如果某个位置值为0，将该位置对应的行首、列首置位0作为标记。然后重新遍历matrix，当行首、列首为0则遍历的点置为0。**这里的第一行和第一列需要专门判断**。


# [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
二分查找中确定重复元素的左右边界，有多种解法，**非常考验思维能力**
# [16. 最接近的三数之和](https://leetcode-cn.com/problems/3sum-closest/)

[15. 三数之和](https://leetcode-cn.com/problems/3sum/)

暴力法，或者排序后利用~~二分查找~~实际上是双指针。有思路也要有工程能力，不然题目无法编码出来。

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i, j, k, sum;
        int size = nums.size();
        int res = nums[0]+nums[1]+nums[2];

        for(i=0; i<size; i++) {
            /*
            这里的i去重操作加上更加严谨，不加上也不影响提交结果。下面分析为什么要去重，重复的情况分为三种
            1. 两个重复，比如[1, 2, 2, ...]，i取第一个2时，后面的j会取到第二个2，当i+1后不需要计算后面第二个2的情况
            2. 三个重复，比如[1,2,3,3,3,...]，和1中的情况相同，后面的j会算上i过滤掉的重复
            3. 大于3个重复，比如[1,2,4,4,4,4,4,4,...]，同1， 2
            */
            if(i>0 && nums[i]==nums[i-1]) continue;


            j = i+1;
            k = size-1;
            while(j < k) {
                sum = nums[i]+nums[j]+nums[k];
                if(sum > target) k--;
                else if(sum<target) j++;
                else return sum;

                if(abs(sum-target) < abs(res-target)) {
                    res = sum;
                }
            }
        }

        return res;
    }
}
```

# [1482. 制作 m 束花所需的最少天数](https://leetcode-cn.com/problems/minimum-number-of-days-to-make-m-bouquets/)
这个思路的关键在于**如何把问题抽象成二分查找**

和之前的[959. 由斜杠划分区域](https://leetcode-cn.com/problems/regions-cut-by-slashes/)很相似。

# [74. 搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/)
[官方题解]()是按行和列分别进行二分查找的，先找到对应行，然后对该行进行二分查找。
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(), col=matrix[0].size();
        int rowi = 0;
        // 找行应该优化为二分查找
        while(rowi<row) {
            if(matrix[rowi][0]<=target && matrix[rowi][col-1]>=target) break;
            rowi++;
        }
        if(rowi >= row) return false;

        int mid, v, left=0, right=col-1;
        while(left <= right) {
            mid = (left+right)/2;
            v = matrix[rowi][mid];
            if(v < target) left += 1;
            else if(v == target) return true;
            else right -= 1;
        }

        return false;
    }
};
```

从右上角到左下角查找，O(m+n):
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int p, x=0, y=matrix[0].size()-1;
        while(x<matrix.size() && y>=0) {
            p = matrix[x][y];
            if(p>target) y--;
            else if(p<target) x++;
            else return true;
        }

        return false;
    }
};
```

将整个数据看成一维数组，这个思路自己很难想到了。
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int col = matrix[0].size();
        int mid, p, left=0, right=matrix.size()*col-1;
        while(left <= right) {
            mid = left + ((right-left)>>1);
            p = matrix[mid/col][mid%col];
            if(p < target) left = mid+1;
            else if(p > target) right = mid-1;
            else return true;
        }

        return false;
    }
};
```

# 前缀和专题
## [974. 和可被 K 整除的子数组](https://leetcode-cn.com/problems/subarray-sums-divisible-by-k/)
1. 首先定义P[i]=a[0] + ... + a[i]
2. 前缀和sum(i, j)=P[j] - P[i-1] (j>i>0)
3. 使用map存储前缀和余数为mod时对应的出现次数，因为是从左到右遍历数组，所以到第i个前缀和时，i前面的子数组都已经统计好

**这里的问题是，为么初始化m[0]=1**

## [560. 和为K的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)
和974一样的思路，**这里还是不明白，为么初始化m[0]=1**

字典中`key=0`并不是指下标为0的情况，而是指连续子数组和为k的情况，这样才会导致差为0，这种情况未必会出现，但是对应的值应该为1，因为此时子数组的和为k。---感觉这样解释也不是很对...

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


# [456. 132 模式](https://leetcode-cn.com/problems/132-pattern/)
只想到了O(n^3)的方法，连提示中的O(n^2)的方法都没有想到，二次方的解法我很容易看懂，但是题解中的其它方法我理解起来需要些时间。`总体感觉这个题目有点抽象，比较新，没见过`。

[官方题解](https://leetcode-cn.com/problems/132-pattern/solution/132mo-shi-by-leetcode-solution-ye89/)中的`枚举1`方法还需要好好理解。