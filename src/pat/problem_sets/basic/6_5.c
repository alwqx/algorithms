#include <stdio.h>
#define MAXN 10

// https://pintia.cn/problem-sets/14/problems/737

typedef float ElementType;

ElementType Max(ElementType S[], int N);

int main ()
{
    ElementType S[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &S[i]);
    printf("%.2f\n", Max(S, N));

    return 0;
}

ElementType Max(ElementType S[], int N) {
    ElementType max = S[0];
    int i;
    for(i=0; i<N; i++)
        if(max<S[i])
            max = S[i];

    return max;
}