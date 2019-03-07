// https://pintia.cn/problem-sets/15/problems/729
#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL

typedef enum {false, true} bool;
typedef int ElementType;

typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

void Print(List L) {
    List t = L->Next;
    while(t) {
        if(t->Next) printf("%d->", t->Data);
        else        printf("%d\n", t->Data);
        t = t->Next;
    }
}

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if ( flag==false ) printf("Wrong Answer\n");
    }
    Print(L);

    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( flag==false )
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if ( flag==false ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if ( flag==true ) printf("Wrong Answer\n");
    flag = Delete(L, P);
    if ( flag==true ) printf("Wrong Answer\n");
    for ( P=L->Next; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

List MakeEmpty() {
    List L = (List) malloc(sizeof(List));
    L->Data = 0;
    L->Next = NULL;

    return L;
}

Position Find(List L, ElementType X) {
    List t = L->Next;
    while(t) {
        if(t->Data == X) return t;
        t = t->Next;
    }

    return ERROR;
}

bool Insert(List L, ElementType X, Position P) {
    List t = L;
    List node = (List) malloc(sizeof(List));
    node->Data = X;
    node->Next = P;

    while(t) {
        if(t->Next == P) {
            t->Next = node;
            return true;
        }
        t = t->Next;
    }

    printf("Wrong Position for Insertion\n");
    return false;
}

bool Delete(List L, Position P) {
    List t = L;

    while(t) {
        if(t->Next == P) {
            t->Next = P->Next;
            return true;
        }
        t = t->Next;
    }

    printf("Wrong Position for Deletion\n");
    return false;
}