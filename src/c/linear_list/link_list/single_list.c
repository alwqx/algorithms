#include <stdlib.h>

#include "list.h"

LinkList *get_single_list() {
    LinkList *L = (LinkList *) malloc(sizeof(LinkList));
    L->first = NULL;
    L->size = 0;

    return L;
}

int list_insert(LinkList *L, int e) {
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = L->first;
    L->first = s;
    L->size++;

    return 0;
}

// list_find_index 0<= pos <= L->data-1
LNode *list_find_index(LinkList *L, int pos) {
    if(pos<0 || pos>L->size)
        return NULL;
        
    LNode *s = L->first;
    int i;
    for(i=0;i<pos;i++)
        s = s->next;
    
    return s;
}

LNode *list_find_value(LinkList *L, int e) {
    LNode *s = L->first;
    while(s){
        if(s->data == e)
            break;
        s=s->next;
    }

    return s;
}

// list_remove_index 0<= pos <= L->data-1
int list_remove_index(LinkList *L, int pos) {
    if(pos<0 || pos>L->size)
        return -1;

    int ret;
    if(pos == 0) {
        LNode *s = L->first;
        L->first = L->first->next;
        ret = s->data;
        free(s);
        L->size--;
        return ret;
    }

    LNode *pre = list_find_index(L, pos-1);
    LNode *cur = list_find_index(L, pos);
    ret = cur->data;
    pre->next = cur->next;
    free(cur);
    L->size--;
    
    return ret;
}

int list_remove_value(LinkList *L, int e) {
    LNode *s = L->first;
    int ret = -1;

    while(s){
        if(s->data == e){
            ret = e;
            s->data = s->next->data;
            s->next = s->next->next;
            L->size--;
            break;
        }
        s = s->next;
    }

    return ret;
}

void list_display(LinkList *L) {
    printf("%s", "list is:");
    LNode *cur = L->first;
    int i;
    for(i=0; i<L->size; i++){
        printf(" %d", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int list_update(LinkList *L, int pos, int e) {
    if(pos<0 || pos>L->size)
        return -1;

    LNode *s = L->first;
    int i;
    for(i=0; i<pos; i++)
        s = s->next;
    s->data = e;

    return 0;
}

int list_find_min(LinkList *L) {
    LNode *s = L->first;
    int min = L->first->data;

    while(s){
        if(min>s->data)
            min=s->data;
        s=s->next;
    }

    return min;
}

int list_find_max(LinkList *L) {
    LNode *s = L->first;
    int max = L->first->data;

    while(s){
        if(max<s->data)
            max=s->data;
        s=s->next;
    }

    return max;
}