#include <stdlib.h>
#include <stdio.h>

#include "st.h"

BinarySearchST *get_bst() {
    BinarySearchST *bst;
    bst = (BinarySearchST *) malloc(sizeof(BinarySearchST));
    bst->cap = 2;
    bst->size = 0;
    bst->keys = (char **) malloc(sizeof(char *)*2);
    bst->values = (int *) malloc(sizeof(int)*2);

    return bst;
}

int bst_size(BinarySearchST *bst) {
    return bst->size;
}

int bst_empty(BinarySearchST *bst) {
    return bst->size == 0;
}

void bst_resize(BinarySearchST *bst, int cap) {
    if(cap <= bst->size) {
        printf("cap should more than size");
        exit(-1);
    }

    int i;
    char **tmpk = (char **) malloc(sizeof(char *)*cap);
    int *tmpv = (int *) malloc(sizeof(int)*cap);
    for(i=0; i<bst->size; i++) {
        tmpk[i] = bst->keys[i];
        tmpv[i] = bst->values[i];
    }
    bst->keys = tmpk;
    bst->values = tmpv;
    bst->cap = cap;
}

void bst_display(BinarySearchST *bst) {
    if(bst_empty(bst)){
        printf("empty symbal table\n");
        return;
    }

    int i;
    for(i=0; i<(bst->size-1); i++)
        printf("[%s, %d]-", bst->keys[i], bst->values[i]);

    printf("[%s, %d]\n", bst->keys[i], bst->values[i]);
}

int bst_rank(BinarySearchST *bst, char *key) {
    if(key == NULL) {
        printf("key of bst_rank() is null");
        exit(-1);
    }

    int mid, low=0, high=bst->size-1;
    while(low<=high) {
        mid=(low+high)/2;
        int cmp = strcmp(key, bst->keys[mid]);
        if(cmp<0) high=mid-1;
        else if(cmp>0) low=mid+1;
        else return mid;
    }

    return low;
}

int bst_get(BinarySearchST *bst, char *key) {
    if(key == NULL) {
        printf("key of bst_get() is null");
        exit(-1);
    }

    if(bst_empty(bst)) return NULL;
    int i = bst_rank(bst, key);
    if(i<bst->size && strcmp(key, bst->keys[i]) == 0)
        return bst->values[i];

    return NULL;
}

int bst_contains(BinarySearchST *bst, char *key) {
    if(key == NULL) {
        printf("key of bst_contains() is null");
        exit(-1);
    }

    return bst_get(bst, key) != NULL;
}

void bst_put(BinarySearchST *bst, char *key, int value) {
    if(key == NULL) {
        printf("key of bst_put() is null");
        exit(-1);
    }

    if(value == NULL) {
        bst_delete(bst, key);
        return;
    }

    int i = bst_rank(bst, key);
    if(i<bst->size && strcmp(key, bst->keys[i]) == 0) {
        bst->values[i] = value;
        return;
    }

    // insert new k-v pair
    if(bst->size == bst->cap) bst_resize(bst, bst->size*2);
    int j;
    for(j=bst->size; j>i; j--) {
        bst->keys[j] = bst->keys[j-1];
        bst->values[j] = bst->values[j-1];
    }
    bst->keys[i] = key;
    bst->values[i] = value;
    bst->size++;
}

void bst_delete(BinarySearchST *bst, char *key) {
    if(key == NULL) {
        printf("key of bst_delete() is null");
        exit(-1);
    }
    if(bst_empty(bst)) return;

    int i = bst_rank(bst, key);

    // key not in table
    if(i==bst->size || strcmp(key, bst->keys[i]) != 0) return;
    int j;
    for(j=i; j<bst->size-1; j++) {
        bst->keys[j] = bst->keys[j+1];
        bst->values[j] = bst->values[j+1];
    }
    bst->size--;

    bst->keys[bst->size] = NULL;
    bst->values[bst->size] = NULL;

    if(bst->size>0 && bst->size == bst->cap/4)
        bst_resize(bst, bst->cap/2);
}