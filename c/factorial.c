#include <stdio.h>

int Factorial(int n)
{
	if (n == 1) return 1;
	return n * Factorial(n - 1);
}

int main(void)
{
	int n = 5;
	int result = Factorial(n);
	printf("Result: %d\n", result);
	return 0;
}
