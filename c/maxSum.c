#include <stdio.h>
#include <limits.h>

int BruteForce(int array[], int n)
{
	int maxSum = INT_MIN;
	for (int i  = 0; i < n; i++)
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

int Max(int value1, int value2, int value3)
{
	int max = value1;
	if (value2 > max) max = value2;
	if (value3 > max) max = value3;
	return max;
}

int DivideAndConquer(int array[], int low, int high)
{
	if (low == high) return array[low];
	int mid = low + (high  - low) / 2;
	int wl = DivideAndConquer(array, low, mid);
	int wm = MaxLeft(array, low, mid) + MaxRight(array, mid + 1, high);
	int wr = DivideAndConquer(array, mid + 1, high);
	return Max(wl, wm, wr);
}

int Max2(int value1, int value2)
{
	int max = value1;
	if (value2 > max) max = value2;
	return max;
}

int DynamicProgramming(int array[], int n)
{
	int si = array[0];
	int ei = array[0];

	for (int i = 1; i < n; i++)
	{
		ei = Max2(array[i], array[i] + ei);
		si = Max2(si, ei);
	}
	return si;

}


int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size = sizeof(array) / sizeof(array[0]);
	/*printf("maxSum: %d\n", BruteForce(array, size));*/
	/*printf("maxSum: %d\n", DivideAndConquer(array, 0, size - 1));*/
	printf("maxSum: %d\n", DynamicProgramming(array, size));

	return 0;
}
