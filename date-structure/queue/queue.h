#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct QueueNode {
    int val;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* QueueCreate();
bool QueueIsEmpty(Queue* q);
void QueuePush(Queue* q, int val);
int QueuePop(Queue* q);
void QueueDestroy(Queue* q);

#endif
