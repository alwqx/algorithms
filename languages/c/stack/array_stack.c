#include <stdlib.h>

#include "stack.h"

ArrayStack *get_array_stack() {
    ArrayStack * s = (ArrayStack *) malloc(sizeof(ArrayStack));
    s->size = 0;
    s->cap = 2;
    s->array = (int *) malloc(sizeof(int)*s->cap);

    return s;
}

int array_stack_empty(ArrayStack *s) {
    return s->size == 0;
}

void array_stack_resize(ArrayStack *s, int cap) {
    if(cap <= s->size) {
        printf("error, new cap should more than size of stack\n");
        exit(-1);
    }
    int * new_array = (int *) malloc(sizeof(int) * cap);
    for(int i=0; i<s->size; i++)
        new_array[i] = s->array[i];

    s->array = new_array;
    s->cap = cap;
}

void array_stack_push(ArrayStack *s, int e) {
    if(s->size == s->cap){
        array_stack_resize(s, s->cap*2);
    }
    s->array[s->size++] = e;
}

int array_stack_pop(ArrayStack *s) {
    if(array_stack_empty(s)){
        printf("stack underflow");
        exit(-1);
    }

    int ret = s->array[s->size-1];
    s->array[s->size-1] = -1;
    s->size--;

    if(s->size>0 && s->size < s->cap/4)
        array_stack_resize(s, s->cap/2);

    return ret;
}

int array_stack_peek(ArrayStack *s) {
    if(array_stack_empty(s)){
        printf("stack underflow");
        exit(-1);
    }

    return s->array[s->size-1];
}