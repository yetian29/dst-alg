#include <stdio.h>


int C(int n, int k, int memoization[][4])
{
	if (k == 0 || k == n) return 1;
	if (memoization[n][k] != - 1) return memoization[n][k];
	return C(n - 1, k, memoization) + C(n - 1, k - 1, memoization);
}

int main(void)
{
	int n = 10, k = 8;

	int memoization[n + 1][k + 1];
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0 ; j < k + 1; j++)
		{
			memoization[i][j] = -1;
		}

	}
	printf("Result: %d\n", C(n, k, memoization));
}
