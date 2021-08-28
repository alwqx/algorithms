# ECNU Online Judge

## 2018

### 3529
[3529. 梵高先生](https://eoj.i64d.com/problem/3529/)
计算组合数时，数据大小可能超过int长度限制，需要使用long int和减枝
1. C(n, k)，k>n/2时，计算C(n, n-k)
2. 使用long int

### 3531
[3531. 定西，爬楼梯](https://eoj.i64d.com/problem/3531/)

爬楼梯动态规划改编，很基础，多看看多练习。

### 3532
[3532. 热河路](https://eoj.i64d.com/problem/3532/)

这道题是数学规律题。先看规律：
```shell
第n个数字(s(n))   
1           1
2           10
4           100
7           1000
11          10000
16          100000
22          1000000
......
```
在无线序列中第1、2、4、7、11、16、22、...位置上的数字均为1。
s(1)=1
s(2)=s(1)+1
s(3)=s(2)+2
s(4)=s(3)+3
s(5)=s(4)+4
s(6)=s(5)+5
...
s(n)=s(n-1)+n-1=n-1+n-2+n-3+...+1+1
    = n(n-1)/2+1
也就是说输入的数N满足**N=n(n-1)/2+1且n为整数**，则输出1，否则输出0。下面根据方程求n
```
n(n-1)/2+1 = N
n*n-n = 2(N-1)
4n*n-4n = 8(N-1)
4n*n-4n+1 = 8(N-1)+1
(2n-1)(2n-1) = 8(N-1)+1
n = sqrt{8(N-1)+1}/2+1
```

**自己没有解出n和N的式子，而是通过for循环确定N的区间，时间复杂度太高**

c代码如下
```c
while(t--) {
    scanf("%lld", &p);
    double x=(1+sqrt(1.0+8.0*(p-1)))/2.0;
    if(x-(long long int)x==0) printf("1\n");
    else printf("0\n");
}
```

## 2017 保研题
### 3346
[3346. 皇后问题](https://eoj.i64d.com/problem/3346/)

直接根据题意编写代码时间复杂度很高，而且容易超时。

根据坐标间的关系来判断点在二维上的横纵斜关系判断可以减少计算复杂度，但是O(n*n)，数据量太大还是超时。

用四个数组记录横、纵、主、副上点的个数，然后一次遍历求和。以横向为例，row表示：
如果row[i]为0，1，说明第i行不存在冲突的皇后，如果row[i]>=2，则根据排列组合的知识，从里面取2个，有row[i]*(row[i]-1)/2个皇后。

[参考](https://blog.csdn.net/KlD1412/article/details/79613615)

### 3357
[3357. 吉吉木的野望](https://eoj.i64d.com/problem/3357/)

不会做，自己写的代码输出很奇怪。
```c
#include <stdio.h>

void v1();
void v2();

int main() {
    v1();
}

void v1() {
    int d;
    long long i, k;
    scanf("%d %lld", &d, &k);
    
    double s = 0.0;
    long long a = 1 + (k-1)*d;
    for(i=k; i>=1; i--) {
        if(i==k)    s = 1.0/((double) a);
        else        s = 1.0/((double) a+1/s);
        a -= d;
    }

    printf("%.16f\n", s);
}
```

### 3337
[3337. 我认识你](https://eoj.i64d.com/problem/3337/)
用邻接表做，找共同定点。了解下C++中的数据结构和STL

### 3338
[3338. 双塔问题](https://eoj.i64d.com/problem/3338/)

不知道怎么用DP做

### 3355
[3355. 开心消消乐](https://eoj.i64d.com/problem/3355/)

没有思路

### 3356
[3356. 解方程](https://eoj.i64d.com/problem/3356/)

### 3340
[3340. 又是 GCD](https://eoj.i64d.com/problem/3340/)

### 3339
[3339. 提交答案题](https://eoj.i64d.com/problem/3339/)

## 2009
### 2573
[2573. Hub Connection plan](https://eoj.i64d.com/problem/2573/)

MST，有难度，并查集+克鲁斯卡尔

### 2575
[2575. Separate Connections](https://eoj.i64d.com/problem/2575/)

### 2574
[2574. Principles of Compiler](https://eoj.i64d.com/problem/2574/)