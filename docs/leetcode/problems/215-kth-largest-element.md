# 215 第K大元素

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
            pos = partition(nums, left, right);
            if(kth == pos) break;
            else if(kth < pos) right = pos-1;
            else left = pos+1;
        }

        return nums[kth];
    }
}
```


## 参考
- [215Leetcode题解-数组中的第K个最大元素 c++实现三种解法 暴力法、使用小顶堆和选择算法 图示讲解](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-cshi-xian-sa/)
- [215Leetcode题解-快速排序思想，数组划分](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/kuai-su-pai-xu-si-xiang-shu-zu-hua-fen-by-liushang/)