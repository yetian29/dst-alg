#include <stdio.h>
#include <stdlib.h>

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

HashNode *create_new_node(int key, unsigned index)
{
	HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));
	new_node -> key = key;
	new_node -> index = index;
	new_node -> next = NULL;
}

void insert(HashTable *table, int key, unsigned index)
{	  
    unsigned int i = hash(key, table -> size);
		HashNode *current = table -> buckets[i];
	  HashNode *new_node = create_new_node(key, index);
		table -> buckets[i] = new_node;
		new_node -> next = current;
}

HashNode *search(HashTable *table, int key)
{
    unsigned int i  = hash(key, table -> size);
	  HashNode *current = table -> buckets[i];
	  while (current != NULL)
		{
		    if (current -> key == key) return current;
		    current = current -> next;
		}
	  return NULL;

}

void update(HashTable *table, int key, unsigned int index)
{
	HashNode *found = search(table, key);
	if (found == NULL)
	{		
    printf("Value key isn't stored in HashTable\n");
	}
	else
	{
		found -> index = index;
	}


}

void freeHashTable(HashTable *table)
{

	for (int i = 0;  i < table -> size; i++)
	{
		HashNode *current = table -> buckets[i];
		while (current != NULL)
		{
			HashNode *tmp = current;
			current = current -> next;
			free(tmp);
		}
	}
	free(table -> buckets);
	free(table);
}
void out(HashTable *table)
{
	for (int i = 0;  i < table -> size; i++)
	{
		HashNode *current = table -> buckets[i];
		while (current != NULL)
		{
			printf("(%d, %d)", current -> key, current -> index);
			printf(", ");
			current = current -> next;
		}
	}
	printf("\n");
}

int main(void)
{
	int nums[] = {2, 1, 5, 7, 9};
	unsigned int size = sizeof(nums) / sizeof(nums[0]);
	HashTable *table = createHashTable(size);
	for (int i = 0; i < size; i++)
	{
		insert(table, nums[i], i);
	}

	update(table, 5, 10);
	out(table);
	freeHashTable(table);

	return 0;
}
