#include <stdlib.h>
#include <stdio.h>

#define CAPACITY 50

typedef struct 
{
	int items[CAPACITY];
	unsigned int head;
	int tail;
	unsigned int size;
} Queue;

Queue *createQueue()
{
	Queue *q = malloc(sizeof(Queue));
	if (q == NULL) exit(1);
	q -> head = 0;
	q -> tail = -1;
	q -> size = 0;
	return q;
}

void insert(Queue *q, int data)
{
	if (q -> size == 0)
	{
		q -> items[q -> head] = data;
		q -> tail++;
	}
	else
	{
		q -> tail++;
		q -> items[q -> tail] = data;
	}
	q -> size++;
}

void delete(Queue *q)
{
	if (q -> size == 0)
	{
		printf("Queue is empty.\n");
		exit(1);
	}
	else 
	{
		q -> head++;
		q -> size--;
	}
  if (q -> size == 0)
	{
		q -> head = 0;
		q -> tail = -1;
	}
}

void out(Queue *q)
{
	for (int i = q -> head; i <= q -> tail; i++)
	{
			printf("%d", q -> items[i]);
			printf(" | ");
	}
	printf("\n");
}

void freeQueue(Queue *q)
{
	free(q);
}

int main(void)
{
	Queue *q = createQueue();
	insert(q, 1);
	insert(q, 3);
	insert(q, 5);
	insert(q, 7);
	delete(q);

	out(q);
	freeQueue(q);
	return 0;
}
