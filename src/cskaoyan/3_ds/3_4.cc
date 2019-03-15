/*
王道考研机试指南 p64
*/
#include <stdio.h>
#include <string.h>

#define MAXN 50

struct Node {
    char c;
    Node *l;
    Node *r;
} Tree[MAXN];

int loc;

Node *create() {
    Tree[loc].l = Tree[loc].r = NULL;
    return &Tree[loc++];
}

// store preorder and inorder result
char pres[30], ins[30];

void postOrder(Node *t) {
    if(t->l != NULL) postOrder(t->l);
    if(t->r != NULL) postOrder(t->r);
    printf("%c", t->c);
}

// build tree by preorder and inorder sequence
Node *build(int s1, int e1, int s2, int e2) {
    Node *ret = create();
    ret->c = pres[s1];

    int i, rindex;
    // 在中序遍历中寻找根节点
    for(i=s2; i<=e2; i++)
        if(pres[s1] == ins[i]) {
            rindex = i;
            break;
        }
    // left subtree is not empty
    if(rindex != s2)
        ret->l = build(s1+1, s1+rindex-s2, s2, rindex-1);
    // right subtree is not empty
    if(rindex != e2)
        ret->r = build(s1+rindex-s2+1, e1, rindex+1, e2);
    
    return ret;
}

int main() {
    int i, n;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%s", pres);
        scanf("%s", ins);
        loc = 0;
        int len = strlen(pres);
        Node *t = build(0, len-1, 0, len-1);

        postOrder(t);
        putchar('\n');
    }

    return 0;
 }