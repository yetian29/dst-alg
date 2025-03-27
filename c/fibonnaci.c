#include <stdio.h>


int Recursive(int n)
{
	if (n < 2) return n;
	return Recursive(n - 1) + Recursive(n - 2);
}


int DP(int n, int memoization[])
{
	if (n < 2) return n;
	if (memoization[n] != -1) return memoization[n];
	memoization[n] = DP(n - 1, memoization) + DP(n - 2, memoization);
	return memoization[n];

}

int main(void)
{
	int n = 5;
	int memoization[n + 1];
	for (int i = 0; i < n + 1; i++) memoization[i] = -1;
	/*printf("Result: %d\n", Recursive(n));*/
	printf("Result: %d\n", DP(n, memoization));
}
