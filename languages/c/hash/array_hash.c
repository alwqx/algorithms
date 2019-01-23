#include <stdlib.h>
#include <stdio.h>

#include "hash.h"

ArrayHash *get_lph() {
    return get_lph_cap(2);
}

ArrayHash *get_lph_cap(int cap) {
    ArrayHash *h = (ArrayHash *) malloc(sizeof(ArrayHash));
    h->cap = cap;
    h->size = 0;
    h->values = (int *) malloc(sizeof(int)*h->cap);
    h->keys = (char **) malloc(sizeof(char *)*h->cap);

    return h;
}

int hash_code(char *key, int len) {
    int sum = 0;
    int i = 0;
    while(key[i] != '\0') {
        sum += key[i];
        i++;
    }

    return sum % len;
}

void lph_resize(ArrayHash *h, int cap) {
    if(cap<=h->size) {
        printf("cap should be more than size");
        exit(-1);
    }

    ArrayHash *nh = get_lph_cap(cap);
    int i;
    for(i=0; i<h->cap; i++) {
        if(h->keys[i] != NULL) {
            lph_put(nh, h->keys[i], h->values[i]);
        }
    }

    h->keys = nh->keys;
    h->values = nh->values;
    h->cap = cap;
}

int lph_size(ArrayHash *h) {
    return h->size;
}

int lph_empty(ArrayHash *h) {
    return h->size != 0;
}

int lph_contains(ArrayHash *h, char *key) {
    if(key == NULL) {
        printf("key of lph_contains is null");
        exit(-1);
    }

    return lph_get(h, key) != NULL;
}

void lph_put(ArrayHash *h, char *key, int value) {
    if(key == NULL) {
        printf("key of lph_put is null");
        return;
    }
    // if(value == NULL) {
    //     lph_delete(h, key);
    //     return;
    // }

    // double table size if 50% full
    if(h->size >= h->cap/2) lph_resize(h, h->cap*2);

    int i;
    for(i=hash_code(key, h->cap); h->keys[i] != NULL; i=(i+1)%h->cap) {
        if(strcmp(h->keys[i], key) == 0) {
            h->values[i] = value;
            return;
        }
    }

    h->keys[i] = key;
    h->values[i] = value;
    h->size++;
}

int lph_get(ArrayHash *h, char *key) {
    if(key == NULL) {
        printf("key of lph_get is null");
        return;
    }
    
    int i;
    for(i=hash_code(key, h->cap); h->keys[i] != NULL; i=(i+1)%h->cap) {
        if(strcmp(h->keys[i], key) == 0)
            return h->values[i];
    }

    return NULL;
}

void lph_delete(ArrayHash *h, char *key) {
    if(key == NULL) {
        printf("key of lph_delete is null");
        return;
    }

    if(!lph_contains(h, key)) return;

    int i = hash_code(key, h->cap);
    while(strcmp(h->keys[i], key) != 0)
        i = (i+1)%h->cap;
    h->keys[i] = NULL;
    h->values[i] = NULL;

    // refresh all keys in same cluster
    i = (i+1)%h->cap;
    while(h->keys[i] != NULL) {
        char *tmpk = h->keys[i];
        int tmpv = h->values[i];
        h->keys[i] = NULL;
        h->values[i] = NULL;
        h->size--;
        lph_put(h, tmpk, tmpv);
        i = (i+1)%h->cap;
    }
    h->size--;

    if(h->size>0 && h->size<=(h->cap/8)) lph_resize(h, h->cap/2);
}

void check(ArrayHash *h) {
    if(h->cap < h->size*2) {
        printf("Hash table size cap=%d, array size=%d", h->cap, h->size);
        exit(-1);
    }

    int i;
    for(i=0; i<h->cap; i++) {
        if(h->keys[i] == NULL) continue;
        else if(lph_get(h, h->keys[i]) != h->values[i]) {
            printf("get[%s]=%s, value=%d", h->keys[i], h->values[i]);
            exit(-1);
        }
    }
}

void lph_display(ArrayHash *h) {
    int i;
    printf("size: %d, cap: %d, elements: ", h->size, h->cap);
    for(i=0; i<h->cap; i++) {
        if(h->keys[i] != NULL)
            printf("[%s, %d] ", h->keys[i], h->values[i]);
    }
}