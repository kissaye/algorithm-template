#include "queue.h"
#include<stdlib.h>

Queue* QueueCreate()
{
    Queue *q=malloc(sizeof(Queue));
    if(q==NULL)
    {
        return NULL;
        q->front=q->rear=NULL;
    }
}

bool QueueIsEmpty(Queue* q)
{
    return q->front==NULL;
}

void QueuePush(Queue* q,int val)
{
    QueueNode* node=malloc(sizeof(QueueNode));
    if(node==NULL)
    {
        return;
    }
    node->val=val;
    node->next=NULL;

    if(q->rear==NULL)
    {
        q->front=q->rear=node;
    }
    else
    {
        q->rear->next=node;
        q->rear=node;
    }

}

int QueuePop(Queue *q)
{
    if(QueueIsEmpty(q))
    return NULL;

    QueueNode*temp=q->front;
    int date=temp->val;
    q->front=temp->next;
    
    if(q->front==NULL)
    {
        q->rear=NULL;
    }
    free(temp);
    return date;
}

void QueueDestroy(Queue* q)
{
    while(!QueueIsEmpty(q))
    {
        QueuePop(q);
    }
    free(q);
}