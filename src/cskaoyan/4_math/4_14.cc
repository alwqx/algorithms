/*
王道考研机试指南 p108

C/C++高精度计算N的阶乘
*/
#include <stdio.h>

#define MAXN 1000

struct bigInteger {
    int digit[MAXN];
    int size;

    void init() {
        int i;
        for(i=0; i<MAXN; i++) digit[i] = 0;
        size = 0;
    }

    void set(int x) {
        init();
        while(x) {
            digit[size++] = x%10000;
            x /= 10000;
        }
    }

    void output() {
        int i;
        for(i=size-1; i>=0; i--)
            if(i == size-1) printf("%d", digit[i]);
            else            printf("%04d", digit[i]);
        putchar('\n');
    }

    bigInteger operator * (int x) const {
        bigInteger ret;
        ret.init();

        int i, tmp, carry = 0; // 进位
        for(i=0; i<size; i++) {
            tmp = digit[i]*x+carry;
            carry = tmp/10000;
            tmp %= 10000;
            ret.digit[ret.size++] = tmp;
        }

        if(carry) ret.digit[ret.size++] = carry;
        return ret;
    }
} a;

int main() {
    int i, n;
    while(scanf("%d", &n) != EOF) {
        a.init();
        a.set(1);
        for(i=1; i<=n; i++) {
            a = a * i;
        }
        a.output();
    }

    return 0;
}