#include <stdio.h>

int n = 4;


void PlaceQueen(int matrix[n][n], int row)
{
}

int main(void)
{
	int matrix[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = -1;
		}
	}
	PlaceQueen(matrix);
	return 0;
}
