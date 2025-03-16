#include <stdio.h>
#include <stdbool.h>


bool IsMesureable(int weights[], int index, int size, int value)
{
	// Base case
	if (size == 0) return value == 0;
	// Recursive case
	return IsMesureable(weights, index + 1, size - 1, value - weights[index]) || IsMesureable(weights, index + 1, size - 1, value + weights[index]) || IsMesureable(weights, index + 1, size - 1, value);
}

int main(void)
{
	int weights[] = {1, 3, 7};
	int value = 6, index = 0;
	int size = sizeof(weights) / sizeof(weights[0]);
	printf("%s\n", IsMesureable(weights, index, size, value) ? "True" : "False");
	return 0;
}
