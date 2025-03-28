

/*#include <stdio.h>*/
/*#include <limits.h>*/
/*#include <stdlib.h>*/
/**/
/*int size = 0;*/
/**/
/*typedef struct Node */
/*{*/
/*	int data;*/
/*	struct Node *next;*/
/*} Node;*/
/**/
/*Node *createNewNode(int value)*/
/*{*/
/*	Node *new_node = malloc(sizeof(Node));*/
/*	if (new_node == NULL)*/
/*	{*/
/*		fprintf(stderr, "Allocation memory for new node failed\n");*/
/*		exit(1);*/
/*	}*/
/*	new_node->data = value;*/
/*	new_node->next = NULL;*/
/*	return new_node;*/
/**/
/**/
/*}*/
/**/
/*void addNewNodeToTail(Node **tail, int value)*/
/*{*/
/*	Node *new_node = createNewNode(value);*/
/*	(*tail)->next = new_node;*/
/*	*tail = (*tail)->next;*/
/*	size++;*/
/*}*/
/**/
/*void insertNewNode(Node *head, int position, int value)*/
/*{*/
/*	if (position < 1)*/
/*	{*/
/*		fprintf(stderr, "Location insert outside range\n");*/
/*		exit(1);*/
/*	}*/
/*	Node *ptr = head;*/
/*	int i = 0;*/
/*	while (ptr->next != NULL && i < position - 1)*/
/*	{*/
/*		ptr = ptr->next;*/
/*		i++;*/
/*	}*/
/*	Node *tmp = ptr->next;*/
/*	Node *new_node = createNewNode(value);*/
/*	ptr->next = new_node;*/
/*	new_node->next = tmp;*/
/*	size++;*/
/**/
/*}*/
/**/
/*void removalNode(Node *head, int position)*/
/*{*/
/*	if (position >= size || position < 1)*/
/*	{*/
/*		fprintf(stderr, "Location delete outside range\n");*/
/*		exit(1);	*/
/*	}*/
/*	Node *ptr = head;*/
/*	int i = 0;*/
/*	while (ptr->next!= NULL && i < position - 1)*/
/*	{*/
/*		ptr = ptr->next;*/
/*		i++;*/
/*	}*/
/*	Node *deleted = ptr->next;*/
/*	Node *after = deleted->next;*/
/*	ptr->next = after;*/
/*	size--;*/
/*	free(deleted);*/
/**/
/*}*/
/**/
/*Node *initSinglyLinkedList()*/
/*{*/
/*	Node *head = malloc(sizeof(Node));*/
/*	if (head == NULL)*/
/*	{*/
/*		fprintf(stderr, "Allocation memory for head failed\n");*/
/*		exit(1);*/
/*	}*/
/*	head->data = INT_MIN;*/
/*	head->next = NULL;*/
/*	return head;*/
/*}*/
/**/
/**/
/*void out(Node *head)*/
/*{*/
/*	Node *ptr = head;*/
/*	while (ptr->next != NULL)*/
/*	{*/
/*		ptr = ptr->next;*/
/*		printf("%d", ptr->data);*/
/*		if (ptr->next != NULL) printf(" -> ");*/
/**/
/*	}*/
/*	printf("\n");*/
/*}*/
/**/
/*void freeSinglyLinkedList(Node *head)*/
/*{*/
/*	Node *ptr = head;*/
/*	while (ptr != NULL)*/
/*	{*/
/*		Node *tmp = ptr;*/
/*		ptr = ptr->next;*/
/*		free(tmp);*/
/*	}*/
/*	head = NULL;*/
/**/
/*}*/
/**/
/*int main(void)*/
/*{*/
/*	Node *head = initSinglyLinkedList();*/
/*	Node *tail = head;*/
/**/
/*	addNewNodeToTail(&tail, 1);*/
/*	addNewNodeToTail(&tail, 2);*/
/*	addNewNodeToTail(&tail, 3);*/
/*	addNewNodeToTail(&tail, 4);*/
/**/
/*	insertNewNode(head, 1, 5);*/
/*	insertNewNode(head, 3, 6);*/
/**/
/**/
/*	removalNode(head, 5);*/
/*	/*removalNode(head, 0);*/
/**/
/**/
/**/
/*	out(head);*/
/*	freeSinglyLinkedList(head);*/
/*	return 0;*/
/*}*/

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
		fprintf(stderr, "Location insert outside range\n");
		exit(1);
	}
	
	Node *new_node = createNewNode(value);

	if (position >= (*size))
	{
		(*tail)->next = new_node;
		new_node->prev = *tail;
		new_node->next = NULL;
		*tail = new_node;
		*size++;
		return;
	}

	int i = 0;
	Node *ptr = head;
	while (ptr->next != NULL && i < position - 1)
	{
		ptr = ptr->next;
		i++;
	}
	Node *tmp  = ptr->next;
	ptr->next = new_node;
	new_node->prev = ptr;
	new_node->next = tmp;
	*tail = new_node;
	*size++;

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
	/*insertNewNode(head, 0, 1);*/
	insertNewNode(head, &tail, &size, 1, 1);
	insertNewNode(head, &tail, &size, 2, 2);
	insertNewNode(head, &tail, &size, 3, 3);
	insertNewNode(head, &tail, &size, 4, 4);
	insertNewNode(head, &tail, &size, 1, 5);
	insertNewNode(head, &tail, &size, 5, 6);

	out(head);


	return 0;

}
