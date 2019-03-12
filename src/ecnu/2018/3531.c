// https://eoj.i64d.com/problem/3531/
#include <stdio.h>
#include <stdlib.h>

int dp(int i, int *a);

int main() {
    int i, m, n, t;
    scanf("%d %d", &m, &n);

    if(m==0) {
        printf("0\n");
        return 0;
    }
    
    int *a = (int *) malloc(sizeof(int)*(m+1));
    for(i=0; i<=m; i++) a[i] = 0;
    for(i=0; i<n; i++) {
        scanf("%d", &t);
        a[t] = 1;
    }

    printf("%d\n", dp(m, a));
    return 0;
}

int dp(int i, int *a) {
    if(i == 0)  return 0;
    if(a[i])    return 0;

    if(i == 1)  return 1;
    if(i == 2)
        if(a[1])    return 1;
        else        return 2;
    if(i == 3) {
        if(a[2])
            if(a[1])  return 1;
            else      return 2;
        else {
            if(a[1])  return 2;
            else      return 4;
        }
    }

    return dp(i-1, a)+dp(i-2, a)+dp(i-3, a);
}