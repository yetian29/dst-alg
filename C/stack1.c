#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 50


typedef struct
{
	int max_size;
	int top;
	int items[CAPACITY];
} Stack;


Stack *createStack()
{
	Stack *s = malloc(sizeof(Stack));
	s -> max_size = 0;
	s -> top = -1;
	return s;
}

void push(Stack *s, int data)
{
	s -> top++;
	s -> items[s -> top] = data;
	s -> max_size++;
}

void pop(Stack *s)
{
	s -> top--;
	if (s -> top == -1)
	{
		printf("Stack is empty\n");
		exit(0);
	}
}

void out(Stack *s)
{
	for (int i = 0; i <= s -> top; i++)
	{
		printf("%d | ", s -> items[i]);
	}
	printf("\n");
}

void freeStack(Stack *s)
{
	free(s);
}

int main(void)
{
	Stack *s = createStack();
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
	out(s);
	freeStack(s);
	return 0;
}
