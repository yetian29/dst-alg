#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct Node
{
	int data;
	struct Node *next;
} Node;

typedef struct Queue
{
	Node *head;
	Node *tail;
} Queue;

Queue *createQueue()
{
	Queue *q = malloc(sizeof(Queue));
	Node *head = malloc(sizeof(Node));
	head -> data = -999999999;
	head -> next = NULL;
	q -> head = head;
	q -> tail = q -> head;
	return q;
}

Node *createNewNode(int data)
{
	Node *new_node = malloc(sizeof(Node));
	new_node -> data = data;
	new_node -> next = NULL;
	return new_node;
}

void insert(Queue *q, int data)
{
	Node *new_node = createNewNode(data);
	(q -> tail) -> next = new_node;
	q -> tail = new_node;
}

bool search(Queue *q, int data)
{
	Node *current = q -> head;
	while (current -> next != NULL)
	{
		if ((current -> next) -> data == data)
		{
			return true;
		}
		current = current -> next;
	}
	return false;
}

void delete(Queue *q)
{
	Node *current = q -> head;
	Node *tmp = current -> next;
	if (tmp == NULL)
	{
		printf("Queue is empty\n");
		exit(1);
	}
	current -> next = tmp -> next;
	free(tmp);
}

void out(Queue *q)
{
	Node *current =  q -> head;
	while (current != NULL)
	{
		printf("%d", current -> data);
		if (current -> next != NULL)
		{
			printf(" -> ");
		}
		current = current -> next;
	}
	printf("\n");
}

void freeQueue(Queue *q)
{
	Node *current = q -> head;
	while (current != NULL)
	{
		Node *tmp = current;
		current = current -> next;
		free(tmp);
	}
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
	out(q);
	printf("Search 10 value in queue: %s\n", search(q, 10) ? "Found" : "Not Found");
	delete(q);
	delete(q);
	delete(q);
	delete(q);
	delete(q);
	delete(q);
	out(q);
	freeQueue(q);
	return 0;
}
