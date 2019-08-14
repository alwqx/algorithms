# 排序

## 选择排序
### 概念
1. 从数组中选择最小的元素a
2. 将a与第一个元素交换位置
3. 在剩下的元素中找到最小的位置b
4. 将b和第二个元素交换位置
5. 重复，直到数组有序

### 代码
```java
public static void sort(Comparable[] a) {
    int n = a.length;
    for(int i=0; i<n; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++)
            if(SortUtil.less(a[j], a[minIndex])) minIndex=j;
        SortUtil.exch(a, i, minIndex);
        assert SortUtil.isSorted(a, 0, i);
    }
}
```

### 分析
1. 时间复杂度 O(N*N)
2. 空间复杂度 O(1)

## 插入排序
### 概念
1. 从第一个元素开始，该元素可以认为已经被排序
2. 取出下一个元素，在已经排序的元素序列中从后向前扫描
3. 如果该元素（已排序）大于新元素，将该元素移到下一位置
4. 重复步骤3，**直到找到已排序的元素小于或者等于新元素的位置**
5. 将新元素插入到该位置后
6. 重复步骤2~5

Insertion Sort 和打扑克牌时，从牌桌上逐一拿起扑克牌，在手上排序的过程相同。举例：Input: {5 2 4 6 1 3}。
1. 首先拿起第一张牌, 手上有 {5}。
2. 拿起第二张牌 2, 把 2 insert 到手上的牌 {5}, 得到 {2 5}。
3. 拿起第三张牌 4, 把 4 insert 到手上的牌 {2 5}, 得到 {2 4 5}。
4. 以此类推。

### 代码
```java
public static void sort(Comparable[] a) {
    int n = a.length;
    for(int i=1; i<n; i++) {
        for(int j=i; j>0&&SortUtil.less(a[j], a[j-1]); j--)
            SortUtil.exch(a, j, j-1);
        assert SortUtil.isSorted(a, 0, i);
    }
}
```
### 分析
取决于输入中元素的初始顺序，受初始顺序的影响较大
1. 时间复杂度 O(N*N)
2. 空间复杂度 O(1)

## 希尔排序
### 概念
1. 改进后的插入排序
2. 选择间隔h，使数组中间隔h的元素都是有序的，称为`h有序数组`
3. 将h递减到1，整个数组有序

希尔排序比较难以理解

### 代码
```java
public static void sort(Comparable[] a) {
    int n = a.length;
    int h=1;
    while(h<n/3) h=3*h+1;

    while(h>=1) {
        for(int i=h; i<n; i++) {
            for(int j=i; j>=h&&SortUtil.less(a[j], a[j-h]); j-=h)
                SortUtil.exch(a, j, j-h);
        }
        h/=3;
    }
}
```

## 归并排序
归并是指将两个有序数组合并成一个大的有序数组，在排序中是一种递归的概念。

### 概念
1. 将数组分成两半，然后分别排序，将结果合并
2. 对左子部分和右子部分分别归并排序

### 代码
递归法
```java
public static void merge(Compareabe[] a, int low, int mid, int high) {
    int i=low, j=mid+1;
    for(int k=low; k<=high; k++) aux[k] = a[k];

    for(int k=low; k<=high; k++)
        if(i>mid)                       a[k] = aux[j++];
        else if(j>high)                 a[k] = aux[j++];
        else if(less(aux[j], aux[i]))   a[k] = aux[j++];
        else                            a[k] = aux[i++];
}
```

自顶向下法
```java
public class Merge {
    private static Comparable[] aux;
    public static void sort(Comparable[] a) {
        aux = new Comparable[a.length];
        sort(a, 0, a.length);
    }

    private static void sort(Comparable[] a, int low, int high) {
        if(high <= low) return;
        int mid = (low+high)/2;
        sort(a, low, mid);
        sort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}
```

### 分析
1. 时间复杂度：O(NlogN)
2. 空间复杂度：O(N)

## 快速排序
### 定义

### 代码
```c
void qsort(int v[], int left, int right) {
    int i, last;
    void swap(int v[], int i, int j);

    if(left>=right) return;
    swap(v, left, (left+right)/2);
    last = left;
    for(i=left+1; i<=right; i++)
        if(v[i] < v[left]) swap(v, ++last, i);

    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}
```
```java
public static void sort(Comparable[] a) {
    StdRandom.shuffle(a);
    sort(a, 0, a.length-1);
    assert SortUtil.isSorted(a);
}

private static void sort(Comparable[] a, int low, int high) {
    if(low>=high) return;

    int j = partition(a, low, high);
    sort(a, low, j-1);
    sort(a, j+1, high);
}

private static int partition(Comparable[] a, int low, int high) {
    int i=low, j=high+1;
    Comparable v = a[low];

    while(true) {
        // find item on low to swap
        while(SortUtil.less(a[++i], v))
            if(i==high) break;
        
        // find item on high to swap
        while(SortUtil.less(v, a[--j]))
            if(j==low) break;

        if(i>=j) break;
        SortUtil.exch(a, i, j);
    }

    // put partitioning item v at a[j]
    SortUtil.exch(a, low, j);
    // now, a[lo .. j-1] <= a[j] <= a[j+1 .. hi]
    return j;
}
```
### 分析
时间复杂度：O(NlogN)  
空间复杂度：?

## 冒泡排序
### 定义
它重复地走访过要排序的元素列，依次比较两个相邻的元素，如果他们的顺序（如从大到小、首字母从A到Z）错误就把他们交换过来。走访元素的工作是重复地进行直到没有相邻元素需要交换，也就是说该元素列已经排序完成。
### 代码
```c
void bubble_sort(int v[], int n) {
    int i, j, flag=1;
    
    for(i=0; i<n; i++) {
        for(j=i+1; j<n-1; j++)
            if(v[j-1] < v[j]) {
                swap(v, j-1, j);
                flag = 0;
            }
        if(flag == 0) return;
    }
}
```

### 分析
时间复杂度：O(N^2)  
空间复杂度：O(1)

## TODOs
堆排序  
桶排序  
基数排序