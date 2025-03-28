// Stack is created by array
/*#include <stdio.h>*/
/*#include <stdlib.h>*/
/**/
/*typedef struct stack*/
/*{*/
/*	int maxSize;*/
/*	int top;*/
/*	int *items;*/
/*} stack;*/
/**/
/**/
/*stack *initializeStack(int size)*/
/*{*/
/*	stack *s = malloc(sizeof(stack));*/
/*	if (!s) // equivalent s == NULL*/
/*	{*/
/*		fprintf(stderr, "Allocation memory for stack failed\n");*/
/*		exit(EXIT_FAILURE);*/
/*	}*/
/*	s->maxSize = size;*/
/*	s->top = -1;*/
/*	s->items = calloc(size, sizeof(int));*/
/*	if (!s->items) // equivalent s->items == NULL*/
/*	{*/
/*		fprintf(stderr, "Allocation memory for items failed\n");*/
/*		free(s);*/
/*		exit(EXIT_FAILURE);*/
/*	}*/
/*	return s;*/
/*}*/
/**/
/*void push(stack *s, int item)*/
/*{*/
/*	if (s->top == s->maxSize - 1)*/
/*	{*/
/*		fprintf(stderr, "Stack OverFlow\n");*/
/*		exit(EXIT_FAILURE);*/
/*	}*/
/**/
/*	s->items[++s->top] = item;*/
/*}*/
/**/
/*void pop(stack *s)*/
/*{*/
/*	if (s->top == -1)*/
/*	{*/
/*		fprintf(stderr, "Stack Empty\n");*/
/*		exit(EXIT_FAILURE);*/
/*	}*/
/*	s->top--;*/
/*}*/
/**/
/*void out(stack *s)*/
/*{*/
/*	for (int i = 0; i <= s->top; i++)*/
/*	{*/
/*		printf("%d", s->items[i]);*/
/*		if (i < s->top) printf(" | ");*/
/*	}*/
/*	printf("\n");*/
/**/
/*}*/
/**/
/*void freeStack(stack *s)*/
/*{*/
/*	free(s->items);*/
/*	free(s);*/
/*}*/
/**/
/**/
/**/
/**/
/*int main(void)*/
/*{*/
/*	int size = 10;*/
/*	stack *s = initializeStack(size);*/
/*	for (int i = 0; i < 10; i++)*/
/*	{*/
/*		push(s, i);*/
/*	}*/
/*	out(s);*/
/*	pop(s);*/
/*	out(s);*/
/*	freeStack(s);*/
/*	return 0;*/
/*}*/


// Stack is created by singly linked list

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

typedef struct Stack
{
	Node *head;
	int size;
} Stack;

Stack *initializeStack()
{
	Stack *s = malloc(sizeof(Stack));
	if (!s)
	{
		fprintf(stderr, "Allocation memory for stack failed\n");
		exit(1);
	}
	s->head = malloc(sizeof(Node));
	if (!(s->head))
	{
	
		fprintf(stderr, "Allocation memory for head node failed\n");
		exit(1);
	}
	(s->head)->data = INT_MIN;
	(s->head)->next = NULL;
	s->size = 0;
	return s;
}

Node *createNewNode(int value)
{
	Node *new_node = malloc(sizeof(Node));
	if (!new_node)
	{
		fprintf(stderr, "Allocation memory for new node failed\n");
		exit(1);
	}
	new_node->data = value;
	new_node->next = NULL;
	return new_node;
}

void push(Stack *s, int value)
{
	Node *ptr = s->head;
	Node *new_node = createNewNode(value);
	Node *tmp = ptr->next;
	ptr->next = new_node;
	new_node->next = tmp;
	(s->size)++;
}

void pop(Stack *s)
{
	if (s->size == 0)
	{
		fprintf(stderr, "Stack has emptied\n");
		exit(1);
	}
	Node *ptr = s->head;
	Node *poped = ptr->next;
	ptr->next = poped->next;
	(s->size)--;
	free(poped);
}

void out(Stack *s)
{
	Node *ptr = (s->head);
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		printf("%d", ptr->data);
		if (ptr->next != NULL) printf(" -> ");
	}
	printf("\n");
}

void freeStack(Stack *s)
{
	Node *ptr = (s->head);
	while (ptr != NULL)
	{
		Node *tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	free(s);
}


int main(void)
{
	Stack *s = initializeStack();
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	pop(s);
	pop(s);
	pop(s);
	pop(s);
	pop(s);
	out(s);
	freeStack(s);

	return 0;
}
