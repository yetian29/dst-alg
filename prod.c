
#include <stdio.h>


int n;

int HelpProd(int array[], int k)
{
	if (k == n - 1) return array[k];
	return HelpProd(array, k + 1) * array[k];
}

int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7};
	n = sizeof(array) / sizeof(array[0]);
	int result = HelpProd(array, 0);
	printf("%d\n", result);
	return 0;
}
