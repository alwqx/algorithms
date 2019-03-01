#include <stdio.h>
#include <stdlib.h>

// https://pintia.cn/problem-sets/14/problems/738

typedef struct Node *PtrToNode;
struct Node {
    int Data;
    PtrToNode Next;
};
typedef PtrToNode List;

int FactorialSum(List L);

int main() {
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for(i=0; i<N; i++) {
        p = (List) malloc(sizeof(List));
        scanf("%d", &p->Data);
        p->Next = L;
        L = p;
    }

    printf("%d\n", FactorialSum(L));
    return 0;
}

int FactorialSum(List L) {
    int i, sum = 0;

    List p = L;
    while(p) {
        int sub = 1;
        for(i=1; i<=p->Data; i++)
            sub *= i;
        sum += sub;
        p = p->Next;
    }

    return sum;
}