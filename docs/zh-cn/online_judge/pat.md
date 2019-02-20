## 基础编程题目集
https://pintia.cn/problem-sets/14/problems

### 6-7
https://pintia.cn/problem-sets/14/problems/739

如何判断一个数是完全平方数，代码参考：
```c
int IsTheNumber(const int N) {
    int s, n, i, a[10];
    for(i=0; i<10; i++)
        a[i] = 0;
    
    s = sqrt(N);
    if(s*s == N) {
        int tmp = N;
        for(; tmp>0; tmp/=10) {
            n = tmp%10;
            a[n]++;
        }
        for(i=0; i<10; i++)
            if(a[i]>=2)
                return 1;
    }

    return 0;
}
```

### 6-9
https://pintia.cn/problem-sets/14/problems/741

注意临界情况：输入0 0,应该返回1。

### 6-10
https://pintia.cn/problem-sets/14/problems/742

大数阶乘，大数超过了64位存储极限，应该如何处理。

### 6-11
https://pintia.cn/problem-sets/14/problems/743

1. 求中位数，理解提议，确定是递增排序还是递减排序。**笔者自己当初递减排序了**，虽然排序方法对了，但是测试样例不对
2. 虽然MAXN是10,但是用O(n*n)的排序算法过不了N非常大的情况
3. 使用希尔排序、快排、归并等方法

## 7-1
https://pintia.cn/problem-sets/14/problems/781

概念比较绕，没理解清楚很难接触来，可以说考察的是**思辨**能力。参考https://blog.csdn.net/qq_36810403/article/details/70939134

## 7-5
https://pintia.cn/problem-sets/14/problems/785

!>把问题想复杂似乎是我经常犯的错误，要谨记教训。按行输出就行，[参考](https://blog.csdn.net/qq_32999795/article/details/53733766)

## 7-7
[12-24小时制](https://pintia.cn/problem-sets/14/problems/787)

自己的解法不仅复杂，而且不好调试
```c
int main() {
    int hour, min;
    scanf("%d:%d", &hour, &min);

    if(hour==12 && min==0)
        printf("12:0 PM\n");
    else if(hour==0 && min==0)
        printf("0:0 AM\n");
    else if(hour==24 && min==0)
        printf("12:0 AM\n");
    else if(hour>12) {
        printf("%d:%d PM\n", hour-12, min);
    } else
        printf("%d:%d AM\n", hour, min);
    
    return 0;
}
```

## 总结
1. 看清题目要求
2. 理解问题和解答方案
3. 考虑临界情况