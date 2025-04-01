#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

typedef struct CIRCULAR_QUEUE Queue;

Queue *InitializeQueue(int capacity);
void EnQueue(Queue *queue, int item);
void DeQueue(Queue *queue);
int GetFront(Queue *queue);
int GetRear(Queue *queue);
void out(Queue *queue);
void FreeQueue(Queue *queue);

#endif

