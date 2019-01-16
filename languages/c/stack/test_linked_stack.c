#include <stdlib.h>

#include "stack.h"

int test_linked_stack() {
    LinkedStack *s = get_linked_stack();
    
    // test push
    linked_stack_push(s, 0);
    linked_stack_push(s, 2);
    linked_stack_push(s, 4);
    linked_stack_push(s, 6); // [6, 4, 2, 0]
    if(s->size != 4){
        printf("push error, size should be 4, but get %d\n", s->size);
        exit(-1);
    }
    if(s->first->data != 6){
        printf("first data of stack should be 6, but get %d\n", s->first->data);
        exit(-1);
    }
    printf("stack push test success\n");

    // test pop
    int ret = linked_stack_pop(s);
    if(ret != 6){
        printf("stack pop error, ret should be 6, but get %d\n", ret);
        exit(-1);
    }
    if(s->size != 3){
        printf("stack pop error, stack size should be 3, but get %d\n", s->size);
        exit(-1);
    }
    printf("stack pop test success\n");

    // test peek
    ret = linked_stack_peek(s); // [4, 2, 0]
    if(ret != 4){
        printf("stack peek error, ret should be 4, but get %d\n", ret);
        exit(-1);
    }
    if(s->size != 3){
        printf("stack peek error, stack size should be 3, but get %d\n", s->size);
        exit(-1);
    }
    printf("stack peek test success\n");

    return 0;
}

int main() {
    return test_linked_stack();
}