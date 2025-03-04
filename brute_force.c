#include <stdio.h>
#include <limits.h>


int MaxSum(int array[], int n)
{
	int maxSum = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += array[j];
			if (sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}
	return maxSum;
}

int main(void)
{
	int array[] = {1, -2, 3, 4, -5, 6};
	int n = sizeof(array) / sizeof(array[0]);
	int maxSum = MaxSum(array, n);
	printf("maxSum: %d\n", maxSum);
	return 0;

}
