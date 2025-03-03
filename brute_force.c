/*#include <stdio.h>*/
/**/
/**/
/*#define INT_MIN -2147483648*/
/**/
/*int main(void)*/
/*{*/
/*	int array[] = {1, 2, 3, 4};*/
/*	int size = sizeof(array) / sizeof(array[0]);*/
/*	int maxSum = INT_MIN;*/
/*	for (int i = 0; i < size; i++)*/
/*	{*/
/*		for (int j = i; j < size; j++)*/
/*		{*/
/*			int sum = 0;*/
/*			for (int k = i; k <= j; k++)*/
/*			{*/
/*				sum += array[k];*/
/*			if (sum >= maxSum)*/
/*			{*/
/*				maxSum = sum;*/
/*			}*/
/*			}*/
/**/
/*		}*/
/**/
/*	}*/
/*	printf("MaxSum: %i\n", maxSum);*/
/**/
/*	return 0;*/
/*}*/


#include <stdio.h>
#include <time.h>

/*#define INT_MIN -2147483648*/
/**/
/**/
/*int main(void)*/
/*{*/
/*	int array[] = {-2, 11, -4, 13, -5, 2};*/
/*	int size = sizeof(array) / sizeof(array[0]);*/
/*	int maxSum = INT_MIN;*/
/*	clock_t startT = clock();*/
/*	for (int i = 0; i < size; i++)*/
/*	{*/
/*		int sum = 0;*/
/*		for (int j = i; j < size; j++)*/
/*		{*/
/*			sum += array[j];*/
/*			if (sum > maxSum)*/
/*			{*/
/*				maxSum = sum;*/
/*			}*/
/**/
/*		}		*/
/*	}*/
/*	clock_t endT = clock();*/
/*	printf("Process time brute_force algorithm: %f\n", (double) (endT - startT) / CLOCKS_PER_SEC);	*/
/*	printf("MaxSum: %i\n", maxSum);*/
/*	return 0;*/
/*}*/

#include <stdio.h>
#define INT_MIN -2147483648

int MaxSum(int array[], int n)
{
	int maxSum = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += array[j];
			if (sum > maxSum)
			{
				maxSum = sum;
			}
		}

	}
	return maxSum;
}
int main(void)
{

	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = sizeof(array) / sizeof(array[0]);
	int maxSum = MaxSum(array, n);
	printf("maxSum: %i\n", maxSum);
	return 0;
}
