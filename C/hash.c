#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct HashNode
{
	int key;
	unsigned int data;
	struct HashNode *next;
} HashNode;

typedef struct
{
	HashNode **buckets;
	unsigned int size;
} HashTable;

unsigned int hash(int key, unsigned int size)
{
	return abs(key) % size;
}

HashTable *createHashTable(unsigned int size)
{
	HashTable *t = malloc(sizeof(HashTable));
	HashNode **buckets = calloc(size, sizeof(HashNode *));
	t -> buckets = buckets;
	t -> size = size;
	return t;
}

HashNode *createNewNode(int key, unsigned int data)
{
	HashNode *new_node = malloc(sizeof(HashNode));
	new_node -> key = key;
	new_node -> data = data;
	new_node -> next = NULL;
	return new_node;
}
void insert(HashTable *t, int key, unsigned data)
{
	unsigned int i = hash(key, t -> size);
	HashNode *current = t -> buckets[i];
	HashNode *new_node = createNewNode(key, data);
	t -> buckets[i] = new_node;
	new_node -> next = current; 
}

bool search(HashTable *t, int key)
{
	unsigned int i = hash(key, t -> size);
	HashNode *current = t -> buckets[i];
	while (current != NULL)
	{
		if (current -> key == key) return true;
		current = current -> next;
	}
	return false;
}

void delete(HashTable *t, int key)
{
	unsigned int i = hash(key, t -> size);
	HashNode *current = t -> buckets[i];
	HashNode *prev = NULL;
	if (current -> key == key)
	{
		t -> buckets[i] = current -> next;
		free(current);
		return;
	}
	while (current != NULL && current -> key != key)
	{
		prev = current;
		current = current -> next;
  }
	if (current == NULL) 
	{
		printf("Value isn't in HashTable\n");
	}
	else
	{
		prev -> next = current -> next;
		free(current);
	}


}

void out(HashTable *t)
{
	for (int i = 0; i < t -> size; i++)
	{
		HashNode *current = t -> buckets[i];
		while (current != NULL)
		{
			printf("(%d, %d)", current -> key, current -> data);
			if (current -> next != NULL) printf(" -> ");
			current = current -> next;
		}
	}
	printf("\n");
}

void freeHashTable(HashTable *t)
{
	for (int i = 0; i < t -> size; i++)
	{
		HashNode *current = t -> buckets[i];
		while (current != NULL)
		{
			HashNode *tmp  = current;
			current = current -> next;
			free(tmp);
		}

	}
	free(t -> buckets);
	free(t);
}

int main(void)
{
	int nums[] = {1, 2, 3, 4, 5};
	unsigned int size = sizeof(nums) / sizeof(nums[0]);
	HashTable *t = createHashTable(size);
	for (int i = 0; i < size; i++)
	{
		insert(t, nums[i], i);
	}
	out(t);
	printf("Search value 5 in HashTable: %s\n", search(t, 5) ? "Found" : "Not Found");
	printf("Search value 10 in HashTable: %s\n", search(t, 10) ? "Found" : "Not Found");
	delete(t, 5);
	out(t);
	freeHashTable(t);
	return 0;
}
