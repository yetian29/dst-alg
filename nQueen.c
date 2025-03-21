
int n = 4;


bool IsSafe(int row, int column)
{
	if (maxtrix[row][column] == 1) return false
	
	return true;

}
voide PlaceQueen(int matrix[n][n], int column)
{
	if (column > 3) return;
	for (int row = 0; row < n; row++)
	{
		if (IsSafe(row, column))
		{
			matrix[row][column] = 1;
		}
	  else PlaceQueen(matrix, column + 1)
	}
}

}


int main(void)
{
	int matrix[n][n]
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) matrix[i][j] = -1;
	}
	PlaceQueen(matrix)
	return 0;
}
