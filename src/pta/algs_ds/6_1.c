// https://pintia.cn/problem-sets/15/problems/724
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();
void Print(List L);
List Reverse(List L);
List Reverse1(List L);
List Reverse2(List L);

int main() {
    List L1, L2;
    L1 = Read();
    Print(L1);
    // L2 = Reverse(L1);
    // L2 = Reverse1(L1);
    L2 = Reverse2(L1);
    Print(L2);
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

void Print(List L) {
    printf("L[%p]: ", L);
    List t = L;
    while(t) {
        if(t->Next != NULL) {
            printf("%d->", t->Data);
        } else
            printf("%d\n", t->Data);
        t = t->Next;
    }
}

List Reverse(List L) {
    if(L==NULL || L->Next==NULL) return L;

    List pcur, tail;
    pcur = L->Next;
    L->Next = NULL;

    while(pcur) {
        tail = pcur->Next;
        pcur->Next = L;
        L = pcur;
        pcur = tail;
    }

    return L;
}

List Reverse1(List L) {
    if(L==NULL || L->Next==NULL) return L;
    List newL=NULL, t=L;
    while(t) {
        if(newL == NULL) { // first node
            newL = (List) malloc(sizeof(List));
            newL->Data = t->Data;
            newL->Next = NULL;
        } else {
            List node = (List) malloc(sizeof(List));
            node->Data = t->Data;
            node->Next = newL;
            newL = node;
        }
        t = t->Next;
    }

    return newL;
}

// Reverse2 recurion implement!
List Reverse2(List L) {
    if(L==NULL || L->Next==NULL) return L;
    List tail = Reverse2(L->Next); // get tail node
    L->Next->Next = L;
    L->Next = NULL;

    return tail;
}