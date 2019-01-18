#include <stdio.h>

typedef struct ArrayQueue {
    int *array;
    int size;
    int cap;
    int first; // head of array
    int last; // tail of array
} ArrayQueue;

ArrayQueue *get_array_queue();
void array_queue_resize(ArrayQueue *, int);
int array_queue_empty(ArrayQueue *);
void array_queue_enqueue(ArrayQueue *, int);
int array_queue_dequeue(ArrayQueue *);
int array_queue_peek(ArrayQueue *);

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct LinkedQueue {
    int size;
    struct QueueNode *first;
    struct QueueNode *last;
} LinkedQueue;

LinkedQueue *get_linked_queue();
int linked_queue_empty(LinkedQueue *);
void linked_queue_enqueue(LinkedQueue *, int);
int linked_queue_dequeue(LinkedQueue *);
int linked_queue_peek(LinkedQueue *);