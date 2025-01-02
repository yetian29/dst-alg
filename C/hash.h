#include <stdlib.h>
#include <stdio.h>

typedef struct HashNode
{
	int key;
	unsigned int index;
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
	HashTable *table = (HashTable *)malloc(sizeof(HashTable));
	HashNode **buckets = (HashNode **)calloc(size, sizeof(HashNode *));
	table -> buckets = buckets;
	table -> size = size;
	return table;
}

HashNode *search(HashTable *table, int key)
{
	unsigned int i = hash(key, table -> size);
	HashNode *node_current = table -> buckets[i];
	while (node_current != NULL)
	{
		if (node_current -> key == key) return node_current;
		node_current = node_current -> next;

	}
	return NULL;

}
HashNode *insert(HashTable *table, int key, unsigned int index)
{
	unsigned int i = hash(key, table -> size);
	HashNode *tmp = table -> buckets[i];
	HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));
	new_node -> key = key;
	new_node -> index = index;
	new_node -> next = NULL;
	table -> buckets[i] = new_node;
	new_node -> next = tmp;
	return new_node;
}

HashNode *delete(HashTable *table, int key)
{
	unsigned int i = hash(key, table -> size);
	HashNode *node_current = table -> buckets[i];
	while (node_current != NULL)
	{
		if (node_current -> key == key && node_current == table -> buckets[i])
		{
			HashNode *tmp = node_current;
			table -> buckets[i] = node_current -> next;
			node_current = node_current -> next;
			return tmp;
		}
		else if ((node_current -> next) -> key == key)
		{
			HashNode *tmp = node_current -> next;
			node_current -> next = tmp -> next;
			return tmp;
		}
		return NULL;
	
	}
}

void freeHashTable(HashTable *table)
{
	for (int i = 0; i < table -> size; i++)
	{
		HashNode *node_current = table -> buckets[i];
		while (node_current != NULL)
		{
			HashNode *tmp = node_current;
			node_current = node_current -> next;
			free(tmp);
		}
	}
	free(table -> buckets);
	free(table);
}
