// https://pintia.cn/problem-sets/15/problems/728
#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find(List L, ElementType X);
List Insert(List L, ElementType X, Position P);
List Delete(List L, Position P);
void Print(List L);

int main() {
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }

    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }

    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    
    P = (Position) malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    
    return 0;
}

Position Find(List L, ElementType X) {
    while(L) {
        if(X == L->Data) return L;
        L = L->Next;
    }

    return ERROR;
}

List Insert(List L, ElementType X, Position P) {
    List head = L;
    List node = (List) malloc(sizeof(List));
    node->Data = X;
    node->Next = NULL;

    if(L == P) {
        node->Next = L;
        return node;
    }

    while(L) {
        if(L->Next == P) {
            List t = L->Next;
            L->Next = node;
            node->Next = t;
            return head;
        }
        L = L->Next;
    }
    
    printf("Wrong Position for Insertion\n");
    return ERROR;
}

List Delete(List L, Position P) {
    if(L == P) {
        L = L->Next;
        return L;
    }

    List head = L;
    while(L) {
        if(L->Next == P) {
            List t = L->Next;
            L->Next = t->Next;
            return head;
        }
        L = L->Next;
    }

    printf("Wrong Position for Deletion\n");
    return ERROR;
}

void Print(List L) {
    List t = L;
    while(t) {
        if(t->Next) printf("%d->", t->Data);
        else        printf("%d\n", t->Data);
        t = t->Next;
    }
}