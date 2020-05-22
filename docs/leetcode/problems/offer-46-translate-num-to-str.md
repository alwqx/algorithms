# 面试题46. 把数字翻译成字符串
这个题目的思路不是很好想，参考了别人的思路，这里自己模拟下。

首先把数字表示成x1x2x3,...,xn的形式，
1. x1,x2,...,x_i-1的方案数为f(i-1)
1. x1,x2,...,x_i-2的方案数为f(i-2)

那么结果为
1. 如果x_i-1x_i这两个数可以翻译，结果为f(i-1)+f(i-2)
2. 如果x_i-1x_i这两个数不可以翻译，结果为f(i-1)

这样整个过程就是一个动态的过程，从一个初始点开始，慢慢动态到最终结果。

```cpp
class Solution {
public:
    int translateNum(int num) {
        int c, n, x, y=num%10, a=1, b=1;
        while(num) {
            num /= 10;
            x = num%10;
            n = 10*x + y;
            c = (n<=9 || n>25)?b:a+b;
            a = b;
            b = c;
            y = x;
        }

        return b;
    }
}
```

下面是递归解法：
```cpp
class Solution {
public:
    int translateNum(int num) {
        if(num < 10) return 1;
        int n = num%100;
        if(n<=9 || n>25) return translateNum(num/10);

        return translateNum(num/10)+translateNum(num/100);
    }
}
```