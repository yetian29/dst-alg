#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int size = 1;

typedef struct Node 
{
	int data;
	struct Node *next;
} Node;

Node *createNewNode(int value)
{
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL)
	{
		fprintf(stderr, "Allocation memory for new node failed\n");
		exit(1);
	}
	new_node->data = value;
	new_node->next = NULL;
	return new_node;


}

void addNewNodeToTail(Node **tail, int value)
{
	Node *new_node = createNewNode(value);
	(*tail)->next = new_node;
	*tail = (*tail)->next;
	size++;
}

void insertNewNode(Node *head, int position, int value)
{
	Node *ptr = head;
	int i = 0;
	while (ptr!= NULL && i < position - 1)
	{
		if (ptr->next != NULL) ptr = ptr->next;
		i++;
	}
	Node *tmp = ptr->next;
	Node *new_node = createNewNode(value);
	ptr->next = new_node;
	new_node->next = tmp;
	size++;

}

void removalNode(Node *head, int position)
{
	if (position >= size)
	{
		fprintf(stderr, "Location delete outside range\n");
		exit(1);	
	}
	Node *ptr = head;
	int i = 0;
	while (ptr!= NULL && i < position - 1)
	{
		if (ptr->next != NULL) ptr = ptr->next;
		i++;
	}
	Node *deleted = ptr->next;
	Node *after = deleted->next;
	ptr->next = after;
	size--;
	free(deleted);

}

Node *initLinkList()
{
	Node *head = malloc(sizeof(Node));
	if (head == NULL)
	{
		fprintf(stderr, "Allocation memory for head failed\n");
		exit(1);
	}
	head->data = INT_MIN;
	head->next = NULL;
	return head;
}


void out(Node *head)
{
	Node *ptr = head;
	while (ptr != NULL)
	{
		printf("%d", ptr->data);
		if (ptr->next != NULL) printf(" -> ");
		ptr = ptr->next;
	}
	printf("\n");
}

void freeLinkList(Node *head)
{
	Node *ptr = head;
	while (ptr != NULL)
	{
		Node *tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}

int main(void)
{
	Node *head = initLinkList();
	Node *tail = head;

	addNewNodeToTail(&tail, 1);
	addNewNodeToTail(&tail, 2);
	addNewNodeToTail(&tail, 3);
	addNewNodeToTail(&tail, 4);

	insertNewNode(head, 1, 5);
	insertNewNode(head, 3, 6);

	removalNode(head, 3);
	removalNode(head, 5);
	removalNode(head, 5);


	out(head);
	freeLinkList(head);
	return 0;
}
