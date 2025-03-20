#include <stdio.h>

bool CheckClash()
{

}

void Queen(int matrix[4][4], int column)
{
	// Base case
	if (CheckClash()) return;

	// Recursive case
	for (int row = 0; row < 4; i++)
	{
		matrix[row][column] = 1;
		Queen(matrix, column + 1);
		matrix[row][column] = -1;
	}

}

void out(int matrix[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (matrix[i][j] == 1)
			{
				printf("(%d, %d)\n", i, j);
			}
		}
	}
}

int main(void)
{
	int n = 4;
	int matrix[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; i++)
		{
			 matrix[i][j] = -1;
		}
	}
	Queen(matrix, 0);
	out(matrix);

	return 0;
}
