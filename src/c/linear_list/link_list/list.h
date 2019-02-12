#include <stdio.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

typedef struct LinkList {
    int size;
    struct LNode *first;
} LinkList;

LinkList *get_single_list();
int list_insert(LinkList *L, int e);
LNode *list_find_index(LinkList *L, int pos);
LNode *list_find_value(LinkList *L, int e);
int list_remove_index(LinkList *L, int pos);
int list_remove_value(LinkList *L, int e);
void list_display(LinkList *L);
int list_update(LinkList *L, int pos, int e);
int list_find_min(LinkList *L);
int list_find_max(LinkList *L);