

#include <stdio.h>
#include <stdbool.h>

bool BinarySearch(int array[], int low, int high, int key)
{
	if (low == high) return array[low] == key;
	int mid = low + (high - low) / 2;
	if (array[mid] == key) return true;
	else if (key < array[mid]) return BinarySearch(array, low, mid - 1, key);
	else return BinarySearch(array, mid + 1, high, key);
}

int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(array) / sizeof(array[0]);
	/*int key = 9;*/
	int key = 0;
	printf("%s\n", BinarySearch(array, 0, n - 1, key) ? "Found" : "Not Found");
	return 0;
}
