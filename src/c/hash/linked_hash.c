#include <stdlib.h>
#include <stdio.h>

#include "hash.h"

LinkedHash *get_linked_hash_cap(int cap) {
    LinkedHash *h = (LinkedHash *) malloc(sizeof(LinkedHash));
    h->size = 0;
    h->cap = cap;
    h->st = (SequentialSearchST *) malloc(sizeof(SequentialSearchST) * cap);
    int i;
    for(i=0; i<cap; i++) {
        h->st[i] = get_sst();
    }

    return h;
}

LinkedHash *get_linked_hash() {
    return get_linked_hash_cap(LINKED_HASH_INIT_CAP);
}

int lhash_code(char *key, int len) {
    int sum = 0;
    int i = 0;
    while(key[i] != '\0') {
        sum += key[i];
        i++;
    }

    return sum % len;
}

int lh_size(LinkedHash *h) {
    return h->size;
}

int lh_empty(LinkedHash *h) {
    return h->size != 0;
}

void lh_resize(LinkedHash *h, int cap) {
    LinkedHash *nh = get_linked_hash_cap(cap);
    int i, j;
    STNode *x;
    for(i=0; i<h->cap; i++) {
        x = h->st[i]->first;
        for(j=0; j<h->st[i]->size; j++) {
            lh_put(nh, x->key, x->value);
            x = x->next;
        }
    }

    h->cap = nh->cap;
    h->st = nh->st;
    h->size = nh->size;
}

void lh_put(LinkedHash *h, char *key, int value) {
    if(key == NULL) {
        printf("key of lh_put() is null");
        exit(-1);
    }

    if(h->size >= 10*h->cap) lh_resize(h, 2*h->cap);
    int i = lhash_code(key, h->cap);
    if(!sst_contains(h->st[i], key)) h->size++;
    sst_put(h->st[i], key, value);
}

int lh_get(LinkedHash *h, char *key) {
    if(key == NULL) {
        printf("key of lh_get is null");
        exit(-1);
    }

    int i = lhash_code(key, h->cap);
    return sst_get(h->st[i], key);
}

void lh_delete(LinkedHash *h, char *key) {
    if(key == NULL) {
        printf("key of lh_delete is null");
        exit(-1);
    }

    int i = lhash_code(key, h->cap);
    if(sst_contains(h->st[i], key)) h->size--;
    sst_delete(h->st[i], key);

    // halve table size if average length of list <= 2
    if(h->size>LINKED_HASH_INIT_CAP && h->size<=2*h->cap)
        lh_resize(h, h->cap/2);
}

int lh_contains(LinkedHash *h, char *key) {
    if(key == NULL) {
        printf("key of lh_contains is null");
        exit(-1);
    }

    return lh_get(h, key) != NULL;
}

void lh_display(LinkedHash *h) {
    printf("size: %d, cap: %d, elements: ", h->size, h->cap);
    int i, j;
    STNode *x;
    for(i=0; i<h->cap; i++) {
        x = h->st[i]->first;
        for(j=0; j<h->st[i]->size; j++) {
            printf("[%s, %d] ", x->key, x->value);
            x = x->next;
        }
    }
    putchar('\n');
}