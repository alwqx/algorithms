/*
王道考研机试指南 p67

建立二叉排序树并输出3种遍历
*/
#include <stdio.h>
#include <string.h>

struct Node {
    int c;
    Node *l;
    Node *r;
} Tree[110];

int loc;
Node *create() {
    Tree[loc].r = Tree[loc].l = NULL;
    return &Tree[loc++];
}

void preOrder(Node *t) {
    if(t == NULL) return;
    printf("%d ", t->c);
    preOrder(t->l);
    preOrder(t->r);
}

void inOrder(Node *t) {
    if(t == NULL) return;
    inOrder(t->l);
    printf("%d ", t->c);
    inOrder(t->r);
}

void postOrder(Node *t) {
    if(t == NULL) return;
    postOrder(t->l);
    postOrder(t->r);
    printf("%d ", t->c);
}

Node *insert(Node *t, int x) {
    if(t == NULL) {
        t = create();
        t->c = x;
        return t;
    } else if(x<t->c)
        t->l = insert(t->l, x);
    else if(x>t->c)
        t->r = insert(t->r, x);
    
    return t;
}

int main() {
    int i, m, n;
    while(scanf("%d", &n) != EOF) {
        loc = 0;
        Node *t = NULL;
        for(i=0; i<n; i++) {
            scanf("%d", &m);
            t = insert(t, m);
        }

        // output
        preOrder(t);
        putchar('\n');
        inOrder(t);
        putchar('\n');
        postOrder(t);
        putchar('\n');
    }

    return 0;
}