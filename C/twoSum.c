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

unsigned int hash(int key, int size)
{
	return abs(key) % size;
}

HashTable *createHashTable(unsigned int size)
{
	HashTable *table = (HashTable *)malloc(sizeof(HashTable));
	table -> buckets = (HashNode **)calloc(size, sizeof(HashNode *));
	table -> size = size;
	return table;
}

void push(HashTable *table, int key, int index)
{
	unsigned int i = hash(key, table -> size);
	HashNode *tmp = table -> buckets[i];
	HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));
	new_node -> key = key;
	new_node -> index = index;
	new_node -> next = NULL;
	table -> buckets[i] = new_node;
	new_node -> next = tmp;
}
HashNode *find(HashTable *table, int key)
{
	unsigned int i  = hash(key, table -> size);
	HashNode *node_current = table -> buckets[i];
	while (node_current != NULL)
	{
		if (node_current -> key == key) return node_current;
		node_current = node_current -> next;
	}
	return NULL;
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

int *twoSum(int *nums, unsigned int numsSize, int target, int *returnSize)
{
	HashTable *table = (HashTable *)createHashTable(numsSize);
	*returnSize = 2;
	int *result = (int *)calloc(*returnSize, sizeof(int));
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
		push(table, nums[i], i);
	}
	*returnSize = 0;
	free(result);
	freeHashTable(table);
	return NULL;

}

int main(void)
{
	// Return list indices of two number such that they add up to target
	int nums[] = {2, 3, 4, 5, 6, 7};
	int target = 9;
	int returnSize;
	unsigned int size = sizeof(nums) / sizeof(nums[0]);
	int *result = twoSum(nums, size, target, &returnSize);
	if (result == NULL)
	{
		printf("No have value valid");
	}
	else
	{
		printf("List indices of two number such that they add up to target: [%d, %d]\n", result[0], result[1]);
		free(result);
	}

	return 0;

}


