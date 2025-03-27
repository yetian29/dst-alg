#include <stdio.h>

int HandShake(int n)
{
	if (n < 2) return 0;
	return HandShake(n - 1) + n - 1;
}

int main(void)
{
	int n =  5;
	printf("Result: %d\n", HandShake(n));
	return 0;
}
