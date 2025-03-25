#include <stdio.h>
#include <stdlib.h>
#include <limits.h>




typedef struct Node 
{
	int data;
	struct Node *next;
} Node;

Node *createNewNode(int value)
{
	Node *new_node = malloc(sizeof(Node));
	new_node->data = value;
	new_node->next = NULL;
	return new_node;
}

void addNodeToTail(Node *head, int value)
{
	Node *ptr = head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = createNewNode(value);

}
Node *createLinkList()
{
	Node *head = malloc(sizeof(Node));
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
		if (ptr->next != NULL)
		{
		   printf(" -> ");
		}
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
	Node *head = createLinkList();
	addNodeToTail(head, 1);	
	out(head);
	freeLinkList(head);

	return 0;
}
