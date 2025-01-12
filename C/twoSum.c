#include <stdlib.h>
#include <stdio.h>

typedef struct HashNode 
{
	int key;
	unsigned int index;
	struct HashNode *next;
} HashNode;

typedef struct HashTable
{
	HashNode **buckets;
	unsigned int size;
} HashTable;

unsigned int hash(int key, unsigned int size)
{
	return abs(key) % size;
}

HashNode *createNewNode(int key, unsigned int index)
{
	HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));
	new_node -> key = key;
	new_node -> index = index;
	new_node -> next = NULL;
	return new_node;
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
	HashNode *current = table -> buckets[i];
	while (current != NULL)
	{
		if (current -> key == key) return current;
		current = current -> next;
	}
	return NULL;
}


void insert(HashTable *table, int key, unsigned int index)
{
	unsigned int i = hash(key, table -> size);
	HashNode *current = table -> buckets[i];
	HashNode *new_node = createNewNode(key, index);
	table -> buckets[i] = new_node;
	new_node -> next = current;

}

void freeHashTable(HashTable *table)
{
	for (int i = 0; i < table -> size; i++)
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


int *twoSum(int *nums, unsigned int numsSize, int target, unsigned int *returnSize)
{
  *returnSize = 2;
	int *result = (int *)calloc(*returnSize, sizeof(int));
	HashTable *table = createHashTable(numsSize);
	for (int i = 0; i < numsSize; i++)
	{
		int complement = target - nums[i];
		HashNode *found = search(table, complement);
		if (found != NULL)
		{
			result[0] = found -> index;
			result[1] = i;
			freeHashTable(table);
			return result;
		}
		insert(table, nums[i], i);
	}
	returnSize = NULL;
	freeHashTable(table);
	return NULL;
}

int main(void)
{
	int nums[] = {2, 7, 11, 5};
	int target = 9;
	int returnSize;
	unsigned int size = sizeof(nums) / sizeof(nums[0]);
	int *result = twoSum(nums, size, target, &returnSize);
	if (result != NULL)
	{
		printf("[%d, %d]\n", result[0], result[1]);
	}
	else
	{
    printf("There isn't index list that satisfies problem request.");
	}
	free(result);
	return 0;
}
