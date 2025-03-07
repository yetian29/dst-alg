
#include <stdio.h>

int Sum(int array[], int low, int high)
{
	if (low == high) return array[low];
	return Sum(array, low, high - 1) + array[high];
}

int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(array) / sizeof(array[0]);
	int result = Sum(array, 0, n - 1);
	printf("Result: %d\n", result);
}
