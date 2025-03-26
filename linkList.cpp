#include <iostream>
#include <limits.h>

typedef struct Node
{
	int data;
	Node *next;
} Node;

class LinkList
{
private:
	Node *head;
	Node *tail;
  
public:
	// Intialize link list
	LinkList()
	{
		head = new Node();
		head->data = INT_MIN;
		head->next = nullptr;
		tail = head;
	}

	Node *createNewNode(int value)
	{
		Node *new_node = new Node(); // Allocating  memory
		new_node->data = value;
		new_node->next = nullptr;
		return new_node;
	}


	void addNewNodeToTail(int value)
	{
		Node *new_node = createNewNode(value);
		tail->next = new_node;
		tail = tail->next;
	}

	void out()
	{
		Node *ptr = head;
		while (ptr != nullptr)
		{
			std::cout << ptr->data;
			if (ptr->next != nullptr)
			{
				std::cout << " -> ";
			}
			ptr = ptr->next;
		}
		std::cout << std::endl;
	}

	void freeLinkList()
	{
		Node *ptr = head;
		while (ptr != nullptr)
		{
			Node *tmp = ptr;
			if (ptr->next != nullptr)
			{
				ptr = ptr->next;

			}
			delete tmp;
		}
		head = tail = nullptr;
		}
};

int main(void)
{
	LinkList list;
	list.addNewNodeToTail(1);
	list.addNewNodeToTail(2);
	list.addNewNodeToTail(3);
	list.addNewNodeToTail(4);
	list.out();


	return 0;
}
