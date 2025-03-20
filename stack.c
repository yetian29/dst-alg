#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int maxSize;
	int top;
	int *items;
} stack;


stack *initializeStack(int size)
{
	stack *s = malloc(sizeof(stack));
	if (!s) // equivalent s == NULL
	{
		fprintf(stderr, "Allocation memory for stack failed\n");
		exit(EXIT_FAILURE);
	}
	s->maxSize = size;
	s->top = -1;
	s->items = calloc(size, sizeof(int));
	if (!s->items) // equivalent s->items == NULL
	{
		fprintf(stderr, "Allocation memory for items failed\n");
		exit(EXIT_FAILURE);
	}
	return s;
}

void push(stack *s, int item)
{
	if (s->top == s->maxSize - 1)
	{
		fprintf(stderr, "Stack OverFlow\n");
		exit(EXIT_FAILURE);
	}

	s->items[s->top++] = item;
}

void pop(stack *s)
{
	if (s->top == -1)
	{
		fprintf(stderr, "Stack Empty\n");
		exit(EXIT_FAILURE);
	}
	s->top--;
}

void out(stack *s)
{
	for (int i = 0; i <= s->top; i++)
	{
		printf("%d", s->items[i]);
		if (i < s->top) printf(" | ");
	}
	printf("\n");

}

void freeStack(stack *s)
{
	free(s->items);
	free(s);
}




int main(void)
{
	int size = 10;
	stack *s = initializeStack(size);
	for (int i = 0; i < 10; i++)
	{
		push(s, i);
	}
	out(s);
	freeStack(s);
	return 0;
}
