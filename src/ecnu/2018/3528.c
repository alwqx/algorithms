// https://eoj.i64d.com/problem/3528/
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int i, j, t, max=-1, sum=0;
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            scanf("%d", &t);
            if(max<t) max=t;
        }
        sum += max;
        max=-1;
    }

    printf("%d\n", sum);

    return 0;
}