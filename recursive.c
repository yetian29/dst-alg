/*#include <stdio.h>*/
/*#include <time.h>*/
/**/
/*#define INT_MIN -2147483648*/
/**/
/*int MaxLeft(int array[], int low, int high)*/
/*{*/
/*	int maxSum = INT_MIN;*/
/*	int sum = 0;*/
/*	for (int j = high; low <= j; j--)*/
/*	{*/
/*		sum += array[j];			*/
/*		if (sum > maxSum)*/
/*		{*/
/*			maxSum = sum;*/
/*		}*/
/*	}*/
/**/
/**/
/*	return maxSum;*/
/*}*/
/**/
/*int MaxRight(int array[], int low, int high)*/
/*{*/
/*	int maxSum = INT_MIN;*/
/*	int sum = 0;*/
/*	for (int j = low; j <= high; j++)*/
/*	{*/
/*		sum += array[j];			*/
/*		if (sum > maxSum)*/
/*		{*/
/*			maxSum = sum;*/
/*		}*/
/*	}*/
/*	return maxSum;*/
/*}*/
/**/
/*int Max(int wl, int wm, int wr)*/
/*{*/
/*  int max = wl;*/
/*	if (wm > max)*/
/*	{*/
/*		max = wm;*/
/*	}*/
/*	if (wr > max)*/
/*	{*/
/*		max = wr;*/
/*	}*/
/*	return max;*/
/*}*/
/**/
/*int MaxSum(int array[], int low, int high)*/
/*{*/
/*	if (low == high) return array[low];*/
/*	int mid = (low + high) / 2;*/
/*	int wl = MaxSum(array, low, mid);*/
/*	int wr = MaxSum(array, mid + 1, high);*/
/*	int wm = MaxLeft(array, low, mid) + MaxRight(array, mid + 1, high);*/
/*	return Max(wl, wm, wr);*/
/*}*/
/**/
/*int main(void)*/
/*{*/
/*	int array[] = {-2, 11, -4, 13, -5, 2};*/
/*	int size = sizeof(array) / sizeof(array[0]);*/
/*	clock_t startT = clock();*/
/*	int maxSum = MaxSum(array, 0, size - 1);*/
/*	clock_t endT = clock();*/
/*	printf("Process time divide and conquer algorithms: %f\n", (double) (endT - startT) / CLOCKS_PER_SEC);*/
/*	printf("MaxSum: %i\n", maxSum);*/
/*	return 0;*/
/*}*/


/*#include <stdio.h>*/
/**/
/*int calculate(int n)*/
/*{*/
/*	if (n == 1) return 1;*/
/*	return n * calculate(n - 1);*/
/*}*/
/**/
/*int main(void)*/
/*{*/
/*	// Computing n!*/
/*	int n;*/
/*	printf("Enter n: ");*/
/*	scanf("%i", &n);*/
/*	int result = calculate(n);*/
/*	printf("Result: %i\n", result);*/
/*	return 0;*/
/*}*/


/*#include <stdio.h>*/
/*#include <stdbool.h>*/
/**/
/*bool BinarySearch(int array[], int low, int high, int key)*/
/*{	*/
/*	if (low == high) return array[low] == key;*/
/*	int mid = low + (high - low) / 2;*/
/*	if (key == array[mid]) return true;	*/
/*	else if (key < array[mid]) return BinarySearch(array, low, mid - 1, key);*/
/*	else return BinarySearch(array, mid + 1, high, key);*/
/*}*/
/**/
/*int main(void)*/
/*{*/
/*	int array[] = {1, 2, 3, 4, 5, 6};*/
/*	int key = 5;*/
/*	int size = sizeof(array) / sizeof(array[0]);*/
/*	bool result = BinarySearch(array, 0, size - 1, key);*/
/*	printf("%s\n", result ? "Found" : "Not Found");*/
/*	return 0;*/
/*}*/
/**/

#include <stdio.h>
#define INT_MIN -2147483648


int MaxLeft(int array[], int low, int high)
{
	int sum = 0;
	int maxSum = INT_MIN;
	for (int i = high; low <= i; i--)
	{
		sum += array[i];
		if (sum > maxSum)
		{
			maxSum = sum;
		}
	}
	return maxSum;
}

int MaxRight(int array[], int low, int high)
{
	int sum = 0;
	int maxSum = INT_MIN;
	for (int i = low; i <= high; i++)
	{
		sum += array[i];
		if (sum > maxSum)
		{
			maxSum = sum;
		}
	}
	return maxSum;
}

int Max(int wl, int wm, int wr)
{
	int max = wl;
	if (wm > max) max = wm;
	if (wr > max) max = wr;
	return max;
}

int MaxSum(int array[], int low, int high)
{
	if (low == high) return array[low];
	int mid = low + (high - low) / 2;
	int wl = MaxSum(array, low, mid);
	int wm = MaxLeft(array, low, mid) + MaxRight(array, mid + 1, high);
	int wr = MaxSum(array, mid + 1, high);
	return Max(wl, wm, wr);
}


int main(void)
{
	int array[] = {1, -2, 4, -10, 3, 5, -100};
	int n = sizeof(array) / sizeof(array[0]);
	int maxSum = MaxSum(array, 0, n - 1);
	printf("maxSum: %d\n", maxSum);
	return 0;
}

