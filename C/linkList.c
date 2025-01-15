#include <stdlib.h>
#include <stdio.h>



typedef struct ListNode
{
	int data;
	struct ListNode *next;
} ListNode;

typedef struct LinkList
{
	ListNode *head;
	ListNode *tail;
	unsigned int size;
} LinkList;

LinkList *createLinkList()
{
	LinkList *list = (LinkList *)malloc(sizeof(LinkList));
	list -> head = NULL;
	list -> tail = NULL;
	list -> size = 0;
	return list;
}

ListNode *createNewNode(int data)
{
	ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
	new_node -> data = data;
	new_node -> next = NULL;
	return new_node;
}

void addFirst(LinkList *list, int data)
{
	ListNode *current = list -> head;
	ListNode *new_node = createNewNode(data);
	if (current == NULL)
	{
		list -> head = new_node;
		list -> size++;
		return;
	}
	list -> head = new_node;
	new_node -> next = current;
	list -> size++;
}

void addLast(LinkList *list, int data)
{
	ListNode *current = list -> head;
	ListNode *new_node = createNewNode(data);
	if (current == NULL)
	{
		list -> head = new_node;
		list -> tail = list -> head;
		list -> size++;
		return;
	}
	(list -> tail) -> next = new_node;
	list -> tail = new_node;
	list -> size++;
}

void out(LinkList *list)
{
	ListNode *current = list -> head;
	while (current != NULL)
	{
		printf("%d", current -> data);
		if (current -> next != NULL)
		{
			printf(" -> ");
		}
		current = current -> next;
	}
	printf("\n");
}

void freeLinkList(LinkList *list)
{
	ListNode *current = list -> head;
	while (current != NULL)
	{
		ListNode *tmp  = current;
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
	addLast(list, 1);
	addLast(list, 2);
	addLast(list, 3);
	addLast(list, 4);
	addLast(list, 5);
	addLast(list, 6);
	out(list);
	freeLinkList(list);
	return 0;
}
