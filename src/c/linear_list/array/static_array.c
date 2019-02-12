#include <stdlib.h>
#include <stdio.h>

#include "array.h"

SqList * get_static_array() {
    SqList *sp = (SqList *) malloc(sizeof(SqList));
    sp->length = 0;
    int i;
    for(i=0; i<MAXSIZE; i++){
        sp->data[i] = -1;
    }
    
    return sp;
}

int array_insert(SqList *L, int pos, int e) {
    if(pos<0 || pos> L->length)
        return -1;

    int j;
    for(j=L->length;j>pos;j--)
        L->data[j] = L->data[j-1];

    L->data[pos] = e;
    L->length++;

    return 0;
}

int array_remove(SqList *L, int pos){
    if(pos<0 || pos>L->length)
        return -1;

    int j;
    for(j=pos; j<L->length; j++)
        L->data[j] = L->data[j+1];
    L->length--;

    return 0;    
}

int array_update(SqList *L, int pos, int e) {
    if(pos<0 || pos>L->length)
        return -1;

    L->data[pos] = e;
    return 0;
}

int array_min(SqList *L){
    int i, e = L->data[0];
    for(i=0; i<L->length; i++)
        if(e>L->data[i])
            e = L->data[i];

    return e;
}

int array_max(SqList *L) {
    int i, e = L->data[0];
    for(i=0; i<L->length; i++)
        if(e<L->data[i])
            e = L->data[i];

    return e;
}

void array_display(SqList *L){
    printf("%s", "static array:");
    int i;
    for(i=0; i<L->length; i++)
        printf(" %d", L->data[i]);
    printf("\n");
}