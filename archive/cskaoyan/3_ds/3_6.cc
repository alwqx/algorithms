/*
王道考研机试指南 p70
*/
#include <stdio.h>
#include <string.h>

struct Node {
    int x;
    Node *l;
    Node *r;
} Tree[110];

char pres[25], ins[25];
int size1, size2;
char *str;
int *size;

void preOrder(Node *t) {
    if(!t) return;
    // printf("%d ", t->x);
    str[(*size)++] = t->x+'0';
    preOrder(t->l);
    preOrder(t->r);
}

void inOrder(Node *t) {
    if(!t) return;
    inOrder(t->l);
    // printf("%d ", t->x);
    str[(*size)++] = t->x+'0';
    inOrder(t->r);
}

int loc;
Node *create() {
    Tree[loc].l = Tree[loc].r = NULL;
    return &Tree[loc++];
}

Node *insert(Node *t, int c) {
    if(!t) {
        t = create();
        t->x = c;
        return t;
    } else if (c<t->x) t->l = insert(t->l, c);
    else if (c>t->x) t->r = insert(t->r, c);

    return t;
}

int main() {
    int i, j, n;
    char tmp[12];
    while(scanf("%d", &n)!=EOF && n!=0) {
        loc = 0;
        Node *t = NULL;
        scanf("%s", tmp);
        for(i=0; tmp[i]; i++)
            t = insert(t, tmp[i]-'0');
        
        size1 = 0;
        str = pres;
        size = &size1;

        preOrder(t);
        inOrder(t);
        pres[size1] = '\0';

        // input another n string
        for(i=0; i<n; i++) {
            scanf("%s", tmp);
            Node *t2 = NULL;

            for(j=0; tmp[j]; j++)
                t2 = insert(t2, tmp[j]-'0');

            size2 = 0;
            str = ins;
            size = &size2;

            preOrder(t2);
            inOrder(t2);
            ins[size2] = '\0';
            // printf("pres is: %s\n", pres);
            // printf("ins  is: %s\n", ins);
            printf("%s\n", strcmp(pres, ins)==0?"YES":"NO");
        }
    }

    return 0;
}