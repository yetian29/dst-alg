#include <stdlib.h>
#include <stdio.h>


typedef struct 
{
	int maxsize;
	int top;
	int *items;

} Stack;

Stack *createStack(unsigned int size)
{
	Stack* s = malloc(sizeof(Stack));
	if (!s)
	{
		fprintf(stderr, "Memory allocate failed\n");
		exit(EXIT_FAILURE);
	}
	s->items = calloc(size, sizeof(int));
	if (!s->items)
	{
		free(s);
		fprintf(stderr, "Memory allocate failed\n");
		exit(EXIT_FAILURE);
	}
	s->maxsize = size;
	s->top = -1;
	return s;
}

void push(Stack *s, int item)
{
	if (s->top == s->maxsize - 1)
	{
		printf("Stack has fulled, can't push item\n");
		return;
	}
	s->top++;
	s->items[s->top] = item;
	
}

void out(Stack *s)
{
	for (int i = 0; i <= s->top; i++)
	{
		printf("%d | ", s->items[i]);

	}
	printf("\n");
}

void freeStack(Stack *s)
{
	free(s->items);
	free(s);
}

int main(void)
{
	unsigned int size = 5;
	Stack *s = createStack(size);
	push(s, 1);
	push(s, 2);
	push(s, 3);
	out(s);
	freeStack(s);
	
	return 0;
}
