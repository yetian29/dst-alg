#include <stdlib.h>
#include <stdio.h>

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

HashTable *createHashTable()
{
	HashTable *t = malloc(sizeof(HashTable));
	HashNode **buckets = malloc(sizeof(HasNode *));
	t -> buckets = buckets;
	t -> size = 0;
	return t;
}

void insert(HashTable *t, int key, unsigned data)
{
	unsigned int i = hash(key, t -> size)
	Node *current = t -> buckets[i];
}

int main(void)
{
	int nums[] = {1, 2, 3, 4, 5};
	unsigned int size = sizeof(nums) / sizeof(nums[0]);
	HashTable *t = createHashTable();
	for (int i = 0; i < size; i++)
	{
		insert(t, nums[i], i);
	}
	return 0;
}
