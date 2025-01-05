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
	unsigned int size;
} LinkList;


LinkList *createLinkList()
{
	LinkList *list = (LinkList *)malloc(sizeof(LinkList));
	Node *head = (Node *)malloc(sizeof(head));
	list -> head = head;
	list -> size = 0;
	return list;
}

Node *create_new_node(int data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node -> data = data;
	new_node -> next = NULL;
	return new_node;
}

void add(LinkList *list, int value)
{
	Node *new_node = create_new_node(value);
	Node *node_current = list -> head;
	while (node_current -> next != NULL)
	{
			node_current = node_current -> next;
	}
	node_current -> next = new_node;
	list -> size += 1;
}

void out(LinkList *list)
{
	Node *node_current = list -> head;
	while (node_current -> next != NULL)
	{
		printf("%d", (node_current -> next) -> data);
		printf(" -> ");
		node_current = node_current -> next;

	}
	printf("\n");
}

int main()
{
	LinkList *list = createLinkList();
	add(list, 1);
	add(list, 2);
	add(list, 3);
	add(list, 4);
	add(list, 5);
	out(list);
	return 0;
}
