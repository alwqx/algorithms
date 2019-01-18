#include <stdlib.h>

#include "queue.h"

int test_linked_queue() {
    LinkedQueue *q = get_linked_queue();

    // test empty
    if(!linked_queue_empty(q)) {
        printf("queue should be empty\n");
        exit(-1);
    }

    // test enqueue
    linked_queue_enqueue(q, 1);
    linked_queue_enqueue(q, 2);
    linked_queue_enqueue(q, 4);
    linked_queue_enqueue(q, 9); // [1,2,4,9] size=4, first=1, last=9
    if(q->size != 4) {
        printf("enqueue error, size should be 4, but get %d\n", q->size);
        exit(-1);
    }
    if(q->first->data != 1) {
        printf("enqueue error, first data should be 1, but get %d\n", q->first->data);
        exit(-1);
    }
    if(q->last->data != 9) {
        printf("enqueue error, last data should be 9, but get %d\n", q->last->data);
        exit(-1);
    }
    printf("test enqueue success\n");

    // test dequeue
    int ret = linked_queue_dequeue(q);
    if(ret != 1) {
        printf("dequeue error, ret should be 1, but get %d\n", ret);
        exit(-1);
    }
    if(q->size != 3) {
        printf("dequeue error, size should be 3, but get %d\n", q->size);
        exit(-1);
    }
    if(q->first->data != 2) {
        printf("dequeue error, first data should be 2, but get %d\n", q->first->data);
        exit(-1);
    }
    if(q->last->data != 9) {
        printf("dequeue error, last data should be 9, but get %d\n", q->last->data);
        exit(-1);
    }
    printf("test dequeue success\n");

    // test peek
    ret = linked_queue_peek(q);
    if(ret != 2) {
        printf("peek error, ret should be 1, but get %d\n", ret);
        exit(-1);
    }
    if(q->size != 3) {
        printf("peek error, size should be 3, but get %d\n", q->size);
        exit(-1);
    }
    if(q->first->data != 2) {
        printf("peek error, first data should be 2, but get %d\n", q->first->data);
        exit(-1);
    }
    if(q->last->data != 9) {
        printf("peek error, last data should be 9, but get %d\n", q->last->data);
        exit(-1);
    }
    printf("test peek success\n");

    return 0;
}

int main() {
    return test_linked_queue();
}