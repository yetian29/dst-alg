#include <stdio.h>


int Prod(int array[], int n)
{
	if (n == 1) return array[0];
	return Prod(array, n - 1) * array[n - 1];

}
int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size = sizeof(array) / sizeof(array[0]);
	printf("Prod: %d\n", Prod(array, size));
	return 0;
}
