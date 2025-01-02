#include "hash.h"

int main(void)
{

	int nums[] = {1, 2, 3, 4, 5};
	unsigned int size = sizeof(nums) / sizeof(nums[0]);
	HashTable *table = createHashTable(size);

	for (int i = 0; i < size; i++)
	{
		HashNode *node_inserted = insert(table, nums[i], i);
		unsigned bucket_index = hash(nums[i], size);
		printf("Bucket (%d) -> %d\n", bucket_index, node_inserted -> index);
	}
	HashNode *node_deleted = delete(table, 1);
	unsigned bucket_index = hash(nums[0], size);
	printf("Bucket at position %d -> value %d is deleted\n", bucket_index, node_deleted -> index);
	free(node_deleted);
	freeHashTable(table);
	return 0;
}
