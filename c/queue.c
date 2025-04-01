#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

struct CIRCULAR_QUEUE
{
	int *buffer; // Array store elements of queue
	int size; // Size of current elements in queue
	int front; // Index first elemenet in queue
	int rear; // Index tail elemenet in queue
	int capacity; // Maximum capacity of queue
};

Queue *InitializeQueue(int capacity)
{
	Queue *queue = malloc(sizeof(Queue));
	if (!queue)
	{
		fprintf(stderr, "Allocation memory for queue failed\n");
		exit(1);
	}
	queue->buffer = malloc(capacity * sizeof(int));
	if (!(queue->buffer)) 
	{
		fprintf(stderr, "Allocation memory for queue buffer failed\n");
		exit(1);
	}
	queue->size = 0;
	queue->front = 0;
	queue->rear = -1;
	queue->capacity = capacity;
	return queue;
}

void EnQueue(Queue *queue, int item)
{
	// Queue is full
	if (queue->size == queue->capacity)
	{
		fprintf(stderr, "Queue if fulled\n");
		exit(1);
	}
	queue->rear = (queue->rear + 1) % (queue->capacity);
	queue->buffer[queue->rear] = item;
	queue->size++;
}

void DeQueue(Queue *queue)
{
	if (queue->size == 0)
	{
		fprintf(stderr, "Queue is emptied\n");
		exit(1);
	}
	queue->front = (queue->front + 1) % (queue->capacity);
	queue->size--;
}

void Out(Queue *q)
{
	for (int i = q->front; i <= q->rear; i++)
	{
		printf("%d", q->buffer[i]);
		if (i < q->rear) printf(" | ");
	}
	printf("\n");

}


void FreeQueue(Queue *queue)
{
	free(queue->buffer);
	free(queue);
}

int main(void)
{
	int capacity = 20;
	Queue *queue = InitializeQueue(capacity);
	EnQueue(queue, 1);
	EnQueue(queue, 2);
	EnQueue(queue, 3);
	Out(queue);
	DeQueue(queue);
	Out(queue);
	return 0;
}
