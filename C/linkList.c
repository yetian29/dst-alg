#include <stdio.h>

typedef struct Node
{
	int data;
	Node *next;
} Node;

typedef struct 
{
	Node *head;
	unsinged int size;
} LinkList;


LinkList *init()
{
	LinkList *linkList = (LinkList *)malloc(sizeof(LinkList));
	linkList -> head = NULL;
	linkList -> size = 0;
	return linkList;
}

Node *create_node_new(int data)
{
	Node *new_node = (Node *)malloc(sizeof(new_node));
	new_node -> data = data;
	new_node -> next = NULL;
	return new_node;
}

void add(LinkList *linkList, int data)
{
	Node *new_node = create_node_new(data);
	Node *node_current = linkList -> head;
	while (node_current != NULL)
	{
		node_current = node_current -> next;
	}
	node_current -> next = new_node;

}

int main(void)
{
	
	LinkList *linkList = init();
	add(linkList, 10);
	add(linkList, 20);
	add(linkList, 30);
	add(linkList, 40);
	add(linkList, 50);


	return 0;
}
