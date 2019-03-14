// https://eoj.i64d.com/problem/2570/
#include <stdio.h>

int prime(int n) {
    if(n == 1) return 0;
    int flag = 1;
    int i;
    if(n==1 || n==2 || n==3)    return flag;
    if (n%6!=1 && n%6!=5)       return 0;

    for(i=5; i*i<=n; i+=6)
        if(n%i==0 || n%(i+2)==0) {
            flag = 0;
            break;
        }

    return flag;
}

int main() {
    int i, j, n, m, cnt;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        cnt = 0;
        scanf("%d", &m);
        for(j=1; j<=m/2; j++)
            if(prime(j) && prime(m-j+1)) cnt++;
        printf("%d\n", cnt*2);
    }

    return 0;
}