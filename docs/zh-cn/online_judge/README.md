# Online Judge

## 平台
- [PTA(Programming Teaching Assistant)](https://pintia.cn/)
- [LeetCode-ZH](https://leetcode-cn.com/)
- [LeetCode](https://leetcode.com/)
- [ECNU OJ](https://acm.ecnu.edu.cn/) [备用网址](https://eoj.i64d.com/)
- [codeforces](http://codeforces.com/)

## 基础知识
### int类型
- 32bit
- 64bit

## 常用高效算法
1. 快排
1. 判断素数，[参考](https://blog.csdn.net/huang_miao_xin/article/details/51331710)
```c
int prime(long int n) {
    int flag = 1;
    long int i;
    if(n==1 || n==2 || n==3)    return flag;
    if (n%6!=1 && n%6!=5)       return 0;

    for(i=5; i*i<=n; i+=6)
        if(n%i==0 || n%(i+2)==0) {
            flag = 0;
            break;
        }

    return flag;
}
```

2. 最大公约数

3. 最小公倍数