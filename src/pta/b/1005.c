// https://pintia.cn/problem-sets/994805260223102976/problems/994805320306507776
#include <stdio.h>

#define MAXN 101

int main() {
    int i, K, n, len;
    int a[MAXN] = {0};

    scanf("%d", &K);
    for(i=0; i<K; i++) {
        scanf("%d", &n);
        a[n] = 1;
    }

    len = K; // remember len
    for(i=0; i<MAXN; i++) {
        if(a[i] == 1) { // input number
            n = i;
            while(n>1) {
                if(n%2==0)  n/=2;
                else        n = (3*n+1)/2;
                if(n<MAXN && a[n]) {
                    a[n] = 0; // mark not key number
                    len--;
                    if(n<i) break; // 剪枝
                }
            }
        }
    }

    for(i=100; i>0; i--) {
        if(a[i]) {
            printf("%d", i);
            if(--len != 0) printf(" ");
        }
    }
}