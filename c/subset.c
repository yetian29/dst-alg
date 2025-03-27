#include <stdio.h>


void SubSet(int array[], int size, int subArray[], int subSize, int startP, int *count)
{
	// Base case
	if (subSize == 3) 
	{
		printf("(");
		for (int i = 0; i < subSize; i++)
		{
			printf("%d", subArray[i]);
			if (i < subSize - 1) printf(", ");	
		}
		printf(")\n");
		(*count)++;
		return;
	}
	// Recursive case
	for (int i = startP; i < size; i++)
	{
		subArray[subSize] = array[i];
		SubSet(array, size, subArray, subSize + 1, i + 1, count);
	}
}

int main(void)
{
	int array[5] = {1, 2, 3, 4, 5};
	int subArray[3];
	int count = 0;
	SubSet(array, 5, subArray, 0, 0, &count);
	printf("Count: %d\n", count);
	return 0;
}
