// https://pintia.cn/problem-sets/15/problems/731
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
int GetHeight(BinTree BT);

int main() {
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}

int GetHeight(BinTree BT) {
    if(BT == NULL) return 0;
    if(BT->Left==NULL) {
        if(BT->Right==NULL) return 1;
        return 1+GetHeight(BT->Right);
    }

    if(BT->Right==NULL) return 1+GetHeight(BT->Left);
    int l = GetHeight(BT->Left);
    int r = GetHeight(BT->Right);
    int h = l>r?l:r;
    return 1+h;
}