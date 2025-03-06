
#include <stdio.h>


int HelpProd(int array[], int k, int n)
{
	if (k == n - 1) return array[k];
	return HelpProd(array, k + 1, n) * array[k];
}

int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(array) / sizeof(array[0]);
	int result = HelpProd(array, 0, n);
	printf("%d\n", result);
	return 0;
}
