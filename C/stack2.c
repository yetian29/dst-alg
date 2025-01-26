#include <stdlib.h>
#include <stdio.h>


typedef struct Node
{
	int data;
	struct Node *next;
} Node;


typedef struct 
{
	Node *head;
	int size;
} Stack;

Stack *createStack()
{
	Stack *s = malloc(sizeof(Stack));
	Node *head = malloc(sizeof(Node));
	head -> data = -999999999;
	head -> next = NULL;
	s -> head = head;
	s -> size = 1;
	return s;
}

Node *createNewNode(int data)
{
	Node *new_node = malloc(sizeof(Node));
	new_node -> data = data;
	new_node -> next = NULL;
	return new_node;
}

void push(Stack *s, int data)
{
	Node *current = s -> head;
	Node *new_node = createNewNode(data);
	Node *tmp = current -> next;
	current -> next = new_node;
	new_node -> next = tmp;
	s -> size++;
}

void pop(Stack *s)
{
	Node *current = s -> head;
	Node *tmp = current -> next;
	current -> next = tmp -> next;
	free(tmp);
	s -> size--;
	if (s -> size == 1)
	{
		printf("Stack is emmpty\n");
		exit(0);
	}

}

void out(Stack *s)
{
	Node *current = s -> head;
	while (current != NULL)
	{
		printf("%d", current -> data);
		if (current -> next != NULL) printf(" -> ");
		current = current -> next;
	}
	printf("\n");
}

void freeStack(Stack *s)
{
	Node *current = s -> head;
	while (current != NULL)
	{
		Node *tmp = current;
		current = current -> next;
		free(tmp);
	}
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
	out(s);
	return 0;
}
