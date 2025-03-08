
/*#include <stdio.h>*/
/**/
/*int Sum(int array[], int low, int high)*/
/*{*/
/*	if (low == high) return array[low];*/
/*	return Sum(array, low, high - 1) + array[high];*/
/*}*/
/**/
/*int main(void)*/
/*{*/
/*	int array[] = {1, 2, 3, 4, 5, 6, 7};*/
/*	int n = sizeof(array) / sizeof(array[0]);*/
/*	int result = Sum(array, 0, n - 1);*/
/*	printf("Result: %d\n", result);*/
/*}*/

#include <stdio.h>

int sum(int array[], int n)
{
	if (n == 1) return array[0];
	return sum(array, n - 1) + array[n - 1];
}

int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(array) / sizeof(array[0]);
	int result = sum(array, n);
	printf("Result: %d\n", result);
	return 0;
}
