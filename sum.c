#include <stdio.h>

int Sum(int array[], int n)
{
	if (n == 1) return array[0];
	return Sum(array, n - 1) + array[n - 1];
}

int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size = sizeof(array) / sizeof(array[0]);
	printf("Sum: %d\n", Sum(array, size));
	return 0;
}
