#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


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

	out(head);
	freeLinkList(head);
	return 0;
}
