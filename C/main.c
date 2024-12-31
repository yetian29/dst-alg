#include <stdlib.h>
#include <stdio.h>

typedef struct HashNode
{
	int key;
	int index;
	struct HashNode *next;
} HashNode;

typedef struct 
{
	HashNode **buckets;
	int size;
} HashTable;

HashTable *createHashTable(int size)
{
  HashTable *table = (HashTable *)malloc(sizeof(*table));
	table -> buckets = (HashNode **)calloc(size, sizeof(HashNode*));
	table -> size = size;
	return table;
}

unsigned int hash(int key, unsigned int size)
{
	unsigned int hash_index = abs(key) % size;
	return hash_index;
}

HashNode *find(HashTable *table, int key)
{
	unsigned int index = hash(key, table -> size);
	HashNode *node_current = table -> buckets[index];
	while (node_current != NULL)
	{
		if(node_current -> key == key) return node_current;
		node_current = node_current -> next;
	}
	return NULL;


}
HashNode *push(HashTable *table, int key, int index)
{
	unsigned int bucket_index = hash(key, table -> size);
	HashNode *new_node = (HashNode *)malloc(sizeof(*new_node));
	new_node -> key = key;
	new_node -> index = index;
	new_node -> next = table -> buckets[bucket_index];
	table -> buckets[bucket_index] = new_node;
	return new_node;

}

void freeHashTable(HashTable *table)
{
	for (int i = 0; i < table -> size; i++)
	{
		HashNode *current_node = table -> buckets[i];
		while (current_node != NULL)
		{
			HashNode *tmp = current_node; 
			current_node = current_node -> next;
			free(tmp);
		}
	}
	free(table -> buckets);
	free(table);
}

int main(void)
{
	int nums[] = {2, 3, 4, 5, 6, 7};
	int size = sizeof(nums) / sizeof(nums[0]);
	HashTable *table = createHashTable(size);
	int target = 7;
	for (int i = 0; i < size; i++)
	{
		HashNode *new_node = push(table, nums[i], i);
		printf("New node with value: %d at index: %d\n", new_node -> key, new_node_index);
	}
	HashNode *found = find(table, target);
	if (found == NULL)
	{
		printf("Not Found");
	}
	else 
	{
		prinf("Found at index: %d\n", found -> index);
	}
	
	freeHashTable(table);
	return 0;
}
