#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 50

typedef struct
{
	int head;
	int tail;
	int items[CAPACITY];
} Queue;

Queue *createQueue()
{
	Queue *q = malloc(sizeof(Queue));
	if (q == NULL) exit(1);
	q -> head = 0;
	q -> tail = -1;
	return q;
}

void insert(Queue *q, int data)
{
	q -> tail++;
	q -> items[q -> tail] = data;
}

bool search(Queue *q, int data)
{
	for (int i = q -> head; i <= q -> tail; i++)
	{
		if (q -> items[i] == data) return true;
	}
	return false;

}

void delete(Queue *q)
{
	q -> head++;
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
	insert(q, 2);
	insert(q, 3);
	insert(q, 4);
	insert(q, 5);
	printf("Search 5 value in queue: %s\n", search(q, 5) ? "Found" : "Not Found");
	delete(q);
	out(q);
	freeQueue(q);
	return 0;
}
