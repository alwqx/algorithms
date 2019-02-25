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

## 7-15
[计算圆周率](https://pintia.cn/problem-sets/14/problems/795)

本题在题意理解上至关重要，注意题干：根据下面关系式，求圆周率的值，**直到最后一项的值小于给定阈值**，第一个小于阈值的项也要加上。

## 7-16
[求符合给定条件的整数集](https://pintia.cn/problem-sets/14/problems/796)

不要用枚举的方法

## 7-17
[爬动的蠕虫](https://pintia.cn/problem-sets/14/problems/797)

测试点少考虑情况，即N<U的情况

## 7-18<sup style="color:red">**<sup>
[二分法求多项式单根](https://pintia.cn/problem-sets/14/problems/798)

题目没有给出具体的`阈值`是多少，因此需要合理的拓展。

错误解法：
```c++
// https://pintia.cn/problem-sets/14/problems/798

#include <iostream>
#include <iomanip>
#define DELTA 1e-5

using namespace std;

int f(double a3, double a2, double a1, double a0, double x) {
    double ret = a3*x*x*x + a2*x*x + a1*x +a0;
    if(ret > 0)         return 1;
    else if(ret == 0)   return 0;
    else                return -1;
}

int main() {
    double a3, a2, a1, a0;
    double a, b, mid;
    cin>>a3>>a2>>a1>>a0;
    cin>>a>>b;

    int fa, fb, ret;
    fa = f(a3, a2, a1, a0, a);
    fb = f(a3, a2, a1, a0, b);
    mid = (a+b)/2;
    ret = f(a3, a2, a1, a0, mid);

    while(b-a>DELTA) {
        if(ret == fa)
            a = mid;
        else if(ret == fb)
            b = mid;
        mid = (a+b)/2;
        ret = f(a3, a2, a1, a0, mid);
    }

    cout<<fixed<<setprecision(2)<<ret;
    return 0;
}
```

## 7-19
[支票面额](https://pintia.cn/problem-sets/14/problems/799)

注意使用二分法降低时间复杂度

## 7-21
[求特殊方程的正整数解](https://pintia.cn/problem-sets/14/problems/801)

?>注意**减枝思想**的运用，去掉没必要的运算

code costs 4ms
```c++
if(N<=4) {
    for(x=1; x<N; x++)
        for(y=x; y<=N-x*x; y++){
            if(x*x+y*y == N) {
                cout<<x<<" "<<y<<endl;
                found = 0;
            }
        }
} else {
    for(x=1; x*x<N; x++)
        for(y=x; y<=N-x*x; y++){
            if(x*x + y*y == N) {
                cout<<x<<" "<<y<<endl;
                found = 0;
            }
        }
}
```

code costs 19ms
```c++
if(N<=4) {
    for(x=1; x<N; x++)
        for(y=x; y<N; y++){
            if(x*x+y*y == N) {
                cout<<x<<" "<<y<<endl;
                found = 0;
            }
        }
} else {
    for(x=1; x<=N/2; x++)
        for(y=x; y<N/2; y++){
            if(x*x + y*y == N) {
                cout<<x<<" "<<y<<endl;
                found = 0;
            }
        }
}
```

## 7-22
[龟兔赛跑](https://pintia.cn/problem-sets/14/problems/802)

题目相对抽象，规律不好找，[参考](https://blog.csdn.net/weixin_37571609/article/details/68927271)

## 7-23
[币值转换](https://pintia.cn/problem-sets/14/problems/803)

代码参考：[2018年冬季寒假作业4--PTA 币值转换](https://www.cnblogs.com/youlanghua/p/10413356.html)

此题灵活性比较大，自己的题目有2个测试集无法通过。参考方案是倒序处理的。

## 总结
1. 看清题目要求
2. 理解问题和解答方案
3. 考虑临界情况
4. `减枝`思想运用，减少不必要的运算