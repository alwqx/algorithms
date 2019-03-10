// https://pintia.cn/problem-sets/994805260223102976/problems/994805313708867584
#include <stdio.h>

#define MAXN 1000

/*
int main() {
    int a, n, t[2][MAXN], i=0;
    while(scanf("%d %d", &a, &n) != EOF) {
        t[0][i] = a;
        t[1][i] = n;
        i++;
    }

    int j, nt[2][MAXN], cnt=0;
    for(j=0; j<i; j++) {
        a = t[0][j];
        n = t[1][j];
        if(a==0 || n==0) {
            continue;
        }
        nt[0][cnt] = a*n;
        nt[1][cnt] = n-1;
        cnt++;
    }
    for(j=0; j<cnt; j++)
        if(j==cnt-1)    printf("%d %d\n", nt[0][j], nt[1][j]);
        else            printf("%d %d ", nt[0][j], nt[1][j]);

    return 0;
}*/


int main()
{
    int a, x, ac, xc, i=0;
    while(scanf("%d %d", &a, &x) != EOF) {
        xc = x;
        ac = a*x;
        if(x==1||x==0)  xc=0;
        else            xc--;

        if(i==0) {
            if(ac == 0) printf("");
            else        printf("%d %d", ac, xc);
        } else if(ac==0)  printf("");
        else            printf(" %d %d", ac, xc);
        i++;
    }

    return 0;
}