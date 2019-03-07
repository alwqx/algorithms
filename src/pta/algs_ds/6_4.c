// https://pintia.cn/problem-sets/15/problems/727

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read();
ElementType FindKth(List L, int K);

int main() {
    int N, K;
    ElementType X;
    List L = Read();

    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }

    return 0;
}

List Read() {
    List L=NULL, tail=NULL;
    int i, n, N;
    scanf("%d", &N);
    for(i=0; i<N; i++) {
        scanf("%d", &n);
        if(L==NULL) { // first input
            L = (List) malloc(sizeof(List));
            L->Data = n;
            L->Next = NULL;
            tail = L;
        } else {
            List node = (List) malloc(sizeof(List));
            node->Data = n;
            node->Next = NULL;
            tail->Next = node;
            tail = tail->Next;
        }
    }

    return L;
}

ElementType FindKth(List L, int K) {
    int i=0;
    List pre=NULL, t = L;

    while(i<K && t!=NULL) {
        i++;
        pre = t;
        t = t->Next;
    }
    if(pre != NULL && i==K) return pre->Data;
    else          return ERROR;
}