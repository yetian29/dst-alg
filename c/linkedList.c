

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
} Node;


Node *createNewNode(int value)
{
	Node *new_node = malloc(sizeof(Node));
	if (!new_node)
	{
		fprintf(stderr, "Allocation memory for new node failed\n");
		exit(1);
	}
	new_node->prev = NULL;
	new_node->data = value;
	new_node->next = NULL;
	return new_node;
}

Node *initDoublyLinkedList()
{
	Node *head = malloc(sizeof(Node));
	if (!head)
	{
		fprintf(stderr, "Allocation memory for head failed\n");
		exit(1);
	}
	head->prev = NULL; 
	head->data = INT_MIN;
	head->next = NULL;
	return head;
}
void insertNewNode(Node *head, Node **tail, int *size, int position, int value)
{
	if (position < 1)
	{
		fprintf(stderr, "Position outside range\n");
		exit(1);
	}
	Node *new_node = createNewNode(value);
	// doubly linked list empty
	if (head->next == NULL)
	{
		head->next = new_node;
		new_node->prev = head;
		new_node->next = NULL;
		(*tail) = new_node;
		(*size)++;
		return;
	}
	// Insert tail doubly linked list
	if (position > (*size))
	{
		(*tail)->next = new_node;
		new_node->prev = (*tail);
		new_node->next = NULL;
		(*size)++;
		(*tail) = new_node;
		return;
	}
	// Insert head and between doubly linked list
	Node *ptr = head;
	int i = 0;
	while (ptr->next != NULL && i < position - 1)
	{
		ptr = ptr->next;
		i++;
	}
	Node *tmp = ptr->next;
	ptr->next = new_node;
	new_node->prev = head;
	new_node->next = tmp;
	if (!tmp) tmp->prev = new_node;
	(*size)++;

}

void removalNode(int *size, int position)
{ 
	//  Doubly linked list empty
  if (size == 0)
	{
		fprintf(stderr, "Doubly linked list empty\n");
		exit(1);
	}
	// Remove head and between doubly linked list
	Node *ptr = head;
	int i = 0;
	while (ptr->next != NULL && i < position - 1)
	{
		ptr = ptr->next;
		i++;
	}
	Node *deleted = ptr->next;
	if (!deleted) 
	{
		Node *tmp = deleted->next;
	}
	ptr->next = tmp;
	if (!tmp) 
	{
		tmp->prev = ptr;
	}
	free(deleted);

}


void out(Node *head)
{
	Node *ptr = head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		printf("%d", ptr->data);
		if (ptr->next != NULL) printf(" <-> ");
	}
	printf("\n");
}

int main(void)
{
	Node *head = initDoublyLinkedList();
	Node *tail = head;
	int size = 0;
	/*insertNewNode(head, &tail, &size, 0, 1);*/
	insertNewNode(head, &tail, &size, 1, 1);
	insertNewNode(head, &tail, &size, 1, 2);
	insertNewNode(head, &tail, &size, 1, 3);
	insertNewNode(head, &tail, &size, 2, 4);
	insertNewNode(head, &tail, &size, 5, 5);
	out(head);
	return 0;

}
