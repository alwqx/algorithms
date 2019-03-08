// https://pintia.cn/problem-sets/15/problems/732
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
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);
void LevelorderTraversal(BinTree BT);

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}

//前序创建二叉树
BinTree CreatBinTree() {
    char c;
    BinTree t;
    scanf("%c", &c);
    if(c==' ')			//如果输入的为空格，将该结点置为空
        return NULL;
    else{              //否则将字符c赋值给该节点，并递归创建该节点的左孩子，右孩子
        t = (BinTree) malloc(sizeof(struct TNode));
        t->Data=c;
        t->Left=CreatBinTree();
        t->Right=CreatBinTree();
    }

    return t;
}

void InorderTraversal(BinTree BT) {
    if(BT == NULL) return;
    InorderTraversal(BT->Left);
    printf(" %c", BT->Data);
    InorderTraversal(BT->Right);
}

void PreorderTraversal(BinTree BT) {
    if(BT == NULL) return;
    printf(" %c", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}

void PostorderTraversal(BinTree BT) {
    if(BT == NULL) return;
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf(" %c", BT->Data);
}

void LevelorderTraversal(BinTree BT) {
    BinTree q[100];
    BinTree t;
    int base=0, head=0;

    if(BT) {
        q[head++] = BT;
        while(base!=head) {
            t = q[base++];
            printf(" %c", t->Data);
            if(t->Left) q[head++] = t->Left;
            if(t->Right) q[head++] = t->Right;
        }
    }
}