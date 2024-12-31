#include <stdio.h>
#include <stdlib.h>



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

unsigned int hash(const int key, int size)
{
	hash_index = abs(key) % size;
	return hash_index;

}

HashTable *createHashTable(size)
{
	HashTable *table;
	table = malloc(sizeof(*table));
	table -> buckets = (HashNode **)calloc(size, sizeof(HashNode*));
	table -> size = size;
	return table
}

HashNode *find(HashTable *table, int key)
{
	hash_index = hash(key, table -> size);
	HashNode *node_current = table -> buckets[hash_index];
	while(node_current != NULL)
	{
		if (node_current -> key == key) return node_current;
		node_current = node_current -> next;	
	}
	return NULL;

}

void insert(HashTable *table, int key, int index)
{
	hash_index = hash(key, table -> size);
	HasNode *new_node = (HashNode *)malloc(sizeof(*new_node));
	new_node -> key = key;
	new_node -> index = index;
	table -> buckets[hash_index] = new_node;
}

void freeHashTable(HashTable *table)
{
	for (int i = 0; i < table -> size; i++)
	{
		HashNode *node_current = table -> buckets[i];
		while (node_current != NULL)
		{
			HashNode *tmp = node_current;
			free(node_current);
			node_current = tmp -> next;
		
		}

	}
	free(table -> buckets);
	free(table);

}
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	int *result;
	*returnSize = 2;
	result = calloc(*returnSize, sizeof(*result));
	HashTable *table = createHashTable(numsSize);
	for (int i = 0; i < numsSize; i++)
	{
		int complement = target - nums[i];
		HashNode *found = find(table, complement);
		if (found != NULL)
		{
			result[0] = found -> index;
			result[1] = i;
			freeHashTable(table);
			return result;	
		}
		insert(table, nums[i], i);
	}
	freeHashTable(table);
	return result;

}


int main(void)
{
	// return indices of the two numbers such that they add up to target.
	int nums[] = {2, 3, 4, 5, 6, 7};
	int target = 9;
	int size = sizeof(nums) / sizeof(nums[0]);
	int returnSize;
	int *result = twoSum(nums, size, target, &returnSize);


	return 0;
}
