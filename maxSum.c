#include <stdio.h>
#include <limits.h>


int BruteForce(int array[], int n)
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

int MaxLeft(int array[], int low, int high)
{
	int maxSum = INT_MIN;
	int sum = 0;
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
	int maxSum = INT_MIN;
	int sum = 0;
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

int Max1(int v1, int v2, int v3)
{
	int maxValue = v1;
	if (v2 > maxValue)
	{
		maxValue = v2;
	}
	if (v3 > maxValue)
	{
		maxValue = v3;
	}
	return maxValue;
}

int DivideAndConquer(int array[], int low, int high)
{
	if (low == high)
	{
		return array[low];
	}
	int mid = low + (high - low) / 2;
	int wl = DivideAndConquer(array, low, mid);
	int wr = DivideAndConquer(array, mid + 1, high);
	int wm = MaxLeft(array, low, mid) + MaxRight(array, mid + 1, high);
	return Max1(wl, wr, wm);

}

int Max2(int v1, int v2)
{
	int maxValue = v1;
	if (v2 > maxValue)
	{
		maxValue = v2;
	}
	return maxValue;
}

int Kadane(int array[], int n)
{
	// declare si is weight max we need to find, ei is weight max contain last element and end at the element

	int ei = array[0];
	int si = array[0];
	for (int i = 1; i < n; i++)
	{
		ei = Max2(array[i], array[i] + ei);
		si = Max2(si, ei);
	}
	return si;

}
int main(void)
{
	int array[] = {1, -2, 3, -4, 5, -6};
	int n = sizeof(array) / sizeof(array[0]);
	/*int maxSum = BruteForce(array, n);*/
	/*int maxSum = DivideAndConquer(array, 0, n - 1);*/
	int maxSum = Kadane(array, n);
	printf("maxSum: %d\n", maxSum);
	return 0;
}
