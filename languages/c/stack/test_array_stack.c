#include <stdlib.h>

#include "stack.h"

int test_array_stack() {
    ArrayStack *s = get_array_stack();

    // test push
    array_stack_push(s, 0); // [0], size=1, cap=2
    array_stack_push(s, 3); // [0, 3], size=2, cap=2
    if(s->size != 2){
        printf("stack push error, stack size should be 2, but get %d\n", s->size);
        exit(-1);
    }
    if(s->array[1] != 3) {
        printf("stack push error, last element of stack should be 3, but get %d\n", s->array[1]);
        exit(-1);
    }
    printf("stack push success\n");

    // test resize
    array_stack_push(s, 5); // [0, 3, 5], size=3, cap=4
    if(s->cap != 4) {
        printf("stack resize error, cap should be 4, but get %d\n", s->cap);
        exit(-1);
    }
    array_stack_push(s, 7); // [0, 3, 5, 7], size=4, cap=4
    array_stack_push(s, 9); // [0, 3, 5, 7, 9], size=5, cap=8
    if(s->cap != 8){
        printf("stack resize error, cap should be 8, but get %d\n", s->cap);
        exit(-1);
    }
    array_stack_pop(s); // [0, 3, 5, 7], size=4, cap=8
    array_stack_pop(s); // [0, 3, 5], size=3, cap=8
    array_stack_pop(s); // [0, 3], size=2, cap=4
    array_stack_pop(s); // [0], size=1, cap=2
    if(s->size != 1) {
        printf("stack resize error, size should be 1, but get %d\n", s->size);
        exit(-1);
    }
    if(s->cap != 2){
        printf("stack resize error, cap should be 4, but get %d\n", s->cap);
        exit(-1);
    }
    printf("stack resize success\n");

    // test pop
    array_stack_push(s, 1);
    array_stack_push(s, 2); // [0, 1, 2]
    int ret = array_stack_pop(s); // [0, 1]
    if(ret != 2){
        printf("stack pop error, ret should be 2, but get %d\n", ret);
        exit(-1);
    }
    if(s->size != 2){
        printf("stack pop error, size should be 2, but get %d\n", s->size);
        exit(-1);
    }
    ret = array_stack_pop(s); // [0]
    if(ret != 1){
        printf("stack pop error, ret should be 1, but get %d\n", ret);
        exit(-1);
    }
    printf("stack pop success\n");

    // test peek
    array_stack_push(s, 3);
    array_stack_push(s, 7); // [0, 3, 7]
    ret = array_stack_peek(s);
    if(s->size != 3){
        printf("stack peek error, size should be 3, but get %d\n", s->size);
        exit(-1);
    }
    if(ret != 7){
        printf("stack peek error, ret should be 7, but get %d\n", ret);
        exit(-1);
    }
    printf("stack peek success\n");

    return 0;
}

int main() {
    return test_array_stack();
}