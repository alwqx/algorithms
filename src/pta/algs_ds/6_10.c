// https://pintia.cn/problem-sets/15/problems/923
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0

typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last;
};

List ReadInput();
Position BinarySearch(List L, ElementType X);

int main() {
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("index of %d is %d\n", X, P);

    return 0;
}

List ReadInput() {
    List L = (List) malloc(sizeof(struct LNode));
    L->Last = 0;
    int i, N, d;
    scanf("%d", &N);
    for(i=0; i<N; i++) {
        scanf("%d", &d);
        L->Last++;
        L->Data[L->Last] = d;
    }

    return L;
}

Position BinarySearch(List L, ElementType X) {
    Position mid, low=1, high=L->Last;
    while(low<=high) {
        mid = (low+high)/2;
        if(L->Data[mid]<X)      low=mid+1;
        else if(L->Data[mid]>X) high=mid-1;
        else                    return mid;
    }

    return NotFound;
}