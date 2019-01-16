#include <stdlib.h>
#include <stdio.h>

#include "array.h"

SqList * get_static_array() {
    SqList *sp = (SqList *) malloc(sizeof(SqList));
    sp->length = 0;
    for(int i=0; i<MAXSIZE; i++){
        sp->data[i] = -1;
    }
    
    return sp;
}

int array_insert(SqList *L, int pos, int e) {
    if(pos<0 || pos> L->length)
        return -1;

    for(int j=L->length;j>pos;j--)
        L->data[j] = L->data[j-1];

    L->data[pos] = e;
    L->length++;

    return 0;
}

int array_remove(SqList *L, int pos){
    if(pos<0 || pos>L->length)
        return -1;

    for(int j=pos; j<L->length; j++)
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
    int e = L->data[0];
    for(int i=0; i<L->length; i++)
        if(e>L->data[i])
            e = L->data[i];

    return e;
}

int array_max(SqList *L) {
    int e = L->data[0];
    for(int i=0; i<L->length; i++)
        if(e<L->data[i])
            e = L->data[i];

    return e;
}

void array_display(SqList *L){
    printf("%s", "static array:");
    for(int i=0; i<L->length; i++)
        printf(" %d", L->data[i]);
    printf("\n");
}