#include <stdlib.h>

#include "stack.h"

LinkedStack *get_linked_stack(){
    LinkedStack *ls = (LinkedStack *) malloc(sizeof(LinkedStack));
    ls->first = NULL;
    ls->size = 0;

    return ls;
}

int linked_stack_empty(LinkedStack *s) {
    return s->size == 0;
    // return s->first == NULL;
}

void linked_stack_push(LinkedStack *s, int e) {
    //类似链表的前插入操作
    StackNode *ss = (StackNode *) malloc(sizeof(StackNode));
    ss->data = e;
    ss->next = s->first;
    s->first = ss;
    s->size++;
}

int linked_stack_pop(LinkedStack *s) {
    if(linked_stack_empty(s))
        return -1;
    
    int ret = s->first->data;
    StackNode *tmp = s->first;
    s->first = s->first->next;
    s->size--;
    free(tmp);

    return ret;
}

int linked_stack_peek(LinkedStack *s) {
    if(linked_stack_empty(s))
        return -1;

    return s->first->data;
}