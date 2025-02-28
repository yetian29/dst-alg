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
/*	printf("MaxSum: %d\n", maxSum);*/
/**/
/*	return 0;*/
/*}*/


#include <stdio.h>
#define INT_MIN -2147483648


int main(void)
{
	int array[] = {-2, 11, -4, 13, -5, 2};
	int size = sizeof(array) / sizeof(array[0]);
	int maxSum = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		int sum = 0;
		for (int j = i; j < size; j++)
		{
			sum += array[j];
			if (sum > maxSum)
			{
				maxSum = sum;
			}

		}		
	}
	printf("MaxSum: %d\n", maxSum);
	return 0;
}
