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

### 7-1
https://pintia.cn/problem-sets/14/problems/781

概念比较绕，没理解清楚很难接触来，可以说考察的是**思辨**能力。参考https://blog.csdn.net/qq_36810403/article/details/70939134

### 7-5
https://pintia.cn/problem-sets/14/problems/785

!>把问题想复杂似乎是我经常犯的错误，要谨记教训。按行输出就行，[参考](https://blog.csdn.net/qq_32999795/article/details/53733766)

### 7-7
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

### 7-15
[计算圆周率](https://pintia.cn/problem-sets/14/problems/795)

本题在题意理解上至关重要，注意题干：根据下面关系式，求圆周率的值，**直到最后一项的值小于给定阈值**，第一个小于阈值的项也要加上。

### 7-16
[求符合给定条件的整数集](https://pintia.cn/problem-sets/14/problems/796)

不要用枚举的方法

### 7-17
[爬动的蠕虫](https://pintia.cn/problem-sets/14/problems/797)

测试点少考虑情况，即N<U的情况

### 7-18<sup style="color:red">**<sup>
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

### 7-19
[支票面额](https://pintia.cn/problem-sets/14/problems/799)

注意使用二分法降低时间复杂度

### 7-21
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

### 7-22
[龟兔赛跑](https://pintia.cn/problem-sets/14/problems/802)

题目相对抽象，规律不好找，[参考](https://blog.csdn.net/weixin_37571609/article/details/68927271)

### 7-23
[币值转换](https://pintia.cn/problem-sets/14/problems/803)

代码参考：[2018年冬季寒假作业4--PTA 币值转换](https://www.cnblogs.com/youlanghua/p/10413356.html)

此题灵活性比较大，自己的题目有2个测试集无法通过。参考方案是倒序处理的。

### 7-26
[单词长度](https://pintia.cn/problem-sets/14/problems/806)

涉及输入字符串处理、统计的问题是薄弱项，结合K&R中的相关示例代码多练习。

测试案例中**开头结尾多空格**，输出数字会有一个空格
```shell
    abc    .
3 %
```
[参考](https://www.muchenhen.com/2018/10/28/pta%E9%A2%98%E7%9B%AE%E9%9B%86%EF%BC%9A7-26-%E5%8D%95%E8%AF%8D%E9%95%BF%E5%BA%A6/)

### 7-27
[指定遍历次数的排序](https://pintia.cn/problem-sets/14/problems/807)

!>Not Implemented

### 7-28
[猴子选大王](https://pintia.cn/problem-sets/14/problems/808)

使用`暴力解法`，用程序模拟选猴王的过程。使用数组进行建模。

### 7-30
[字符串的冒泡排序](https://pintia.cn/problem-sets/14/problems/810)

使用C编写，遇到错误提示**Expression must be a modifiable L-value**，数组的item如果是字符数组，不能直接修改，
要`声明成指针`才行。[参考](https://stackoverflow.com/questions/6008733/expression-must-be-a-modifiable-l-value)

### 7-29
[删除字符串中的子串](https://pintia.cn/problem-sets/14/problems/809)

重点是解决嵌套问题，ccatat与cat如何处理。下面的代码是自己实现的，有bug，不能处理嵌套的情况
```c
// https://pintia.cn/problem-sets/14/problems/809

#include <stdio.h>
#include <string.h>

#define MAXN 80

void readline(char s[]);

int main() {
    char S1[MAXN], S2[MAXN];
    readline(S1);
    readline(S2);

    int i, j, k, n, len_s1=strlen(S1), len_s2=strlen(S2);
    while(i<len_s1) {
        j = 0;
        while(S2[j] != '\0') {
            if(S1[i] == S2[j]) {
                i++;
                j++;
            } else 
                break;
        }
        if(j == len_s2)
            i--;
        else {  // not match, print
            for(n=i-j; n<=i; n++)
                putchar(S1[n]);
        }
    }

    return 0;
}

void readline(char s[]) {
    int c, i = 0;
    while((c=getchar()) != '\n')
        s[i++] = c;

    s[i] = '\0';
}
```

### 7-35
[有理数均值](https://pintia.cn/problem-sets/14/problems/815)

综合数组、输入输出等知识，需要多看。

### 7-37
[整数分解为若干项之和](https://pintia.cn/problem-sets/14/problems/2990)

[参考](https://www.cnblogs.com/masterchd/p/7801445.html)

### 7-38
[数列求和-加强版](https://pintia.cn/problem-sets/14/problems/3006)

[参考](http://www.voidcn.com/article/p-rranmapg-wk.html)

## 基础算法

### 6-1
[单链表逆转](https://pintia.cn/problem-sets/15/problems/724)
思想方法与具体实现：
- 指针变量
- 新建链表
- 递归实现

### 6-2
[顺序表操作集](https://pintia.cn/problem-sets/15/problems/725)

这道题目的描述信息容易让人误解。其实`Last`指的是最后一个元素的下一个位置。
```c
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};
```

### 6-5
[链式表操作集](https://pintia.cn/problem-sets/15/problems/728)

用于调试的Print函数写错了，浪费了大量时间调试。

对于这种`List Insert(List L, ElementType X, Position P)`插入位置也是List(Position)类型，可以用下面的方法直接找L。而不用再家一个pre指针。
```c
List head = L;
while(L) {
    if(L->Next == P) {
        ....
    }
    L=L->Next;
}
```

### 6-6
[带头结点的链式表操作集](https://pintia.cn/problem-sets/15/problems/729)

多练习

### 6-7
[在一个数组中实现两个堆栈](https://pintia.cn/problem-sets/15/problems/730)

!>注意打印的格式，是否换行，是否有`.`等格式不匹配问题。

### 6-8
[本题要求给定二叉树的高度](https://pintia.cn/problem-sets/15/problems/731)

!>注意考虑临界情况：空树

### 6-9
[二叉树的遍历](https://pintia.cn/problem-sets/15/problems/732)

!>难点是如何层序遍历。参考中的做法是实现一个数组队列，使用head和base来判断队列是否为空，值得借鉴

[参考](https://blog.csdn.net/yangd9292/article/details/83626386)

### 6-12
[二叉搜索树的操作集](https://pintia.cn/problem-sets/15/problems/927)

基础题，需要牢固掌握。[参考](https://blog.csdn.net/wanmeiwushang/article/details/51921821)

?>注意if(!BST) <==> if(BST==NULL)

### 7-1
[最大子列和问题](https://pintia.cn/problem-sets/15/problems/709)

[参考](https://blog.csdn.net/jimtrump/article/details/72782852)分析得很到位。

在线算法、分治算法

## PTA-B
### 1003
[我要通过！](https://pintia.cn/problem-sets/994805260223102976/problems/994805323154440192)

本题第一个难点是**准确理解题目含义**。
1. `字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；`：这个很容易理解
2. `任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；`：这个很容易理解
3. `如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。`：这句最难理解。该条件是利用1,2推断出来的。在1的基础上：
    - `PAT`(x='')是合理的，则`PAAT`是正确的。
    - `APATA`(x='A')是合理的，则`APAATAA`是正确的。
    - `AAPATAA`(x='AA')是合理的，则`AAPAATAAAA`是正确的。
    - ...
    - 归纳后可得a*b=c

[PAT-B 1003. 我要通过！(20)](https://www.jianshu.com/p/59ea02ed0c6c)
[1003 我要通过！ （20 分）](https://zhuanlan.zhihu.com/p/46465425)

### 1004
[成绩排名](https://pintia.cn/problem-sets/994805260223102976/problems/994805321640296448)

思路不难，使用在线算法可在O(N)时间内完成。问题出在C语言的语法上
```c
#include <stdio.h>
#define MAXN 10

int main() {
    char a[MAXN], b[MAXN];
    scanf("%s", b);
    a = b;

    printf("%s", a);
}
```
类似上面的代码，编译时报错**assignment to expression with array type**,原因是C中左值必须是可修改的，数组不是可修改的类型，所以不能赋值。

**字符数组要初始化，不然有奇怪的问题，原因未知...**

### 1005
[继续(3n+1)猜想 （25 point(s)）](https://pintia.cn/problem-sets/994805260223102976/problems/994805320306507776)

要点：
1. 明确输入的都是正整数，所以数组索引下标为0用不到
2. 理解**覆盖**、**关键字**的含义

### 1007
[素数对猜想 （20 point(s)）](https://pintia.cn/problem-sets/994805260223102976/problems/994805317546655744)

本题难点在于素数判断的时间复杂度。

### 1010
[一元多项式求导](https://pintia.cn/problem-sets/994805260223102976/problems/994805313708867584)

感觉这题的测试案例不全或者不合理。参考别人的答案可以AC，但是以下输入
```shell
./a.out
3 0 2 3
// output
 6 3
// 其实应该是
6 3
```

自己有2个案例错了，但是题目没给是什么案例，导致自己不好调试。

### 1012
[数字分类](https://pintia.cn/problem-sets/994805260223102976/problems/994805311146147840)
不能用结果是否为零来判断打印N

### 1013
[数素数 （20 point(s)）](https://pintia.cn/problem-sets/994805260223102976/problems/994805309963354112)

注意格式控制和素数高效判断算法

### 1014
[福尔摩斯的约会 （20 point(s)）](https://pintia.cn/problem-sets/994805260223102976/problems/994805308755394560)

!>自己为了图省事，使用了库函数，把范围扩大了，不能用`isupper(c)`代替`c>='A'&&c<='N`。

```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXN 61

char wa[][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    char s1[MAXN], s2[MAXN], s3[MAXN], s4[MAXN];
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%s", s3);
    scanf("%s", s4);

    int i;
    for(i=0; i<strlen(s1); i++) {
        // if(s1[i]==s2[i] && isupper(s1[i])) {
        if(s1[i]==s2[i] && s1[i]>='A'&&s1[i]<='G') {
            printf("%s ", wa[s1[i]-'A']);
            i++;
            break;
        }
    }
    for(; i<strlen(s1); i++) {
        if(s1[i] == s2[i]) {
            if(isdigit(s1[i])) {
                printf("0%c:", s1[i]);
                break;
            // } else if(isupper(s1[i])) {
            } else if(s1[i]>='A' && s1[i]<='N') {
                printf("%d:", s1[i]-'A'+10);
                break;
            }
        }
    }
    
    for(i=0; i<strlen(s3); i++) {
        if(s3[i]==s4[i] && isalpha(s3[i])) {
            printf("%02d\n", i);
            break;
        }
    }
    
    return 0;
}
```

### 1015
[德才论 （25 point(s)）](https://pintia.cn/problem-sets/994805260223102976/problems/994805307551629312)

排序有点绕，用C++中的vector相对容易些。[参考](https://blog.csdn.net/daoshen1314/article/details/87093400)

## 总结
0. 掌握C/C++基本用法，常用函数库。STL模板等。
1. 看清题目要求
2. 理解问题和解答方案
3. 考虑临界情况
4. `减枝`思想运用，减少不必要的运算