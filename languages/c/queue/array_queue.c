#include <stdlib.h>

#include "queue.h"

ArrayQueue *get_array_queue() {
    ArrayQueue *s = (ArrayQueue *) malloc(sizeof(ArrayQueue));
    s->first = s->last = s->size = 0;
    s->cap = 2;
    s->array = (int *) malloc(sizeof(int) * s->cap);

    return s;
}

int array_queue_empty(ArrayQueue *s) {
    return s->size == 0;
}

void array_queue_resize(ArrayQueue *s, int cap) {
    if(cap <= s->size){
        printf("error, new cap should more than size of queue\n");
        exit(-1);
    }

    int *new_array = (int *) malloc(sizeof(int) * cap);
    int i;
    for(i=0; i<s->size; i++)
        new_array[i] = s->array[(s->first+i)%s->size];

    s->array = new_array;
    s->cap = cap;
    s->first = 0;
    s->last = s->size;
}

void array_queue_enqueue(ArrayQueue *s, int e) {
    if(s->size == s->cap)
        array_queue_resize(s, s->cap * 2);
    
    s->array[s->last++] = e;
    if(s->last == s->cap)
        s->last = 0;
    s->size++;
}

int array_queue_dequeue(ArrayQueue *s) {
    if(array_queue_empty(s)){
        printf("error, queue is empty\n");
        exit(-1);
    }

    int ret = s->array[s->first];
    s->array[s->first] = 0;
    s->size--;
    s->first++;

    if(s->first == s->cap)
        s->first = 0;
    
    if(s->size>0 && s->size == s->cap/4)
        array_queue_resize(s, s->cap/2);

    return ret;
}

int array_queue_peek(ArrayQueue *s) {
    if(array_queue_empty(s)) {
        printf("error, queue is empty\n");
        exit(-1);
    }

    return s->array[s->first];
}