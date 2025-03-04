#include <stdio.h>
#include <limits.h>

int MaxLeft(int array[], int low, int high)
{
	int maxSum = INT_MIN;
	int sum =  0;
	for (int i = high; i >= low; i--)
	{
		sum += array[i];
		if (sum > maxSum) maxSum = sum;
	}
	return maxSum;
}

int MaxRight(int array[], int low, int high)
{
	int maxSum = INT_MIN;
	int sum =  0;
	for (int i = low; i <= high; i++)
	{
		sum += array[i];
		if (sum > maxSum) maxSum = sum;
	}
	return maxSum;
}

int Max(int v1, int v2, int v3)
{
	int maxValue = v1;
	if (v2 > maxValue) maxValue = v2;
	if (v3 > maxValue) maxValue = v3;
	return maxValue;
}

int MaxSum(int array[], int low, int high)
{
	if (low == high) return array[low];
	int mid = low + (high - low) / 2;
	int wl = MaxSum(array, low, mid);
	int wr = MaxSum(array, mid + 1, high);
	int wm = MaxRight(array, mid + 1, high) + MaxLeft(array, low, mid);
	return Max(wl, wr, wm);

}

int main(void)
{
	int array[] = {1, -2, 3, 4, -5, 6};
	int n = sizeof(array) / sizeof(array[0]);
	int maxSum = MaxSum(array, 0, n - 1);
	printf("maxSum: %d\n", maxSum);
	return 0;
}
