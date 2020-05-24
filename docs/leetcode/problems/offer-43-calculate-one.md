# 面试题43. 1～n整数中1出现的次数
这个题目自己没有思路，参考的[Krahets](https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/mian-shi-ti-43-1n-zheng-shu-zhong-1-chu-xian-de-2/)大佬的解法。

Krahets的思路一开始没有理解，后来自己的草稿纸上画了20多分钟，渐渐理解了。其思路是`逐位计算`，根据该位数字的不同，来判断有多少个1，然后累加到结果上。

![](https://pic.leetcode-cn.com/78e60b6c2ada7434ba69643047758e113fa732815f7c53791271c5e0f123687c-Picture1.png)

下面以当前数字cur为0讨论，设数字是`2304`，那么0位为1的数字有`0010~2219`中把0位1去掉，即000~229，一共230个。

然后找规律，判断cur为1，为2-9时的情况。

```cpp
class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        if(n <= 0) return ans;

        int high=n/10, cur=n%10, low=0, digit=1;
        while(high!=0 || cur!=0) {
            if(cur == 0) ans += high*digit;
            else if(cur == 1) ans += high*digit + low + 1;
            else ans += (high+1)*digit;
        }

        low += 10*cur;
        cur = high%10;
        high /= 10;
        digit *= 10;
    }

    return ans;
}
```

**记住这个思路，遇到了现推理**