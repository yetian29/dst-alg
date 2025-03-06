#include <stdio.h>


int Factorial(int n)
{
	if (n == 1) return 1;
	return Factorial(n - 1) * n;
}

int main(void)
{
	int n;
	printf("Enter value: ");
	scanf("%d", &n);
	int result = Factorial(n);
	printf("Result: %d\n", result);
	return 0;

}
