#include <stdio.h>
#include <time.h>

#define INT_MIN -2147483648

int max(int value1, int value2)
{
	return value1 > value2 ? value1 : value2;

}
int dp(int array[], int size)
{
	int si = array[0];
	int ei = array[0];
	for (int i = 1; i <= size - 1; i++)
	{
		ei = max(array[i], array[i] + ei);
		si = max(si, ei);
	}
	return si;

}

int main(void)
{
	int array[] = {-2, 11, -4, 13, -5, 2};
	int size = sizeof(array) / sizeof(array[0]);
	clock_t startT = clock();
	int maxSum = dp(array, size);
	clock_t endT = clock();
	printf("Process time dynamic programming algorithm: %f\n", (double) (endT - startT) / CLOCKS_PER_SEC);		
	printf("MaxSum: %i\n", maxSum);
	return 0;
}
