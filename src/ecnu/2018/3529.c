// https://eoj.i64d.com/problem/3529/
#include <stdio.h>

int cc(int i, int j);

int main() {
    int i, j, N;
    scanf("%d", &N);

    for(i=0; i<N; i++) {
        for(j=0; j<=i; j++)
            if(j==i)    printf("%d\n", cc(i, j));
            else        printf("%d ", cc(i, j));
    }

    return 0;
}

int cc(int n, int k) {
    if(n==0 || k==0)    return 1;
    if(n==k)            return 1;

    if(k>n/2) return cc(n, n-k);
    
    int i;
    long int sa=1, sb=1;
    for(i=n; i>=(n-k+1); i--)   sa *= i;
    for(i=k; i>=1; i--)         sb *= i;

    return sa/sb;
}