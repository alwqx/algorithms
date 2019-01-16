#include <stdio.h>

typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

typedef struct LinkedStack {
    int size;
    struct StackNode *first;
} LinkedStack;

LinkedStack *get_linked_stack();
int linked_stack_empty(LinkedStack *);
void linked_stack_push(LinkedStack *, int);
int linked_stack_pop(LinkedStack *);
int linked_stack_peek(LinkedStack *);

typedef struct ArrayStack {
    int *array;
    int size;
    int cap;
} ArrayStack;

ArrayStack *get_array_stack();
int array_stack_empty(ArrayStack *);
void array_stack_resize(ArrayStack *, int);
void array_stack_push(ArrayStack *, int);
int array_stack_pop(ArrayStack *);
int array_stack_peek(ArrayStack *);