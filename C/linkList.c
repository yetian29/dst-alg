#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

typedef struct 
{
	Node *head;
	Node *tail;
	unsigned int size;
} LinkList;

LinkList *createLinkList()
{
	LinkList *list = (LinkList *)malloc(sizeof(LinkList));
  Node *head = (Node *)malloc(sizeof(Node));
	head -> data = -1;
	head -> next = NULL;
	list -> head = head;
	list -> tail = head;
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
void addFirst(LinkList *list, int data)
{
	Node *new_node = create_new_node(data);
	Node *current = list -> head;
	if (current -> next == NULL)
	{
		current -> next = new_node;
	}
	else
	{
		Node *tmp = current -> next;
		current -> next = new_node;
		new_node -> next = tmp;
	}
	list -> size += 1;
}

void addLast(LinkList *list, int data)
{
	Node *new_node = create_new_node(data);
	Node *tail = list -> tail;
	tail -> next = new_node;
	list -> tail = new_node;
	list -> size += 1;
}

void out(LinkList *list)
{
	Node *current = list -> head;
	while (current != NULL)
	{
		printf("%d", current -> data);
		printf(" -> ");
		current = current -> next;
	}
	printf("\n");
}

void freeLinkList(LinkList *list)
{
	Node *current = list -> head;
	while (current != NULL)
	{
		Node *tmp  = current;
		current = current -> next;
		free(tmp);
	}
	free(list);

}
int main(void)
{
	LinkList *list = createLinkList();
	/*addFirst(list, 1);*/
	/*addFirst(list, 2);*/
	/*addFirst(list, 3);*/
	/*addFirst(list, 4);*/
	/*addFirst(list, 5);*/
	addLast(list, 6);
	addLast(list, 7);
	addLast(list, 8);
	addLast(list, 9);
	addLast(list, 10);
	out(list);
	freeLinkList(list);
	return 0;
}
