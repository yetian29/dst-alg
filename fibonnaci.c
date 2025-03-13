#include <stdio.h>


int Recursive(int n)
{
	if (n == 1 || n == 2) return 1;
	return Recursive(n - 1) + Recursive(n - 2);
}


int DP(int n, int memoization[])
{
	if (n == 1 || n == 2) return 1;
	if (memoization[n - 1] != -1) return memoization[n - 1];
	memoization[n - 1] = DP(n - 1, memo) + DP(n - 2, memoization);
	return memoization[n - 1];

}

int main(void)
{
	int n = 5;
	int memoization[n];
	for (int i = 0; i < n; i++) memoization[i] = -1;
	/*printf("Result: %d\n", Recursive(n));*/
	printf("Result: %d\n", DP(n, memoization));
}
