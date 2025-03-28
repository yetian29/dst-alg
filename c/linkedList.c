
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
	Node *new_node = createNewNode(value);
	Node *ptr = head;
	int i = 0;

	if (position < 1)
	{
		fprintf(stderr, "Position outside range\n");
		exit(1);
	}

	// doubly linked list empty
	if (ptr->next == NULL)
	{
		ptr->next = new_node;
		new_node->prev = ptr;
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
	while (ptr->next != NULL && i < position - 1)
	{
		ptr = ptr->next;
		i++;
	}
	Node *tmp = ptr->next;
	ptr->next = new_node;
	new_node->prev = ptr;
	new_node->next = tmp;
	if (tmp != NULL) tmp->prev = new_node;
	(*size)++;

}

void removalNode(Node *head, Node **tail, int *size, int position)
{ 
	//  Doubly linked list empty
  if ((*size) == 0)
	{
		fprintf(stderr, "Doubly linked list empty\n");
		exit(1);
	}
	if (position < 1)
	{
		fprintf(stderr, "Position outside range\n");
		exit(1);
	}
	// Remove tail doubly linked list
	if (position == (*size))
	{
		Node *tmp = (*tail);
		(*tail) = (*tail)->prev;
		(*tail)->next = NULL;
		(*size)--;
		free(tmp);
		return;
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
	if (deleted != NULL) 
	{
		Node *tmp = deleted->next;
		ptr->next = tmp;
		if (tmp != NULL)
		{
			tmp->prev = ptr;
		}
		(*size)--;
		free(deleted);
	}

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

void freeDoublyLinkedList(Node *head)
{
	Node *ptr = head;
	while (ptr != NULL)
	{
		Node *tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	head = NULL;
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

	/*removalNode(head, &tail, &size, 0);*/
	/*removalNode(head, &tail, &size, 1);*/
	removalNode(head, &tail, &size, 5);
	out(head);
	freeDoublyLinkedList(head);
	
	return 0;

}
