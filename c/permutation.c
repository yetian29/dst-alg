#include <stdio.h>




void Permutation(int array[], int size, int subArray[], int subSize, int used[], int *count)
{
	// Base case
	if (subSize == 5)
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
	for (int i = 0; i < size; i++)
	{
		if (used[i] == -1)
		{
			subArray[subSize] = array[i];
			used[i] = 1;
			Permutation(array, size, subArray, subSize + 1, used, count);
			used[i] = -1; // reset used to use for next iteration
		}


	}
	return;
}



int main(void)
{
	int array[5] = {1, 2, 3, 4, 5};
	int subArray[5];
	int count = 0;
	int used[5]; // create array store value is used
	for (int i = 0; i < 5; i++)
	{
		used[i] = -1;
	}
	Permutation(array, 5, subArray, 0, used, &count);
	printf("Count: %d\n", count);

	return 0;
}
