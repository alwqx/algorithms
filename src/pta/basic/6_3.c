#include <stdio.h>
#define MAXN 10

// https://pintia.cn/problem-sets/14/problems/735

int Sum(int list[], int N);

int main() {
    int list[MAXN], N, i;

    scanf("%d", &N);
    for(i=0; i<N; i++)
        scanf("%d", &list[i]);

    printf("%d\n", Sum(list, N));
    return 0;
}

int Sum(int list[], int N) {
    int i, sum = 0;
    for(i=0; i<N; i++)
        sum += list[i];

    return sum;
}