#include <stdio.h>

#define INT_MIN -2147483648

int MaxLeft(int array[], int low, int high)
{
	int maxSum = INT_MIN;
	int sum = 0;
	for (int j = high; low <= j; j--)
	{
		sum += array[j];			
		if (sum > maxSum)
		{
			maxSum = sum;
		}
	}

	
	return maxSum;
}

int MaxRight(int array[], int low, int high)
{
	int maxSum = INT_MIN;
	int sum = 0;
	for (int j = low; j <= high; j++)
	{
		sum += array[j];			
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
	if (wm > max)
	{
		max = wm;
	}
	if (wr > max)
	{
		max = wr;
	}
	return max;
}

int MaxSum(int array[], int low, int high)
{
	if (low == high) return array[low];
	int mid = (low + high) / 2;
	int wl = MaxSum(array, low, mid);
	int wr = MaxSum(array, mid + 1, high);
	int wm = MaxLeft(array, low, mid) + MaxRight(array, mid + 1, high);
	return Max(wl, wm, wr);
}

int main(void)
{
	int array[] = {-2, 11, -4, 13, -5, 2};
	int size = sizeof(array) / sizeof(array[0]);
	int maxSum = MaxSum(array, 0, size - 1);
	printf("MaxSum: %d\n", maxSum);
	return 0;
}
