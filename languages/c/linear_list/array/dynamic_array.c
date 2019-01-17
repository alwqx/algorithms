#include <stdlib.h>
#include <stdio.h>

#include "array.h"

DSqList * get_dynamic_array(int cap) {
    DSqList *sp = (DSqList *) malloc(sizeof(DSqList));
    sp->data = (int *) malloc(sizeof(int) * cap);
    sp->length = 0;
    sp->cap = cap;
    int i;
    for(i=0; i<MAXSIZE; i++){
        sp->data[i] = -1;
    }
    
    return sp;
}

int darray_insert(DSqList *L, int pos, int e) {
    if(pos<0 || pos> L->cap)
        return -1;
    int j;
    for(j=L->length;j>pos;j--)
        L->data[j] = L->data[j-1];

    L->data[pos] = e;
    L->length++;

    return 0;
}

int darray_remove(DSqList *L, int pos){
    if(pos<0 || pos>L->length)
        return -1;

    int j;
    for(j=pos; j<L->length; j++)
        L->data[j] = L->data[j+1];
    L->length--;

    return 0;    
}

int darray_update(DSqList *L, int pos, int e) {
    if(pos<0 || pos>L->length)
        return -1;

    L->data[pos] = e;
    return 0;
}

int darray_min(DSqList *L){
    int i, e = L->data[0];
    for(i=0; i<L->length; i++)
        if(e>L->data[i])
            e = L->data[i];

    return e;
}

int darray_max(DSqList *L) {
    int i, e = L->data[0];
    for(i=0; i<L->length; i++)
        if(e<L->data[i])
            e = L->data[i];

    return e;
}

void darray_display(DSqList *L){
    printf("%s", "static array:");
    int i;
    for(i=0; i<L->length; i++)
        printf(" %d", L->data[i]);
    printf("\n");
}