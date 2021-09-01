# 堆 Heap

# 复合元素的堆定义
```cpp
class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int n:nums) m[n]++;

        // 注意下面的复合元素堆定义方法
        // 该方法定义的是小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype (&cmp)> heap(cmp);

        return res;
    }
};
```

使用结构体的定义，[参考-ffreturn的题解](https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/solution/cjian-dan-yi-dong-you-xian-dui-lie-by-ff-t8cs/)
```cpp
struct item {
    int x, y, sum;
    item(int sum, int x, int y): sum(sum), x(x), y(y) {}
};

// 重载运算符 <
// 这种写法在堆中很难理解，语义不一致了
// <的语义在priority_queue中的含义是“值小的在顶部”，即小顶堆
bool operator< (item a, item b) {
    return a.sum > b.sum;
}
```

或者在结构体里面重载<，参考`算法笔记 6.6节-priority_queue常见用法详解`：
```cpp
struct Node {
    int x, y, sum;
    friend bool operator < (item a, item b) {
        return a.sum > b.sum;
    }
};
```

# [347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)
使用堆做比较方便，就是堆元素是pair复合类型时比较不好定义，参考上面代码

# [215 第K大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)

## 排序/暴力
这是我最先想到的方法，C++里有函数可以直接对数组排序，而且题干中说明k是合法的，代码简单易懂。
```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
}
```

上面代码的时间复杂度是O(N*logN)，是排序的时间复杂度，空间复杂度O(1);

## 堆
使用小顶堆，确保大小为k，遍历一次数组，堆顶元素即为所求。
```cpp
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    findKthLargest(vector<int>& nums, int k) {
        int ans=0, size=nums.size();
        if(size==0 || k>size) return 0;

        priority_queue<int, vector<int>, greater<int>> gp;
        for(int i=0; i<size; i++) {
            gp.push(nums[i]);
            if(gp.size() > k) gp.pop();
        }

        ans = gp.top();
        return ans;
    }
}
```

时间复杂度O(N*logK)，空间复杂度O(k)。

## 分区选择
这个方法基于快速排序思想，需要非常熟悉快速排序思想。
```cpp
class Solution {
public:
    int partition(vector<int>& nums, int left, int right, int pos) {
        int pivot = nums[pos];
        swap(nums[right], nums[pos]);
        // pre表示pos对应元素最终在数组中的位置
        // 即该位置左边小，右边大
        int i, pre=left;
        for(i=left; i<=right; i++) {
            if(nums[i]<pivot) {
                swap(nums[i], nums[pre++]);
            }
        }

        swap(nums[pre], nums[right]);
        return pre;
    }

    int quick(vector<int>& nums, int left, int right, int kth) {
        if(left == right) return nums[left];

        // choose random pos
        srand(time(0));
        int pos = left + (rand() % (right-left));
        pos = partition(nums, left, right, pos);
        if(kth == pos) return nums[pos];
        else if(kth < pos) return quick(nums, left, pos-1, kth);

        return quick(nums, pos+1, right, kth);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        if(size==0 || k>size) return 0;

        return quick(nums, 0, size-1, size-k);
    }
}
```

时间复杂度O(N*logK)，空间复杂度O(k)

非递归版
```cpp
class Solution {
public:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        int left=low, right=high;
        while(left < right) {
            while(left<right && nums[right]>=pivot) right--;
            while(left<right && nums[left]<=pivot) left++;

            if(left < right) swap(nums[left], nums[right]);
        }

        swap(nums[left], nums[low]);
        return left;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int left=0, right=nums.size()-1;
        int pos=0, kth=nums.size()-k;
        while(left < right) {
            // 每次都有一个元素被放置在正确的位置，返回该位置的下标
            pos = partition(nums, left, right);
            // 下标和kth是对应的，相等则正好找到该位置
            if(pos == kth) break;
            // kth < pos 说明得到的下标比kth大
            else if(kth < pos) right = right-1;
            else left = left+1;
        }

        return nums[kth];
    }
}
```


## 参考
- [215Leetcode题解-数组中的第K个最大元素 c++实现三种解法 暴力法、使用小顶堆和选择算法 图示讲解](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-cshi-xian-sa/)
- [215Leetcode题解-快速排序思想，数组划分](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/kuai-su-pai-xu-si-xiang-shu-zu-hua-fen-by-liushang/)