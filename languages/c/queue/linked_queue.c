#include <stdlib.h>

#include "queue.h"

LinkedQueue *get_linked_queue() {
    LinkedQueue *q = (LinkedQueue *) malloc(sizeof(LinkedQueue));
    q->first = NULL;
    q->last = NULL;
    q->size = 0;

    return q;
}

int linked_queue_empty(LinkedQueue *q) {
    return q->size == 0;
}

void linked_queue_enqueue(LinkedQueue *q, int e) {
    if(linked_queue_empty(q)) {
        q->first = (QueueNode *) malloc(sizeof(QueueNode));
        q->first->data = e;
        q->last = q->first;
        q->size++;
    }else{
        QueueNode *s = (QueueNode *) malloc(sizeof(QueueNode));
        s->data = e;
        s->next = NULL;
        q->last->next = s;
        q->last = s;
        q->size++;
    }
}

int linked_queue_dequeue(LinkedQueue *q) {
    if(linked_queue_empty(q)) {
        printf("dequeue error, queue is empty");
        exit(-1);
    }

    int e = q->first->data;
    q->first = q->first->next;
    q->size--;

    return e;
}

int linked_queue_peek(LinkedQueue *q) {
    if(linked_queue_empty(q)) {
        printf("peek error, queue is empty");
        exit(-1);
    }

    return q->first->data;
}