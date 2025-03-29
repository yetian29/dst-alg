#include <stdio.h>


int size = 1000;

int C(int n, int k, int memoization[size][size])
{
	// Base Case
	if (n == k || k == 0)
	{
		return 1;
	}
	
	// Recursive Base
	if (memoization[n][k] != - 1) return memoization[n][k];

	return C(n - 1, k, memoization) + C(n - 1, k - 1, memoization);
}


int main(void)
{
	int n = 5, k = 3;
	int memoization[size][size];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			memoization[i][j] = -1;
		}
	}
	int result = C(n, k, memoization);
	printf("Result: %d\n", result);
	return 0;
}
