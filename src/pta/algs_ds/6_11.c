// https://pintia.cn/problem-sets/15/problems/925
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree();
void PreorderPrintLeaves(BinTree BT);

int main() {
    BinTree BT = CreatBinTree();
    printf("Leaf nodes are:");
    PreorderPrintLeaves(BT);
    printf("\n");

    return 0;
}

void PreorderPrintLeaves(BinTree BT) {
    if(BT == NULL) return;
    PreorderPrintLeaves(BT->Left);
    if(BT->Left==NULL && BT->Right==NULL)
        printf(" %c", BT->Data);
    PreorderPrintLeaves(BT->Right);
}