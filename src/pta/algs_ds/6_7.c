// https://pintia.cn/problem-sets/15/problems/730
#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;

typedef enum {push, pop, end} Operation;
typedef enum {false, true} bool;
typedef int Position;

struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack(int MaxSize);
bool Push(Stack S, ElementType X, int Tag);
ElementType Pop(Stack S, int Tag);

Operation GetOp();  /* details omitted */
void PrintStack(Stack S, int Tag); /* details omitted */

int main() {
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while(!done) {
        Operation op = GetOp();
        // printf("op is %d\n", op);
        switch(op) {
        case push:
            scanf("%d %d", &Tag, &X);
            if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
            break;
        case pop:
            scanf("%d", &Tag);
            X = Pop(S, Tag);
            if (X==ERROR) printf("Stack %d is Empty!\n", Tag);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }

    return 0;
}

Stack CreateStack(int MaxSize) {
    Stack s = (Stack) malloc(sizeof(struct SNode));
    s->Data = (ElementType *) malloc(sizeof(ElementType)*MaxSize);
    s->MaxSize = MaxSize;
    s->Top1 = -1;
    s->Top2 = MaxSize;

    return s;
}

bool Push(Stack S, ElementType X, int Tag) {
    if((S->Top2 - S->Top1) == 1) {
        printf("Stack Full\n");
        return false;
    }

    if(Tag == 1) {
        S->Top1++;
        S->Data[S->Top1] = X;
        return true;
    }

    S->Top2--;
    S->Data[S->Top2] = X;
    return true;
}

ElementType Pop(Stack S, int Tag) {
    ElementType x;
    if(Tag == 1) {
        if(S->Top1 == -1) {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
        x = S->Data[S->Top1];
        S->Top1--;
        return x;
    }

    if(S->Top2 == S->MaxSize) {
        printf("Stack %d Empty\n", Tag);
        return ERROR;
    }
    x = S->Data[S->Top2];
    S->Top2++;
    return x;
}

Operation GetOp() {
    int i = rand();
    printf("[GetOp]: i is %d, op is %d\n", i, i%3);
    return i%3;
}

void PrintStack(Stack S, int Tag) {
    int i;
    if(Tag == 1)
        for(i=S->Top1; i>=0; i--) {
            if(i!=0) printf("%d ", S->Data[i]);
            else     printf("%d\n", S->Data[i]);
        }
    else
        for(i=S->Top2; i<=S->MaxSize; i++) {
            if(i!=S->MaxSize)   printf("%d ", S->Data[i]);
            else                printf("%d\n", S->Data[i]);
        }
}
