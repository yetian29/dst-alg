
#include <stdio.h>

int Sum(int n)
{
  if (n == 1) return 0;
	return Sum(n - 1) + n - 1;
}

int main(void)
{
	int n;
	printf("Enter the value: ");
	scanf("%d", &n);
	int result = Sum(n);
	printf("Resutl: %d\n", result);
	return 0;
}
