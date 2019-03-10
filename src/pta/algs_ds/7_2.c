// https://pintia.cn/problem-sets/15/problems/710
#include <stdio.h>
#include <stdlib.h>

void process_multi();
void process_add(int *a[], int *b[], int A, int B);

int main() {
    int i, A, B;
    scanf("%d", &A);
    int *a[2];
    a[0] = (int *) malloc(sizeof(int)*A);
    a[1] = (int *) malloc(sizeof(int)*A);
    for(i=0; i<A; i++)
        scanf("%d %d", &a[0][i], &a[1][i]);

    scanf("%d", B);
    int *b[2];
    b[0] = (int *) malloc(sizeof(int)*A);
    b[1] = (int *) malloc(sizeof(int)*A);
    for(i=0; i<B; i++)
        scanf("%d %d", &b[0][i], &b[1][i]);

    process_multi();
    process_add(a, b, A, B);

    return 0;
}

void process_add(int *a[], int *b[], int A, int B) {
    int *s[2], N=A+B;
    s[0] = (int *) malloc(sizeof(int)*N);
    s[1] = (int *) malloc(sizeof(int)*N);

    int i, MAX=A>B?A:B, j=0;
    for(i=0; i<MAX; i++) {

    }
}