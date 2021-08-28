/*
王道考研机试指南 p111

C/C++高精度计算 大数进制转换
*/
#include <stdio.h>
#include <string.h>

#define MAXN 100

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
        for(i=size-1; i>=0; i++)
            if(i == size-1) printf("%d", digit[i]);
            else            printf("%04d", digit[i]);
    }

    bigInteger operator * (int x) const {
        bigInteger ret;
        ret.init();
        int i, tmp, carry=0;
        for(i=0; i<size; i++) {
            tmp = digit[i]*x+carry;
            ret.digit[ret.size++] = tmp%10000;
            carry = tmp/10000;
        }
        if(carry) ret.digit[ret.size++] = carry;

        return ret;
    }

    bigInteger operator + (const bigInteger &A) const {
        bigInteger ret;
        ret.init();
        int i, tmp, carry=0;
        
        for(i=0; i<A.size || i<size; i++) {
            tmp = A.digit[i]+digit[i]+carry;
            carry = tmp/10000;
            tmp %= 10000;
            ret.digit[ret.size++] = tmp;
        }

        if(carry) ret.digit[ret.size++] = carry;
        return ret;
    }

    bigInteger operator / (int x) const {
        bigInteger ret;
        ret.init();
        int i, t, remainder=0; // 余数

        for(i=size-1; i>=0; i--) {
            t = (remainder*10000+digit[i])/x;
            remainder = (remainder*10000+digit[i])%x;
            ret.digit[i] = t;
        }

        ret.size = 0;
        for(i=0; i<MAXN; i++)
            if(digit[i]) ret.size = i;
        ret.size++;

        return ret;
    }

    int operator % (int x) const {
        int i, t, remainder=0;
        for(i=size-1; i>=0; i--)
            remainder = (remainder*10000+digit[i])%x;
        return remainder;
    }


} a, b, c;

int main() {
    char str[10000], ans[10000];
    int i, t, len, n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        scanf("%s", str);
        len = strlen(str);
        a.set(0);
        b.set(1);
        for(i=len-1; i>=0; i--) {
            if(str[i]>='0' && str[i]<='9')
                t = str[i] - '0';
            else t = str[i]-'A'+10;

            a = a + b * t;
            b = b * m;
        }

        int size = 0;
        do{
            t = a%n;
            if(t>=10) ans[size++] = t-10+'a';
            else ans[size++] = t+'0';
            a = a/n;
        }while(a.digit[0]!=0 ||a.size!=1);
        for(i=size-1; i>=0; i--) {
            if(ans[i]>='0'&&ans[i]<='9')    printf("%d", ans[i]-'0');
            else                            printf("%d", ans[i]-'a'+10);
        }
        printf("\n");
    }

    return 0;
}
