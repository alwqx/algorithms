排序算法参考[LeetCode数组排序](https://leetcode-cn.com/problems/sort-an-array/)

里面介绍了：
- 快速排序
- 堆排序
- 归并排序

# 快速排序

快排的核心思路/方法是**分区**，每执行一次分区函数，排序数组就有一个元素被放在了正确的位置，返回该位置。

分区函数决定最终效果的好坏。下面介绍集中分区方法，自己只需**深入理解记忆其中一个，降低负担**。

## 默认左端为枢纽
```cpp
int partition(vector<int>& nums, int low, int high) {
    int i, pivot=nums[low], pos=low;
    swap(nums[high], nums[low]);

    for(i=low; i<=high; i++)
        if(nums[i] < pivot)
            swap(nums[i], nums[pos++]);

    swap(nums[pos], nums[high]);
    return pos;
}
```
**这个方法有个缺陷，在数组是降序排列等特殊情况下，复杂度降为O(n^2)**，详细找下原因。我们引入舍伍德概率算法，使得排序的时间复杂度和输入无关。

使用概率随机在[low, high]选择一个位置和low交换，然后再进行分区。


两端逼近，参考[最常用的排序——快速排序](https://wiki.jikexueyuan.com/project/easy-learn-algorithm/fast-sort.html)中的图解
```cpp
int partition(vector<int>& nums, int low, int high) {
    int i=low, j=high+1, pivot=nums[low];
    while(i < j) {
        while(i<high && nums[++i] <= pivot) {}
        while(j>low && nums[--j] >= pivot) {}

        if(i < j) swap(nums[i], nums[j]);
    }

    swap(nums[j], nums[low]);
    return j;
}
```


## 完整代码
```cpp
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int partition(vector<int>& nums, int low, int high) {
    int i=low, j=high+1;
    int pivot = nums[low];

    while(i<j) {
        while(i<high && nums[++i] <= pivot) {}
            // if(i == high) break;

        while(j>low && nums[--j] >= pivot) {}
            // if(j == low) break;

        if(i<j) swap(nums[i], nums[j]);
    }

    swap(nums[j], nums[low]);
    return j;
}

int partition1(vector<int>& nums, int low, int high) {
    int pivot = nums[low];
    swap(nums[high], nums[low]);
    int pos = low;
    for(int i=low; i<=high; i++) {
        if(nums[i] < pivot)
            swap(nums[i], nums[pos++]);
    }

    swap(nums[pos], nums[high]);
    return pos;
}

void shullfle(vector<int>& nums) {
    int i, j;
    for(i=nums.size()-1; i>=0; i--) {
        j = rand() % (i+1);
        swap(nums[i], nums[j]);
    }
}

int select(vector<int>& nums, int k) {
    if(k<1 || k>nums.size()) return -1;
    k--;
    // shullfle(nums);
    int pos, low=0, high=nums.size()-1;
    while(low < high) {
        pos = partition(nums, low, high);
        if(k == pos) return nums[pos];
        else if(k < pos) high = pos-1;
        else low = pos+1;
    }

    return nums[low];
}

void quick(vector<int>& nums, int low, int high) {
    if(low >= high) return;
    int pos = partition1(nums, low, high);
    quick(nums, low, pos-1);
    quick(nums, pos+1, high);
}

void show(vector<int>& nums) {
    int i, size=nums.size();
    for(i=0; i<size; i++) {
        printf("%d", nums[i]);
        if(i==size-1) printf("\n");
        else printf(" ");
    }
}

int main() {
    vector<int> nums = {5,8,1,4,2,9,70,4};
    quick(nums, 0, nums.size()-1);
    show(nums);

    shullfle(nums);
    show(nums);
    printf("%d\n", select(nums, 1));
    printf("%d\n", select(nums, 2));
    printf("%d\n", select(nums, 3));
    printf("%d\n", select(nums, 4));

    return 0;
}
```

# 归并排序
归并排序的采用**分-合**的思想，
1. 分：先把数组从中间分成两部分，分别对左、右两部分递归进行归并排序然后合并到一起的时候进行排序。
2. 合：假设左、右两部分已经排序好，然后把两部分合并在一起，此时左、右元素需要进行比较

代码如下：
```cpp
class Merge {
private:
    vector<int> aux;
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        int i, j, k;
        for(i=low; i<=high; i++) aux[i] = nums[i];

        i=low, j=mid+1;
        for(k=low; k<=high; k++) {
            if(i>mid) nums[k] = aux[j++];
            else if(j>high) nums[k] = aux[i++];
            else if(aux[i] < aux[j]) nums[k] = aux[i++];
            else nums[k] = aux[j++];
        }
    }

    void helper(vector<int>& nums, int low, int high) {
        if(low >= high) return;

        int mid = (low+high)/2;
        helper(nums, low, mid);
        helper(nums, mid+1, high);
        merge(nums, low, mid, high);
    }

    void sort(vector<int>& nums) {
        int size = nums.size();
        aux = vector<int>(size, 0);
        helper(nums, 0, size-1);
    }

    void shullfle(vector<int>& nums) {
        int i, j;
        for(j=nums.size()-1; j>=0; j--) {
            i = rand()%(j+1);
            swap(nums[i], nums[j]);
        }
    }

    void show(vector<int>& nums) {
        int i, size=nums.size();
        for(i=0; i<size; i++) {
            printf("%d", nums[i]);
            if(i != size-1) printf("-");
            else printf("\n");
        }
    }
};

int main() {
    vector<int> nums = {5,8,1,4,2,9,70,4};

    Quick quick;
    quick.show(nums);
    quick.sort(nums, 0, nums.size()-1);
    quick.show(nums);
    quick.shullfle(nums);
    quick.show(nums);

    Merge merge;
    merge.show(nums);
    merge.sort(nums);
    merge.show(nums);

    printf("select:%d\n", quick.select(nums, 2));
    return 0;
}
```

## 参考
- [快速排序的4种优化](https://blog.csdn.net/qq_38289815/article/details/82718428)