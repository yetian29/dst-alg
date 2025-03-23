#include <stdio.h>
#include <stdbool.h>

bool IsMeasureable(int weights[], int size, int startP, int value)
{
	// Base case
	if (size == startP && value != 0)  return false;
	else if (size == startP && value == 0) return true;
	// Recursive case
	return IsMeasureable(weights, size, startP + 1, value + weights[startP]) || IsMeasureable(weights, size, startP + 1, value - weights[startP]) || IsMeasureable(weights, size, startP + 1, value);
}

int main(void)
{
	int weights[] = {1, 3, 7};
	int value = 6;
	int size = sizeof(weights) / sizeof(weights[0]);
	int startP = 0;
	printf("%s\n", IsMeasureable(weights, size, startP, value) ? "True": "False");
}


