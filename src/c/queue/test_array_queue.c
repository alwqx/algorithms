#include <stdlib.h>

#include "queue.h"

int test_array_queue() {
    ArrayQueue *q = get_array_queue();

    // test empty
    if(!array_queue_empty(q)){
        printf("queue should be empty, but not\n");
        exit(-1);
    }

    // test enqueue
    array_queue_enqueue(q, 1);
    array_queue_enqueue(q, 2);
    // q=[1, 2], size=2, cap=2, first=0, last=0
    array_queue_enqueue(q, 3);
    array_queue_enqueue(q, 14);
    // q=[1, 2, 3, 14], size=4, cap=4, last=0
    if(q->size != 4) {
        printf("enqueue error, size should be 4, but get %d\n", q->size);
        exit(-1);
    }
    if(q->cap != 4) {
        printf("enqueue error, cap should be 4, but get %d\n", q->cap);
        exit(-1);
    }
    if(q->last != 0) {
        printf("enqueue error, last should be 0, but get %d\n", q->last);
        exit(-1);
    }
    if(q->first != 0) {
        printf("enqueue error, first should be 0, but get %d\n", q->first);
        exit(-1);
    }
    if(q->array[0]!=1 || q->array[1]!=2 || q->array[2]!=3 || q->array[3]!=14){
        printf("enqueue error, queue data not equal\n");
        exit(-1);
    }
    printf("test enqueue success\n");

    // test peek
    int ret = array_queue_peek(q);
    if(ret != 1){
        printf("peek error, ret should be 1, but get %d\n", ret);
        exit(-1);
    }
    printf("test peek success\n");

    // test dequeue
    ret = array_queue_dequeue(q);
    // q=[2, 3, 14], first=1, last=4, size=3, cap=4
    if(ret != 1) {
        printf("dequeue error, ret should be 1, but get %d\n", ret);
        exit(-1);
    }
    if(q->size!=3) {
        printf("dequeue error, size should be 3, but get %d\n", q->size);
        exit(-1);
    }
    if(q->first!=1) {
        printf("dequeue error, first should be 1, but get %d\n", q->first);
        exit(-1);
    }
    ret = array_queue_dequeue(q);
    // q=[3, 14], first=2, last=4, size=2, cap=4
    if(ret != 2) {
        printf("dequeue error, ret should be 2, but get %d\n", ret);
        exit(-1);
    }
    if(q->size!=2) {
        printf("dequeue error, size should be 2, but get %d\n", q->size);
        exit(-1);
    }
    if(q->first!=2) {
        printf("dequeue error, first should be 2, but get %d\n", q->first);
        exit(-1);
    }
    printf("test dequeue success\n");

    // test resize
    array_queue_dequeue(q);
    // q=[14], first=0, last=1, size=1, cap=2
    if(q->size != 1){
        printf("resize error, size should be 1, but get %d\n", q->size);
        exit(-1);
    }
    if(q->cap != 2) {
        printf("resize error, cap should be 2, but get %d\n", q->cap);
        exit(-1);
    }
    if(q->first != 0) {
        printf("dequeue error, first should be 0, but get %d\n", q->first);
        exit(-1);
    }
    if(q->last != 1) {
        printf("resize error, last should be 1, but get %d\n", q->last);
        exit(-1);
    }
    array_queue_resize(q, q->cap*2);
    // q=[14], first=0, last=1, size=1, cap=4
    if(q->cap != 4) {
        printf("resize error, cap should be 4, but get %d\n", q->cap);
        exit(-1);
    }
    printf("test resize success\n");

    return 0;
}

int main() {
    return test_array_queue();
}