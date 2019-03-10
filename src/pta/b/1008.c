// https://pintia.cn/problem-sets/994805260223102976/problems/994805316250615808
#include <stdio.h>
#include <stdlib.h>

void Print(int *a, int N) {
    int i;
    for(i=0; i<N; i++)
        if(i==N-1)  printf("%d\n", a[i]);
        else        printf("%d ", a[i]);
}

int main() {
    int i, N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    int *a = (int *) malloc(sizeof(int)*N);
    for(i=0; i<N; i++)
        scanf("%d", &a[i]);

    // format M (M>N)
    M = M%N;
    int j, tmp;
    while(M--) {
        tmp = a[N-1];
        for(i=N-1; i>=1; i--)
            a[i] = a[i-1];
        a[0] = tmp;
    }

    for(i=0; i<N; i++)
        if(i==N-1)  printf("%d\n", a[i]);
        else        printf("%d ", a[i]);

    return 0;
}