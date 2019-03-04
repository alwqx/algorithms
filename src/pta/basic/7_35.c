// https://pintia.cn/problem-sets/14/problems/815
#include <stdio.h>
#include <stdlib.h>

int find(int, int);

int main() {
    int i, tmp, N, *a, *b, c[2];
    scanf("%d", &N);
    a = (int *) malloc(sizeof(int)*N);
    b = (int *) malloc(sizeof(int)*N);
    for(i=0; i<N; i++)
        scanf("%d/%d", &a[i], &b[i]);

    // process add
    c[0] = 0; c[1] = 1;
    for(i=0; i<N; i++) {
        c[0] = c[0]*b[i]+a[i]*c[1];
        c[1] *= b[i];
        tmp = find(c[0], c[1]);
        c[0] /= tmp;
        c[1] /= tmp;
    }

    // if(c[0]*c[1]<0) putchar('-');
    c[1] *= N;
    tmp = find(c[0], c[1]);
    c[0] /= tmp;
    c[1] /= tmp;

    if(c[0]%c[1] == 0) {
        if(c[1] == 1)   printf("%d", c[0]);
        else            printf("%d", c[0]/c[1]);
    } else              printf("%d/%d", c[0], c[1]);
    return 0;
}

int find(int a, int b) {
    int c = b;
    while(a%b != 0) {
        c = a%b;
        a = b;
        b = c;
    }

    return c<0?-c:c;
}