// https://pintia.cn/problem-sets/15/problems/726
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read();
int Length(List L);

int main() {
    List L = Read();
    printf("%d\n", Length(L));
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

int Length( List L ) {
    int i = 0;
    List t = L;
    while(t) {
        i++;
        t = t->Next;
    }

    return i;
}