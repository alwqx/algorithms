/*
王道考研机试指南 p106

C/C++高精度计算
*/
#include <stdio.h>
#include <string.h>

#define MAXN 1000

struct bigInteger {
    int digit[MAXN];
    int size;

    void init() {
        int i;
        for(i=0; i<MAXN; i++) digit[i] = 0;
        size = 0;
    }

    // 从字符串中提取整数
    void set(char s[]) {
        init();
        int i, j, t, c, len = strlen(s);
        for(i=len-1, j=0, t=0, c=1;i>=0; i--) {
            t += (s[i]-'0')*c;
            j++;
            c *= 10;
            if(j==4 || i==0) {
                digit[size++] = t;
                j = 0;
                c = 1;
                t = 0;
            }
        }
    }

    void output() {
        int i;
        for(i=size-1; i>=0; i--)
            if(i==size-1)   printf("%d", digit[i]);
            else            printf("%04d", digit[i]);

        putchar('\n');
    }

    bigInteger operator + (const bigInteger &A) const {
        bigInteger ret;
        ret.init();
        int i, tmp, carry = 0;

        for(i=0; i<A.size || i<size; i++) {
            tmp = A.digit[i] + digit[i] + carry;
            carry = tmp/10000;
            tmp %= 10000;
            ret.digit[ret.size++] = tmp;
        }
        if(carry != 0)
            ret.digit[ret.size++] = carry;

        return ret;
    }
}a, b, c;

char s1[MAXN+2], s2[MAXN+2];

int main() {
    while(scanf("%s %s", s1, s2) != EOF) {
        a.set(s1); b.set(s2);
        c = a + b;
        c.output();
    }
    
    return 0;
}