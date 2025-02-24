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
		printf("Memory stack allocate failed\n");
		exit(1);
	}
	s->items = calloc(size, sizeof(int));
	if (!s->items)
	{
		printf("Memory items allocate failed\n");
		exit(1);
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

void pop(Stack *s)
{
	if (s->top == -1)
	{
		printf("Stack is empty\n");
		return;
	}
	s->top--;
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
	push(s, 4);
	push(s, 5);
	out(s);
	pop(s);
	pop(s);
	pop(s);
	pop(s);
	pop(s);
	pop(s);
	out(s);
	freeStack(s);
	
	return 0;
}
