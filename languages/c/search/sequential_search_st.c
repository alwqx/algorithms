#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "st.h"

SequentialSearchST *get_sst() {
    SequentialSearchST *st = (SequentialSearchST *) malloc(sizeof(SequentialSearchST));
    st->size = 0;
    st->first = NULL;

    return st;
}

int sst_size(SequentialSearchST *st) {
    return st->size;
}

int sst_empty(SequentialSearchST *st) {
    return st->size == 0;
    // return st->first == NULL;
}

int sst_contains(SequentialSearchST *st, char *key) {
    return sst_get(st, key) != NULL;
}

int sst_get(SequentialSearchST *st, char *key) {
    if(key == NULL) {
        printf("key of sst_get() is null");
        exit(-1);
    }

    STNode *x;
    for(x=st->first; x!=NULL; x=x->next) {
        if(strcmp(x->key, key) == 0) {
            return x->value;
        }
    }

    return NULL;
}

STNode *sst_get_node(SequentialSearchST *st, char *key) {
    if(key == NULL) {
        printf("key of sst_get_node() is null");
        exit(-1);
    }

    STNode *x = st->first;
    for(; x!= NULL; x=x->next) {
        if(strcmp(key, x->key) == 0) {
            return x;
        }
    }

    return NULL;
}

void sst_put(SequentialSearchST *st, char *key, int value) {
    if(key == NULL) {
        printf("key to sst_put() is null");
        exit(-1);
    }
    if(value == NULL) {
        sst_delete(st, key);
        return;
    }

    STNode *x;
    for(x=st->first; x!=NULL; x=x->next) {
        if(strcmp(key, x->key) == 0) {
            x->value = value;
            return;
        }
    }

    STNode *tmp = (STNode *) malloc(sizeof(STNode));
    tmp->key = key;
    tmp->value = value;
    tmp->next = st->first;
    st->first = tmp;
    st->size++;
}

void sst_delete(SequentialSearchST *st, char *key) {
    if(key == NULL) {
        printf("key of sst_delete() is null");
        exit(-1);
    }

    int found = 1;
    STNode *pre = NULL, *cur = st->first;
    for(; cur!=NULL; pre=cur, cur=cur->next) {
        if(strcmp(key, cur->key) == 0){
            found=0;
            break;
        }
    }
    if(found == 1)
        return;

    // contains key, begin delete
    if(pre == NULL) {
        st->first = st->first->next;
        // cur = cur->next;
        st->size--;
        return;
    }

    pre->next = cur->next;
    st->size--;
}

void sst_display(SequentialSearchST *st) {
    STNode *x = st->first;
    int i;
    for(i=0; i<st->size; i++) {
        printf("[%s, %d]->", x->key, x->value);
        x = x->next;
    }
    printf("NULL\n");
}