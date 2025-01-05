typedef struct Node
{
	int data;
	struct Node *next;
} Node

typedef struct
{
	Node *head;
	unsigned int size;
} LinkList;

LinkList *createLinkList()
{

}

int main()
{
	LinkList *list = createLinkList();
	return 0;
}
