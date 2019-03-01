#include <stdio.h>
#define MAXN 10

// https://pintia.cn/problem-sets/14/problems/736

typedef float ElementType;
ElementType Average(ElementType S[], int N);

int main() {
    ElementType S[MAXN];
    int N, i;
    scanf("%d", &N);
    for(i=0; i<N; i++)
        scanf("%f", &S[i]);
    
    printf("%.2f\n", Average(S, N));
    return 0;
}

ElementType Average(ElementType S[], int N) {
    ElementType sum = 0;
    int i;

    for(i=0; i<N; i++)
        sum += S[i];

    return sum/N;
}