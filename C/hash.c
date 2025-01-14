/*#include <stdio.h>*/
/*#include <stdlib.h>*/
/**/
/*typedef struct HashNode */
/*{*/
/*	int key;*/
/*	unsigned int index;*/
/*	struct HashNode *next;*/
/*} HashNode;*/
/**/
/*typedef struct */
/*{*/
/*	HashNode **buckets;*/
/*	unsigned int size;*/
/*} HashTable;*/
/**/
/*unsigned int hash(int key, unsigned int size)*/
/*{*/
/*	return abs(key) % size;*/
/*}*/
/**/
/*HashTable *createHashTable(unsigned int size)*/
/*{*/
/*	HashTable *table = (HashTable *)malloc(sizeof(HashTable));*/
/*	HashNode **buckets = (HashNode **)calloc(size, sizeof(HashNode *));*/
/*	table -> buckets = buckets;*/
/*	table -> size = size;*/
/*	return table;*/
/*}*/
/**/
/*HashNode *create_new_node(int key, unsigned index)*/
/*{*/
/*	HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));*/
/*	new_node -> key = key;*/
/*	new_node -> index = index;*/
/*	new_node -> next = NULL;*/
/*}*/
/**/
/*void insert(HashTable *table, int key, unsigned index)*/
/*{	  */
/*    unsigned int i = hash(key, table -> size);*/
/*		HashNode *current = table -> buckets[i];*/
/*	  HashNode *new_node = create_new_node(key, index);*/
/*		table -> buckets[i] = new_node;*/
/*		new_node -> next = current;*/
/*}*/
/**/
/*HashNode *search(HashTable *table, int key)*/
/*{*/
/*    unsigned int i  = hash(key, table -> size);*/
/*	  HashNode *current = table -> buckets[i];*/
/*	  while (current != NULL)*/
/*		{*/
/*		    if (current -> key == key) return current;*/
/*		    current = current -> next;*/
/*		}*/
/*	  return NULL;*/
/**/
/*}*/
/**/
/*void update(HashTable *table, int key, unsigned int index)*/
/*{*/
/*	HashNode *found = search(table, key);*/
/*	if (found == NULL)*/
/*	{		*/
/*    printf("Value key isn't stored in HashTable\n");*/
/*	}*/
/*	else*/
/*	{*/
/*		found -> index = index;*/
/*	}*/
/**/
/**/
/*}*/
/**/
/*void freeHashTable(HashTable *table)*/
/*{*/
/**/
/*	for (int i = 0;  i < table -> size; i++)*/
/*	{*/
/*		HashNode *current = table -> buckets[i];*/
/*		while (current != NULL)*/
/*		{*/
/*			HashNode *tmp = current;*/
/*			current = current -> next;*/
/*			free(tmp);*/
/*		}*/
/*	}*/
/*	free(table -> buckets);*/
/*	free(table);*/
/*}*/
/*void out(HashTable *table)*/
/*{*/
/*	for (int i = 0;  i < table -> size; i++)*/
/*	{*/
/*		HashNode *current = table -> buckets[i];*/
/*		while (current != NULL)*/
/*		{*/
/*			printf("(%d, %d)", current -> key, current -> index);*/
/*			printf(", ");*/
/*			current = current -> next;*/
/*		}*/
/*	}*/
/*	printf("\n");*/
/*}*/
/**/
/*int main(void)*/
/*{*/
/*	int nums[] = {2, 1, 5, 7, 9};*/
/*	unsigned int size = sizeof(nums) / sizeof(nums[0]);*/
/*	HashTable *table = createHashTable(size);*/
/*	for (int i = 0; i < size; i++)*/
/*	{*/
/*		insert(table, nums[i], i);*/
/*	}*/
/**/
/*	update(table, 5, 10);*/
/*	out(table);*/
/*	freeHashTable(table);*/
/**/
/*	return 0;*/
/*}*/

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
	unsigned int count;
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
	table -> count = 0;
	return table;
}

int *LinkListToArray(HashNode *current, unsigned int size)
{
	int *array = (int *)malloc(size * sizeof(int));
	int i = 0;
	while (current != NULL)
	{
		array[i] = current -> key;
		i++;
		current = current -> next;
	}
	return array;


}
void insert(HashTable *table, int key, unsigned int index)
{
	unsigned int i = hash(key, table -> size);
	HashNode *current = table -> buckets[i];
	HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));
	new_node -> key = key;
	new_node -> index = index;
	new_node -> next = NULL;
	if (current == NULL)
	{
		table -> buckets[i] = new_node;
	}
	else
	{
		if (new_node -> key > current -> key)
		{
			current -> next = new_node;

		}
		else
		{
			table -> buckets[i] = new_node;
			new_node -> next = current;

		}
	}
	table -> size++;
	table -> count++;

}

int *searchArray(int *array, int key)
{

	unsigned int length = sizeof(array) / sizeof(array[0]);
	unsigned int middle = length / 2;
	if (length < 2)
	{
		if (key == array[0])
		{
		    return &array;
	  }
		else 
	      return NULL;

	}
	if (key == array[middle])
		return &array[middle];
	else if (key < array[middle]) 
		return searchArray(array[:middle] , key);
	else 
		return searchArray(array[middle+1:], key);
}

void search(HashTable *table, int key)
{
	unsigned int i = hash(key, table -> size);
	HashNode *current = table -> buckets[i];
	int *array = LinkListToArray(current, table -> count);
	int *found = searchArray(array, key);
	if (found != NULL) printf("Found\n");
	else printf("Not Found\n");int found = searchArray(array, key);
	free(array);

}

void out(HashTable *table)
{
	for (int i = 0; i < table -> size; i++)
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

int main(void)
{
	int nums[] = {1, 2, 3, 4, 5, 6, 7};
	unsigned int size = sizeof(nums) / sizeof(nums[0]);
  HashTable *table = createHashTable(size);
	for (int i = 0; i < size; i++)
	{
			insert(table, nums[i], i);
	}
	out(table);
	search(table, 4);
	freeHashTable(table);

	return 0;
}
