// https://pintia.cn/problem-sets/14/problems/3006
#include <stdio.h>
#define MAXN 200005
typedef long long int LL;

int main() {
    LL a, n, cnt, b[MAXN];
    scanf("%lld %lld", &a, &n);
    LL i, cot, x;
    cot = cnt = 200000;
    x = 0;

    for(i=n; i>=1; i--) {
        b[cnt] = (a*i+x)%10;
        x = (a*i+x)/10;
        cnt--;
    }

    int tag = 1;
    if(x!=0) {
        printf("%lld", x);
        tag = 0;
    }

    for(i=cnt+1; i<=cot; i++) {
        printf("%lld", b[i]);
        tag = 0;
    }
    if(tag) printf("0");

    return 0;
}