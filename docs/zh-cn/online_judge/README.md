# Online Judge

## 平台
- [PTA(Programming Teaching Assistant)](https://pintia.cn/)
- [LeetCode-ZH](https://leetcode-cn.com/)
- [LeetCode](https://leetcode.com/)
- [ECNU OJ](https://acm.ecnu.edu.cn/) [备用网址](https://eoj.i64d.com/)
- [codeforces](http://codeforces.com/)

## 基础知识
### int类型
- 32bit (-2^31~2^31-1)
- 64bit (-2^63~2^63-1)

## 常用范式
1. 快排（可以使用C++中的algorithm库代替）
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
2. 最大公约数，**欧几里德算法**
3. 最小公倍数
4. 打印四种蛇形数组，顺时针，逆时针，Z，倒Z。[参考](https://blog.csdn.net/Echo_Ana/article/details/53411476)
5. 素数筛，算法需要好好看看
6. 素因数分解，多写几遍